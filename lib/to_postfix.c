#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "common.h"
#include "stack.h"

int OperatorRank(char operator) {
    switch (operator) {
        case '*':
        case '/':
            return 4;
        case '+':
        case '-':
            return 2;
        case '(':
            return 1;
    }
    return -1;
}

int WhoIsPrecede(char op1, char op2) {
    int op1_rank = OperatorRank(op1);
    int op2_rank = OperatorRank(op2);

    if (op1_rank > op2_rank) {
        return 1;
    } else if (op1_rank < op2_rank) {
        return -1;
    } else {
        return 0;
    }
}

void ToPostfix(char infix[]) {
    Stack stack;
    const int infix_len = strlen(infix);
    const int postfix_len = infix_len + 1;

    int idx = 0;
    char *postfix = (char *) malloc(postfix_len);

    char character, ejected_operator;

    memset(postfix, 0, sizeof(char) * postfix_len);
    Init(&stack);

    for (int i = 0; i < infix_len; i++) {
        character = infix[i];

        if (isdigit(character)) {
            postfix[idx++] = character;

        } else {
            switch (character) {
                case '(':
                    Push(&stack, character);
                    break;
                case ')':
                    while(1) {
                        ejected_operator = Pop(&stack);
                        if (ejected_operator == '(') {
                            break;
                        }
                        postfix[idx++] = ejected_operator;
                    }
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                    while (!IsEmpty(&stack) && 
                           WhoIsPrecede(Peek(&stack), character) >=0 ) {
                        postfix[idx++] = Pop(&stack);
                    }
                    Push(&stack, character);
                    break;
            }

        }
    }

    while (!IsEmpty(&stack)) {
        postfix[idx++] = Pop(&stack);
    }

    strcpy(infix, postfix);
    free(postfix);
}
