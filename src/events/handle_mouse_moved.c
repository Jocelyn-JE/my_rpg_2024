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
    sfFloatRect rect = {0, 0, 0, 0};

    base_scale *= app->zoom;
    scale = base_scale;
    if (app->inventory->dragged_item != NULL) {
        rect = sfSprite_getGlobalBounds(
        app->inventory->dragged_item->sprite);
        sfSprite_setPosition(app->inventory->dragged_item->sprite,
        (sfVector2f){world_pos.x - (rect.width / 2) * scale,
        world_pos.y - (rect.height / 2) * scale});
    }
    if (app->inventory->dragged_item != NULL &&
        app->inventory->dragged_item->limit > 1) {
        sfText_setPosition(app->inventory->dragged_item->quantity_text,
        (sfVector2f){world_pos.x - (rect.width / 2) * scale + (31 * scale),
        world_pos.y - (rect.height / 2) * scale + (39 * scale)});
    }
}

void handle_mouse_moved(sfEvent *event, app_t *app)
{
    int slot_index = 0;
    sfVector2i pixel_pos = {event->mouseMove.x, event->mouseMove.y};
    sfVector2f world_pos = sfRenderWindow_mapPixelToCoords(
        app->window, pixel_pos, app->view);

    if (app->game_state == INVENTORY) {
        manage_dragged_item(app, world_pos, 0.f, 1.0f);
        slot_index = get_slot_index(event->mouseMove.x,
        event->mouseMove.y, app);
        app->inventory->current_item_slot = slot_index;
        slot_index = get_armor_index(event->mouseMove.x,
        event->mouseMove.y, app);
        app->inventory->current_armor_slot = slot_index;
    }
}
