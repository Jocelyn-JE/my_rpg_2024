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
    static bool moving = false;
    static sfVector2f oldpos;
    static sfVector2f newpos;
    static sfVector2f delta_pos;
    float zoom = 0;
    sfView *view = (sfView *)sfRenderWindow_getDefaultView(app->window);

    if (event->type == sfEvtClosed)
        sfRenderWindow_close(app->window);
    if (event->type == sfEvtMouseButtonPressed) {
        if (event->mouseButton.button == sfMouseLeft) {
            moving = true;
            oldpos = sfRenderWindow_mapPixelToCoords(app->window, (sfVector2i){event->mouseButton.x, event->mouseButton.y}, NULL);
        }
    }
    if (event->type == sfEvtMouseButtonReleased) {
        if (event->mouseButton.button == sfMouseLeft)
            moving = false;
    }
    if (event->type == sfEvtMouseWheelScrolled) {
        zoom = event->mouseWheel.delta > 0.0f ? 0.9f : 1.1f;
        sfView_setSize(view, sfView_getSize(sfRenderWindow_getDefaultView(app->window)));
        sfView_zoom(view, zoom);
        sfRenderWindow_setView(app->window, view);
    }
    if (event->type == sfEvtMouseMoved) {
        if (!moving)
            return;
        newpos = sfRenderWindow_mapPixelToCoords(app->window, (sfVector2i){event->mouseMove.x, event->mouseMove.y}, NULL);
        delta_pos = (sfVector2f){oldpos.x - newpos.x, oldpos.y - newpos.y};
        sfView_setCenter(view, (sfVector2f){sfView_getCenter(view).x + delta_pos.x,
            sfView_getCenter(view).y + delta_pos.y});
        sfRenderWindow_setView(app->window, view);
        oldpos = sfRenderWindow_mapPixelToCoords(app->window, (sfVector2i){event->mouseMove.x, event->mouseMove.y}, NULL);
    }
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
