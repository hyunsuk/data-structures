#include <stdio.h>
#include "lib/eval_infix.h"

int main(void) {

    char infix1[] = "1 + 2 * 3";
    char infix2[] = "(1 + 2) * 3";
    char infix3[] = "((1-2)+3)*(5-2)";

    printf("%s = %d \n", infix1, EvalInfix(infix1));
    printf("%s = %d \n", infix2, EvalInfix(infix2));
    printf("%s = %d \n", infix3, EvalInfix(infix3));

    return 0;
}
