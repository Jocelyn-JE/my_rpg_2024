/*
** EPITECH PROJECT, 2023
** rpg: handle_key_pressed.c
** File description:
** functions for handling key pressed
*/

#include "../../../../include/rpg.h"

static void set_dragged_to_null(app_t *app)
{
    bool return_value = false;

    if (app->inventory->dragged_item != NULL) {
        return_value = add_item_to_inventory(app->inventory,
            app->inventory->dragged_item, -1);
        if (return_value == false)
            free(app->inventory->dragged_item);
        app->inventory->dragged_item = NULL;
        app->inventory->dragging_slot = -1;
        app->inventory->current_item_slot = -1;
        app->inventory->current_armor_slot = -1;
    }
}

void manage_inventory_input(app_t *app)
{
    app->event_handler = manage_game_events;
    app->game_handler = draw_game;
    set_dragged_to_null(app);
}

void handle_key_pressed(sfEvent *event, app_t *app)
{
    if (event->key.code == sfKeyE)
        manage_inventory_input(app);
}
