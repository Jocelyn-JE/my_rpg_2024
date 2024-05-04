/*
** EPITECH PROJECT, 2023
** rpg: handle_mouse_moved.c
** File description:
** functions for handling mouse moved events
*/

#include "../../include/rpg.h"

void manage_dragged_item(app_t *app, sfVector2f world_pos, float scale,
    float base_scale)
{
    if (app->inventory->dragged_item != NULL)
        sfSprite_setPosition(app->inventory->dragged_item->sprite,
        world_pos);
    if (app->inventory->dragged_item != NULL &&
        app->inventory->dragged_item->limit > 1) {
        base_scale *= app->zoom;
        scale = base_scale;
        sfText_setPosition(app->inventory->dragged_item->quantity_text,
        (sfVector2f){world_pos.x + (43 * scale),
        world_pos.y + (32 * scale)});
    }
}

void handle_mouse_moved(sfEvent *event, app_t *app)
{
    float scale = 0.f;
    float base_scale = 1.0f;
    int slot_index = 0;
    sfVector2i pixel_pos = {event->mouseMove.x, event->mouseMove.y};
    sfVector2f world_pos = sfRenderWindow_mapPixelToCoords(
        app->window, pixel_pos, app->view);

    if (app->game_state == INVENTORY) {
        manage_dragged_item(app, world_pos, scale, base_scale);
        slot_index = get_slot_index(event->mouseMove.x,
        event->mouseMove.y, app);
        app->inventory->current_slot = slot_index;
    }
}
