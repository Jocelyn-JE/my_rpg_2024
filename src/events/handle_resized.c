/*
** EPITECH PROJECT, 2023
** rpg: handle_resized.c
** File description:
** functions for handling window resize
*/

#include "../../include/rpg.h"

void handle_resized(sfEvent *event, app_t *app)
{
    get_letterbox_view(app->view,
        (sfVector2f){event->size.width, event->size.height});
}
