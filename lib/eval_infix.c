#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "stack.h"
#include "to_postfix.h"
#include "eval_postfix.h"

int EvalInfix(char infix[]) {
    const int len = strlen(infix);
    int result;

    char *copy = (char *) malloc(len + 1);
    strcpy(copy, infix);

    ToPostfix(copy);
    result = EvalPostfix(copy);

    free(copy);

    return result;
}
