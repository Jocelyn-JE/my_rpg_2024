/*
** EPITECH PROJECT, 2023
** rpg: manage_armor_slots.c
** File description:
** functions for managing armor slots recognition
*/

#include "../../include/rpg.h"

void case_picking_armor(app_t *app, int slot_index, sfEvent *event)
{
    sfVector2i pixel_pos = {event->mouseButton.x, event->mouseButton.y};
    sfVector2f world_pos = sfRenderWindow_mapPixelToCoords(
        app->window, pixel_pos, app->view);

    if (slot_index != -1 && app->inventory->armor[slot_index] != NULL) {
        app->inventory->dragging_slot = slot_index;
        app->inventory->dragged_item = app->inventory->armor[slot_index];
        app->inventory->armor[slot_index] = NULL;
        manage_dragged_item(app, world_pos, 0.f, 1.f);
    }
}

static void manage_same_item(app_t *app, int slot_index)
{
    int diff = app->inventory->armor[slot_index]->limit -
        app->inventory->armor[slot_index]->quantity;

    if (diff >= app->inventory->dragged_item->quantity) {
        app->inventory->armor[slot_index]->quantity +=
            app->inventory->dragged_item->quantity;
        free_item(app->inventory->dragged_item);
        app->inventory->dragged_item = NULL;
        app->inventory->dragging_slot = -1;
    } else {
        app->inventory->dragged_item->quantity -= diff;
        app->inventory->armor[slot_index]->quantity =
            app->inventory->armor[slot_index]->limit;
    }
}

static void execute(app_t *app, int slot_index)
{
    item_t *temp = NULL;

    if (app->inventory->armor[slot_index] == NULL) {
        app->inventory->armor[slot_index] = app->inventory->dragged_item;
        app->inventory->dragged_item = NULL;
        app->inventory->dragging_slot = -1;
    } else {
        if (app->inventory->armor[slot_index]->current_item ==
            app->inventory->dragged_item->current_item) {
            manage_same_item(app, slot_index);
        } else {
            temp = app->inventory->armor[slot_index];
            app->inventory->armor[slot_index] = app->inventory->dragged_item;
            app->inventory->dragged_item = temp;
            app->inventory->dragging_slot = slot_index;
        }
    }
}

void case_dropping_armor(app_t *app, int slot_index)
{
    if (slot_index == -1)
        return;
    if (slot_index == 0 &&
        is_helmet(app->inventory->dragged_item->current_item))
        execute(app, slot_index);
    if (slot_index == 1 &&
        is_chestplate(app->inventory->dragged_item->current_item))
        execute(app, slot_index);
    if (slot_index == 2 &&
        is_leggings(app->inventory->dragged_item->current_item))
        execute(app, slot_index);
    if (slot_index == 3 &&
        is_boots(app->inventory->dragged_item->current_item))
        execute(app, slot_index);
}

void manage_armor_slots(app_t *app, sfEvent *event)
{
    int armor_index =
        get_armor_index(event->mouseButton.x, event->mouseButton.y, app);

    if (armor_index == -1)
        return;
    if (app->inventory->dragged_item == NULL) {
        case_picking_armor(app, armor_index, event);
    } else {
        case_dropping_armor(app, armor_index);
    }
}
