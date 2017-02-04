#include <stdio.h>
#include "lib/to_postfix.h"
#include "lib/eval_postfix.h"

int main(void) {

    char infix1[] = "1 + 2 * 3";
    char infix2[] = "(1 + 2) * 3";
    char infix3[] = "((1-2)+3)*(5-2)";

    ToPostfix(infix1);
    ToPostfix(infix2);
    ToPostfix(infix3);

    printf("%s = %d \n", infix1, EvalPostfix(infix1));
    printf("%s = %d \n", infix2, EvalPostfix(infix2));
    printf("%s = %d \n", infix3, EvalPostfix(infix3));

    return 0;
}
