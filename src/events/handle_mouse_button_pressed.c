/*
** EPITECH PROJECT, 2023
** rpg: handle_mouse_button_pressed.c
** File description:
** functions for mouse button pressed
*/

#include "../../include/rpg.h"

void case_picking(app_t *app, int slot_index)
{
    if (app->inventory->slots[slot_index] != NULL) {
        app->inventory->dragging_slot = slot_index;
        app->inventory->dragged_item = app->inventory->slots[slot_index];
        app->inventory->slots[slot_index] = NULL;
    }
}

static void manage_same_item(app_t *app, int slot_index)
{
    int diff = app->inventory->slots[slot_index]->limit -
        app->inventory->slots[slot_index]->quantity;

    if (diff >= app->inventory->dragged_item->quantity) {
        app->inventory->slots[slot_index]->quantity +=
            app->inventory->dragged_item->quantity;
        app->inventory->dragged_item = NULL;
        app->inventory->dragging_slot = -1;
    } else {
        app->inventory->dragged_item->quantity -= diff;
        app->inventory->slots[slot_index]->quantity =
            app->inventory->slots[slot_index]->limit;
    }
}

void case_dropping(app_t *app, int slot_index)
{
    item_t *temp = NULL;

    if (app->inventory->slots[slot_index] == NULL) {
        app->inventory->slots[slot_index] = app->inventory->dragged_item;
        app->inventory->dragged_item = NULL;
        app->inventory->dragging_slot = -1;
    } else {
        if (app->inventory->slots[slot_index]->current_item ==
            app->inventory->dragged_item->current_item) {
            manage_same_item(app, slot_index);
        } else {
            temp = app->inventory->slots[slot_index];
            app->inventory->slots[slot_index] = app->inventory->dragged_item;
            app->inventory->dragged_item = temp;
            app->inventory->dragging_slot = slot_index;
        }
    }
}

void handle_mouse_button_pressed(sfRenderWindow *window,
    sfEvent *event, app_t *app)
{
    int slot_index =
        get_slot_index(event->mouseButton.x, event->mouseButton.y, app);

    if (slot_index == -1) {
        manage_armor_slots(app, event);
        return;
    }
    if (app->inventory->dragged_item == NULL) {
        case_picking(app, slot_index);
    } else {
        case_dropping(app, slot_index);
    }
}

void handle_mouse_button(sfEvent *event, app_t *app)
{
    if (event->mouseButton.button == sfMouseLeft &&
        app->game_state == INVENTORY)
        handle_mouse_button_pressed(app->window, event, app);
}
