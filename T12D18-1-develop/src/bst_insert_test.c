#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void bst_insert_test();

int main() { bst_insert_test(); }

void bst_insert_test() {
    t_btree* tmp1 = bstree_create_node(45);

    printf("1. Node creating\n");
    printf("\t> Expected top value:\t\t45\n");
    printf("\t> Actual top value:\t\t%d\n", tmp1->val);
    printf("\t> Test result:\t\t");
    if (tmp1->val == 45)
        printf("\tSUCCESS\n");
    else
        printf("\tFAIL\n");

    bstree_insert(tmp1, 12, compare);

    printf("2. Node inserting [top-left]\n");
    printf("\t> Expected t->l value:\t\t12\n");
    printf("\t> Actual t->l value:\t\t%d\n", tmp1->left->val);
    printf("\t> Test result:\t\t");
    if (tmp1->left->val == 12)
        printf("\tSUCCESS\n");
    else
        printf("\tFAIL\n");

    bstree_insert(tmp1, 6, compare);
    printf("3. Node inserting [top-left-left]\n");
    printf("\t> Expected t->l->l value:\t6\n");
    printf("\t> Actual t->l->l value:\t\t%d\n", tmp1->left->left->val);
    printf("\t> Test result:\t\t");
    if (tmp1->left->left->val == 6)
        printf("\tSUCCESS\n");
    else
        printf("\tFAIL\n");

    bstree_insert(tmp1, 50, compare);
    printf("4. Node inserting [top-right]\n");
    printf("\t> Expected t->r value:\t\t50\n");
    printf("\t> Actual t->r value:\t\t%d\n", tmp1->right->val);
    printf("\t> Test result:\t\t");
    if (tmp1->right->val == 50)
        printf("\tSUCCESS\n");
    else
        printf("\tFAIL\n");

    bstree_clear(tmp1);
}
