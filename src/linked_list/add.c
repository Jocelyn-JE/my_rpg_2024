/*
** EPITECH PROJECT, 2023
** add
** File description:
** Add a element to a linked list
*/
#include "rpg.h"

void add(linked_list_t **start, void *ptr)
{
    linked_list_t *new_node = malloc(sizeof(linked_list_t));

    if (!new_node)
        return;
    new_node->next = *start;
    new_node->data = ptr;
    *start = new_node;
}
