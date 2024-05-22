/*
** EPITECH PROJECT, 2023
** rpg: handle_key_pressed.c
** File description:
** functions for handling key pressed
*/

#include "../../../../include/rpg.h"

static void update_debug_options(sfKeyEvent *event, debug_t *options)
{
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
    if (event->key.code == sfKeyEscape)
        switch_to_menu(app);
    if (event->key.code == sfKeyE) {
        app->event_handler = manage_invent_events;
        app->draw_function = draw_inventory;
    }
    if (event->key.code == sfKeyF) {
        app->event_handler = manage_combat_events;
        app->draw_function = switch_to_combat;
        get_letterbox_view(app->view, sfRenderWindow_getSize(app->window));
        sfRenderWindow_setView(app->window, app->view);
    }
}
