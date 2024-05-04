/*
** EPITECH PROJECT, 2023
** rpg: handle_mouse_moved.c
** File description:
** functions for handling mouse moved events
*/

#include "../../include/rpg.h"

void handle_mouse_moved(sfEvent *event, app_t *app)
{
    float scale = 0.f;
    float baseScale = 1.0f;
    sfVector2i pixelPos = {event->mouseMove.x, event->mouseMove.y};
    sfVector2f worldPos = sfRenderWindow_mapPixelToCoords(
        app->window, pixelPos, app->view);

    if (app->game_state == INVENTORY) {
        if (app->inventory->dragged_item != NULL)
            sfSprite_setPosition(app->inventory->dragged_item->sprite,
                worldPos);
        if (app->inventory->dragged_item != NULL &&
            app->inventory->dragged_item->limit > 1) {
            baseScale *= app->zoom;
            scale = baseScale;
            sfText_setPosition(app->inventory->dragged_item->quantity_text,
                (sfVector2f){worldPos.x + (43 * scale),
                    worldPos.y + (32 * scale)});
        }
    }
}
