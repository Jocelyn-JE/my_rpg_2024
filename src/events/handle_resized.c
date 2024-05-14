/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** handle_resized
*/

#include "rpg.h"

void handle_resized(sfEvent *event, app_t *app)
{
    get_letterbox_view(app->view,
        (sfVector2f){event->size.width, event->size.height});
}
