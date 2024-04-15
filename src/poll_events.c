/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** poll_events
*/
#include "rpg.h"

static void handle_events(app_t *app, sfEvent *event, sfVector2f old_mouse_pos,
    sfVector2f mouse_pos)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(app->window);
}

void poll_events(app_t *app, sfEvent *event)
{
    static sfVector2f old_mouse_pos = {0, 0};
    static sfVector2f mouse_pos = {0, 0};

    mouse_pos = sfRenderWindow_mapPixelToCoords(app->window,
        sfMouse_getPositionRenderWindow(app->window), NULL);
    while (sfRenderWindow_pollEvent(app->window, event) &&
        sfRenderWindow_hasFocus(app->window))
        handle_events(app, event, old_mouse_pos, mouse_pos);
    old_mouse_pos = mouse_pos;
}
