#include "list.h"

#include <stdlib.h>

struct node* init(const struct door* door) {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->door = *door;
    head->next = NULL;
    return head;
}

struct node* add_door(struct node* elem, const struct door* door) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->door = *door;
    new_node->next = elem->next;
    elem->next = new_node;
    return new_node;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* current = root;
    while (current != NULL) {
        if (current->door.id == door_id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

struct node* remove_door(struct node* elem, struct node* root) {
    if (root == NULL) {
        return NULL;
    }

    if (elem == root) {
        struct node* new_root = root->next;
        free(root);
        return new_root;
    }

    struct node* prev = root;
    struct node* current = root->next;

    while (current != NULL) {
        if (current == elem) {
            prev->next = current->next;
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }

    return root;
}

void destroy(struct node* root) {
    struct node* current = root;
    while (current != NULL) {
        struct node* temp = current;
        current = current->next;
        free(temp);
    }
}