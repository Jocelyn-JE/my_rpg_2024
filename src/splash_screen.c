/*
** EPITECH PROJECT, 2024
** project
** File description:
** splash_screen
*/

#include "rpg.h"

void splash_screen(app_t *a)
{
    while (sfRenderWindow_isOpen(a->window)) {
        poll_events(a, &a->e->event);
        sfRenderWindow_clear(a->window, sfWhite);
        sfRenderWindow_display(a->window);
    }
}