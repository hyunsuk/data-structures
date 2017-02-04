#include <string.h>
#include <ctype.h>
#include "common.h"
#include "stack.h"

int EvalPostfix(char postfix[]) {
    Stack stack;
    const int postfix_len = strlen(postfix);

    char character, first_operand, second_operand;

    Init(&stack);

    for (int i = 0; i < postfix_len; i++) {
        character = postfix[i];

        if (isdigit(character)) {
            Push(&stack, character - '0');

        } else {
            second_operand = Pop(&stack);
            first_operand = Pop(&stack);

            switch (character) {
                case PLUS:
                    Push(&stack, first_operand + second_operand);
                    break;
                case MINUS:
                    Push(&stack, first_operand - second_operand);
                    break;
                case MULTIPLY:
                    Push(&stack, first_operand * second_operand);
                    break;
                case DIVIDE:
                    Push(&stack, first_operand / second_operand);
                    break;
            }

        }
    }
    return Pop(&stack);
}
