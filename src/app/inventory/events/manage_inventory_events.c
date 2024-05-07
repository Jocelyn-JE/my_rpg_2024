/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** poll_events
*/
#include "../../../../include/rpg.h"

void manage_invent_events(app_t *app, sfEvent *event)
{
    if (event->type == sfEvtMouseButtonPressed)
        handle_mouse_button(event, app);
    if (event->type == sfEvtMouseMoved)
        handle_mouse_moved(event, app);
    if (event->type == sfEvtKeyPressed)
        handle_key_pressed(event, app);
}
