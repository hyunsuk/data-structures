#include <stdio.h>
#include "lib/expression_tree.h"

int main(void) {
    char exp[] = "12+7*";

    BTreeNode * exp_tree = NewExpTree(exp);

    ShowPrefixTypeExp(exp_tree);
    printf("\n");

    ShowInfixTypeExp(exp_tree);
    printf("\n");

    ShowPostfixTypeExp(exp_tree);
    printf("\n");

    printf("%d", EvaluateExpTree(exp_tree));

    return 0;
}
