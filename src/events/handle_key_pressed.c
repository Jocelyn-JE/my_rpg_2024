/*
** EPITECH PROJECT, 2023
** rpg: handle_key_pressed.c
** File description:
** functions for handling key pressed
*/

#include "../../include/rpg.h"

static void update_debug_options(sfKeyEvent *event, debug_t *options)
{
    if (event->code == sfKeyW && options->wireframe)
        options->wireframe = false;
    else if (event->code == sfKeyW)
        options->wireframe = true;
    if (event->code == sfKeyX && options->bounding_box)
        options->bounding_box = false;
    else if (event->code == sfKeyX)
        options->bounding_box = true;
    if (event->code == sfKeyF3 && options->fps)
        options->fps = false;
    else if (event->code == sfKeyX)
        options->fps = true;
}

void manage_inventory_input(app_t *app, sfEvent *event)
{
    if (app->game_state == INVENTORY)
        app->game_state = GAME;
    else
        app->game_state = INVENTORY;
}

void handle_key_pressed(sfEvent *event, app_t *app)
{
    if (event->key.code == sfKeyE)
        manage_inventory_input(app, event);
    update_debug_options(&event->key, app->debug_options);
}
