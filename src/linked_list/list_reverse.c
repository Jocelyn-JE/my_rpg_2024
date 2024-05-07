/*
** EPITECH PROJECT, 2024
** list_reverse
** File description:
** Reverses a list
*/
#include <stdlib.h>
#include "linked_list.h"

void list_reverse(list_t **begin)
{
    list_t *prev = NULL;
    list_t *current = *begin;
    list_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *begin = prev;
}
