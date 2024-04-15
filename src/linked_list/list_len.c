/*
** EPITECH PROJECT, 2023
** disp
** File description:
** Display an element to a linked list
*/
#include "rpg.h"

int list_len(linked_list_t *start)
{
    linked_list_t *current_node = start;
    int i = 0;

    if (current_node == NULL)
        return (0);
    for (; current_node->next != NULL; i++)
        current_node = current_node->next;
    return (i);
}
