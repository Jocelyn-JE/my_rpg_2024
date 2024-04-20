/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** linked_list
*/

#pragma once
#include <stdlib.h>

typedef struct linked_list_s {
    void *data;
    struct linked_list_s *next;
} list_t;
void list_add(list_t **start, void *ptr);
void list_del(list_t **list, void *ptr);
void destroy_list(list_t *list);
void free_list(list_t *list, void (*free_func)());
int list_len(list_t *start);
