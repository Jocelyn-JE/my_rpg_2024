/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** poll_events
*/
#include "../include/rpg.h"

event_handler_t event_handlers[sfEvtCount];

void initialize_event_handlers(void)
{
    for (int i = 0; i < sfEvtCount; i++)
        event_handlers[i] = NULL;
    event_handlers[sfEvtClosed] = handle_closed;
    event_handlers[sfEvtResized] = handle_resized;
    event_handlers[sfEvtMouseButtonPressed] = handle_mouse_button;
    event_handlers[sfEvtMouseMoved] = handle_mouse_moved;
    event_handlers[sfEvtKeyPressed] = handle_key_pressed;
    event_handlers[sfEvtMouseWheelScrolled] = handle_mouse_wheeling;
}

void poll_events(app_t *app, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(app->window, event)) {
        if (event->type >= 0 && event->type < sfEvtCount &&
            event_handlers[event->type] != NULL) {
            event_handlers[event->type](event, app);
        }
    }
    if (app->game_state == GAME)
        drag_view(event, app->window, app->view);
}
