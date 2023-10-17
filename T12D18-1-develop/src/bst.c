#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

// Создание нового узла дерева
t_btree *bstree_create_node(int item) {
    t_btree *tmp = (t_btree *)malloc(sizeof(t_btree));
    tmp->val = item;
    tmp->left = NULL;
    tmp->left = NULL;
    return tmp;
}

// Функция сравнения двух чисел
int compare(int x, int y) {
    if (x >= y) return 1;
    if (x < y) return -1;
    return 0;
}

// Вставка элемента в бинарное дерево
void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int)) {
    int cmp = cmpf(root->val, item);
    if (cmp == 1) {
        // Вставка в левое поддерево
        if (root->left == NULL) {
            t_btree *tmp = bstree_create_node(item);
            root->left = tmp;
            return;
        } else {
            bstree_insert(root->left, item, cmpf);
        }
    }
    if (cmp == -1) {
        // Вставка в правое поддерево
        if (root->right == NULL) {
            t_btree *tmp = bstree_create_node(item);
            root->right = tmp;
            return;
        } else {
            bstree_insert(root->right, item, cmpf);
        }
    }
}

// Применение функции applyf ко всем элементам дерева в порядке "infix"
void bstree_apply_infix(t_btree *root, void (*applyf)(int)) {
    if (root->left != NULL) bstree_apply_infix(root->left, applyf);
    applyf(root->val);
    if (root->right != NULL) bstree_apply_infix(root->right, applyf);
}

// Применение функции applyf ко всем элементам дерева в порядке "prefix"
void bstree_apply_prefix(t_btree *root, void (*applyf)(int)) {
    applyf(root->val);
    if (root->left != NULL) bstree_apply_prefix(root->left, applyf);
    if (root->right != NULL) bstree_apply_prefix(root->right, applyf);
}

// Применение функции applyf ко всем элементам дерева в порядке "postfix"
void bstree_apply_postfix(t_btree *root, void (*applyf)(int)) {
    if (root->right != NULL) bstree_apply_postfix(root->right, applyf);
    applyf(root->val);
    if (root->left != NULL) bstree_apply_postfix(root->left, applyf);
}

// Очистка памяти, выделенной для дерева
void bstree_clear(t_btree *root) {
    if (root) {
        bstree_clear((root)->left);
        bstree_clear((root)->right);
        free(root);
    }
}

// Функция для печати значения узла
void printNode(int val) { printf("%d ", val); }
