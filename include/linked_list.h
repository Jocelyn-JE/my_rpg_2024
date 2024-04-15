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
} linked_list_t;
void add(linked_list_t **start, void *ptr);
void del(linked_list_t **list, void *ptr);
void free_list(linked_list_t *list);
int list_len(linked_list_t *start);
