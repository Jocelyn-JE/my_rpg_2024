/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-jocelyn.jean-elie
** File description:
** free_list
*/
#include "rpg.h"

void free_list(list_t *begin, void (*free_func)())
{
    list_t *current_node = begin;
    list_t *cpy;

    for (int i = 0; current_node != NULL; i++) {
        cpy = current_node->next;
        free_func(current_node->data);
        free(current_node);
        current_node = cpy;
    }
}
