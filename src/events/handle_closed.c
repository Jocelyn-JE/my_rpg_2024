/*
** EPITECH PROJECT, 2023
** rpg: handle_closed.c
** File description:
** functions for handling closed event
*/

#include "../../include/rpg.h"

void handle_closed(sfEvent *event, app_t *app)
{
    sfRenderWindow_close(app->window);
    (void)event;
    (void)app;
}
