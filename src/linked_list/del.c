/*
** EPITECH PROJECT, 2023
** del
** File description:
** Delete a element to a linked list
*/
#include "rpg.h"
#include <stdbool.h>

static void delete_from_list(linked_list_t *del, linked_list_t *prev)
{
    free(del->data);
    if (prev != NULL) {
        prev->next = del->next;
    }
    free(del);
}

static bool delete_head(linked_list_t **list, void *ptr)
{
    linked_list_t *cpy = NULL;

    if (*list != NULL && ptr == (*list)->data) {
        free((*list)->data);
        cpy = (*list)->next;
        free(*list);
        *list = cpy;
        return (true);
    }
    return (false);
}

void del(linked_list_t **list, void *ptr)
{
    linked_list_t *previous_node = NULL;
    linked_list_t *current_node = *list;

    if (delete_head(list, ptr)) {
        return;
    }
    for (int i = 0; current_node != NULL; i++) {
        if (ptr == current_node->data) {
            delete_from_list(current_node, previous_node);
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
}
