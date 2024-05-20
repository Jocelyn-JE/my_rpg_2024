/*
** EPITECH PROJECT, 2023
** rpg: handle_mouse_button_pressed.c
** File description:
** functions for mouse button pressed
*/

#include "../../../../include/rpg.h"

void case_picking(app_t *app, int slot_index, sfVector2f world_pos)
{
    if (app->inventory->slots[slot_index] != NULL) {
        app->inventory->dragging_slot = slot_index;
        app->inventory->dragged_item = app->inventory->slots[slot_index];
        app->inventory->slots[slot_index] = NULL;
        manage_dragged_item(app, world_pos, 0.f, 1.f);
    }
}

static void manage_same_item(app_t *app, int slot_index, sfVector2f world_pos)
{
    int diff = app->inventory->slots[slot_index]->limit -
        app->inventory->slots[slot_index]->quantity;

    if (diff >= app->inventory->dragged_item->quantity) {
        app->inventory->slots[slot_index]->quantity +=
            app->inventory->dragged_item->quantity;
        free_item(app->inventory->dragged_item);
        app->inventory->dragged_item = NULL;
        app->inventory->dragging_slot = -1;
    } else {
        app->inventory->dragged_item->quantity -= diff;
        app->inventory->slots[slot_index]->quantity =
            app->inventory->slots[slot_index]->limit;
        manage_dragged_item(app, world_pos, 0.f, 1.f);
    }
}

void case_dropping(app_t *app, int slot_index, sfVector2f world_pos)
{
    item_t *temp = NULL;

    if (app->inventory->slots[slot_index] == NULL) {
        app->inventory->slots[slot_index] = app->inventory->dragged_item;
        app->inventory->dragged_item = NULL;
        app->inventory->dragging_slot = -1;
    } else {
        if (app->inventory->slots[slot_index]->current_item ==
            app->inventory->dragged_item->current_item) {
            manage_same_item(app, slot_index, world_pos);
        } else {
            temp = app->inventory->slots[slot_index];
            app->inventory->slots[slot_index] = app->inventory->dragged_item;
            app->inventory->dragged_item = temp;
            app->inventory->dragging_slot = slot_index;
            manage_dragged_item(app, world_pos, 0.f, 1.f);
        }
    }
}

static void manage_trash_can(app_t *app)
{
    if (app->inventory->dragged_item != NULL) {
        free_item(app->inventory->dragged_item);
        app->inventory->dragged_item = NULL;
        app->inventory->dragging_slot = -1;
    }
}

void handle_mouse_button_pressed(sfEvent *event, app_t *app)
{
    int slot_index =
        get_slot_index(event->mouseButton.x, event->mouseButton.y, app);
    sfVector2i pixel_pos = {event->mouseButton.x, event->mouseButton.y};
    sfVector2f world_pos = sfRenderWindow_mapPixelToCoords(
        app->window, pixel_pos, app->game_view);

    if (slot_index == -1) {
        manage_armor_slots(app, event);
        return;
    }
    if (slot_index == 1000) {
        manage_trash_can(app);
        return;
    }
    if (app->inventory->dragged_item == NULL) {
        case_picking(app, slot_index, world_pos);
    } else {
        case_dropping(app, slot_index, world_pos);
    }
}

void handle_mouse_button(sfEvent *event, app_t *app)
{
    if (event->mouseButton.button == sfMouseLeft)
        handle_mouse_button_pressed(event, app);
    if (event->mouseButton.button == sfMouseRight)
        handle_mouse_button_right(app, event);
}
