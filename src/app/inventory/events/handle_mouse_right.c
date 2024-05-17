/*
** EPITECH PROJECT, 2023
** rpg: handle_mouse_button_right.c
** File description:
** functions for mouse right button
*/

#include "../../../../include/rpg.h"

void case_picking_half(app_t *app, int slot_index, sfVector2f world_pos)
{
    int half_quantity = 0;
    item_t *temp = NULL;

    if (app->inventory->slots[slot_index] != NULL &&
        app->inventory->slots[slot_index]->quantity > 1) {
        half_quantity = app->inventory->slots[slot_index]->quantity / 2;
        temp = copy_item(app->inventory->slots[slot_index]);
        temp->quantity = half_quantity;
        app->inventory->slots[slot_index]->quantity -= half_quantity;
        app->inventory->dragged_item = temp;
        app->inventory->dragging_slot = slot_index;
        manage_dragged_item(app, world_pos, 0.f, 1.f);
    } else {
        case_picking(app, slot_index, world_pos);
    }
}

static void set_item(app_t *app, int slot_index, sfVector2f world_pos)
{
    item_t *new_item = copy_item(app->inventory->dragged_item);

    if (new_item != NULL) {
        new_item->quantity = 1;
        app->inventory->slots[slot_index] = new_item;
    }
    app->inventory->dragged_item->quantity -= 1;
    if (app->inventory->dragged_item->quantity <= 0) {
        free_item(app->inventory->dragged_item);
        app->inventory->dragged_item = NULL;
        app->inventory->dragging_slot = -1;
    }
    manage_dragged_item(app, world_pos, 0.f, 1.f);
}

static void add_one_to_slot(app_t *app, int slot_index, sfVector2f world_pos)
{
    item_t *target_slot = app->inventory->slots[slot_index];

    target_slot->quantity += 1;
    app->inventory->dragged_item->quantity -= 1;
    if (app->inventory->dragged_item->quantity <= 0) {
        free_item(app->inventory->dragged_item);
        app->inventory->dragged_item = NULL;
        app->inventory->dragging_slot = -1;
    }
    manage_dragged_item(app, world_pos, 0.f, 1.f);
}

void case_dropping_one(app_t *app, int slot_index, sfVector2f world_pos)
{
    item_t *target_slot = app->inventory->slots[slot_index];

    if (target_slot == NULL) {
        set_item(app, slot_index, world_pos);
        return;
    }
    if (target_slot->current_item == app->inventory->dragged_item->current_item
        && target_slot->quantity < target_slot->limit) {
        add_one_to_slot(app, slot_index, world_pos);
        return;
    }
    if (target_slot->current_item != app->inventory->dragged_item->current_item
        || target_slot->quantity >= target_slot->limit) {
        app->inventory->slots[slot_index] = app->inventory->dragged_item;
        app->inventory->dragged_item = target_slot;
        app->inventory->dragging_slot = slot_index;
        manage_dragged_item(app, world_pos, 0.f, 1.f);
    }
}

static void manage_trash_can(app_t *app)
{
    if (app->inventory->dragged_item != NULL) {
        if (app->inventory->dragged_item->quantity > 1) {
            app->inventory->dragged_item->quantity -= 1;
        } else {
            free_item(app->inventory->dragged_item);
            app->inventory->dragged_item = NULL;
            app->inventory->dragging_slot = -1;
        }
    }
}

void handle_mouse_button_right(app_t *app, sfEvent *event)
{
    int slot_index =
        get_slot_index(event->mouseButton.x, event->mouseButton.y, app);
    sfVector2i pixel_pos = {event->mouseButton.x, event->mouseButton.y};
    sfVector2f world_pos = sfRenderWindow_mapPixelToCoords(
        app->window, pixel_pos, app->view);

    if (slot_index == -1)
        return;
    if (slot_index == 1000) {
        manage_trash_can(app);
        return;
    }
    if (app->inventory->dragged_item == NULL) {
        case_picking_half(app, slot_index, world_pos);
    } else {
        case_dropping_one(app, slot_index, world_pos);
    }
}
