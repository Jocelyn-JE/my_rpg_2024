/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-jocelyn.jean-elie
** File description:
** free_list
*/
#include "rpg.h"

void free_list(linked_list_t *list)
{
    linked_list_t *current_node = list;
    linked_list_t *cpy;

    for (int i = 0; current_node != NULL; i++) {
        cpy = current_node->next;
        free(current_node->data);
        free(current_node);
        current_node = cpy;
    }
}
