#include <stdio.h>

#include "bst.h"

void bst_traverse_test();

int main() { bst_traverse_test(); }

void bst_traverse_test() {
    t_btree* tmp1 = bstree_create_node(45);
    bstree_insert(tmp1, 12, compare);
    bstree_insert(tmp1, 6, compare);
    bstree_insert(tmp1, 50, compare);

    printf("1. Infix traverse [ltr]\n");
    printf("\t> Expected output:\t\t6 12 45 50\n");
    printf("\t> Actual output:\t\t");
    bstree_apply_infix(tmp1, printNode);
    printf("\n");

    printf("2. Prefix traverse [tlr]\n");
    printf("\t> Expected output:\t\t45 12 6 50\n");
    printf("\t> Actual output:\t\t");
    bstree_apply_prefix(tmp1, printNode);
    printf("\n");

    printf("3. Postfix traverse [rtl]\n");
    printf("\t> Expected output:\t\t50 45 12 6\n");
    printf("\t> Actual output:\t\t");
    bstree_apply_postfix(tmp1, printNode);
    printf("\n");

    bstree_clear(tmp1);
}
