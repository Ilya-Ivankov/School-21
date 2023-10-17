#include "list.h"

#include <stdio.h>

#define SUCCESS 0
#define FAIL 1

int test_add_door() {
    struct door door1 = {1, 1};
    struct door door2 = {2, 0};
    struct door door3 = {3, 1};

    struct node* root = init(&door1);
    struct node* elem = add_door(root, &door2);

    if (elem == NULL) {
        return FAIL;
    }

    if (elem->door.id != door2.id || elem->door.status != door2.status) {
        return FAIL;
    }

    elem = add_door(elem, &door3);

    if (elem == NULL) {
        return FAIL;
    }

    if (elem->door.id != door3.id || elem->door.status != door3.status) {
        return FAIL;
    }

    destroy(root);

    return SUCCESS;
}

int test_remove_door() {
    struct door door1 = {1, 1};
    struct door door2 = {2, 0};
    struct door door3 = {3, 1};

    struct node* root = init(&door1);
    struct node* elem1 = add_door(root, &door2);
    struct node* elem2 = add_door(elem1, &door3);

    root = remove_door(elem1, root);

    if (root == NULL) {
        return FAIL;
    }

    if (root->door.id != door1.id || root->door.status != door1.status) {
        return FAIL;
    }

    if (root->next != elem2) {
        return FAIL;
    }

    destroy(root);

    if (find_door(3, root) == NULL) {
        printf("123");
    }

    return SUCCESS;
}

int main() {
    int add_door_result = test_add_door();
    if (add_door_result == SUCCESS) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    int remove_door_result = test_remove_door();
    if (remove_door_result == SUCCESS) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }

    return 0;
}