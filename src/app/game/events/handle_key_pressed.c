/*
** EPITECH PROJECT, 2023
** rpg: handle_key_pressed.c
** File description:
** functions for handling key pressed
*/

#include "../../../../include/rpg.h"

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

void handle_key_pressed_game(sfEvent *event, app_t *app)
{
    update_debug_options(&event->key, app->debug_options);
}
