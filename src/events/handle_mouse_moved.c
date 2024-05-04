/*
** EPITECH PROJECT, 2023
** rpg: handle_mouse_moved.c
** File description:
** functions for handling mouse moved events
*/

#include "../../include/rpg.h"

void handle_mouse_moved(sfEvent *event, app_t *app)
{
    sfVector2i pixelPos = {event->mouseMove.x, event->mouseMove.y};
    sfVector2f worldPos = sfRenderWindow_mapPixelToCoords(
        app->window, pixelPos, app->view);

    if (app->game_state == INVENTORY) {
        if (app->inventory->dragged_item != NULL) {
            sfSprite_setPosition(app->inventory->dragged_item->sprite,
                worldPos);
        }
    }
}
