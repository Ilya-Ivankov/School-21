#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void bst_create_test();

int main() { bst_create_test(); }

void bst_create_test() {
    t_btree* tmp1 = bstree_create_node(45);

    printf("1. Node creating [45]\n");
    printf("\t> Expected top value:\t\t45\n");
    printf("\t> Actual top value:\t\t%d\n", tmp1->val);
    printf("\t> Test result:\t\t");
    if (tmp1->val == 45)
        printf("\tSUCCESS\n");
    else
        printf("\tFAIL\n");

    free(tmp1);

    t_btree* tmp2 = bstree_create_node(0);

    printf("2. Node creating [0]\n");
    printf("\t> Expected top value:\t\t0\n");
    printf("\t> Actual top value:\t\t%d\n", tmp2->val);
    printf("\t> Test result:\t\t");
    if (tmp2->val == 0)
        printf("\tSUCCESS\n");
    else
        printf("\tFAIL\n");

    free(tmp2);

    t_btree* tmp3 = bstree_create_node(-123);

    printf("3. Node creating [-123]\n");
    printf("\t> Expected top value:\t\t-123\n");
    printf("\t> Actual top value:\t\t%d\n", tmp2->val);
    printf("\t> Test result:\t\t");
    if (tmp3->val == -123)
        printf("\tSUCCESS\n");
    else
        printf("\tFAIL\n");

    free(tmp3);
}
