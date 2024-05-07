/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** destroy
*/
#include "linked_list.h"

void list_destroy(list_t *begin)
{
    if (begin == NULL)
        return;
    list_destroy(begin->next);
    free(begin);
}
