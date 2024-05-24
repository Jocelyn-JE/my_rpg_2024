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
        switch_to_pause_menu(app);
<<<<<<< HEAD
=======
    if (event->key.code == sfKeyE) {
        switch_to_inventory(app);
    }
    if (event->key.code == sfKeyF) {
        app->event_handler = manage_combat_events;
        app->draw_function = switch_to_combat;
        get_letterbox_view(app->view, sfRenderWindow_getSize(app->window));
        sfRenderWindow_setView(app->window, app->view);
    }
>>>>>>> b11962b9f4f3f8fe24c44896482ecbb91c5082e4
}
