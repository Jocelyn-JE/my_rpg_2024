/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** poll_events_menu
*/

#include "rpg.h"

static void handle_events_menu(app_t *app, sfEvent *event)
{
    sfMouseButtonEvent mouse_event = event->mouseButton;

    if (event->type == sfEvtMouseButtonPressed) {
        if (mouse_event.button == sfMouseLeft) {
            handle_button_click(app, &mouse_event);
        }
    }
}

void manage_events_menu(app_t *app, sfEvent *events)
{
    while (sfRenderWindow_pollEvent(app->window, events) &&
        sfRenderWindow_hasFocus(app->window)) {
        handle_events_menu(app, events);
        if (events->type == sfEvtResized)
            handle_resized(events, app);
        if (events->type == sfEvtClosed)
            sfRenderWindow_close(app->window);
    }
}
