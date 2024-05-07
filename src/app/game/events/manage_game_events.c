/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** poll_events
*/
#include "../../../../include/rpg.h"

void manage_game_events(app_t *app, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed)
        handle_key_pressed_game(event, app);
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyE) {
        app->event_handler = manage_invent_events;
        app->game_handler = draw_inventory;
    }
    if (event->type == sfEvtMouseWheelScrolled)
        handle_mouse_wheeling(event, app);
    drag_view(event, app->window, app->view);
}
