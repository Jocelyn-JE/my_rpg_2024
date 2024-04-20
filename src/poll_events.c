/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** poll_events
*/
#include "rpg.h"

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
}

static void zoom_view(sfEvent *event, sfRenderWindow *window, sfView *view)
{
    float zoom = 0;

    if (event->type == sfEvtMouseWheelScrolled) {
        zoom = event->mouseWheelScroll.delta > 0.0f ? 0.9f : 1.1f;
        sfView_setSize(view, sfView_getSize(sfRenderWindow_getDefaultView(window)));
        sfView_zoom(view, zoom);
        sfRenderWindow_setView(window, view);
    }
}

static void drag_view(sfEvent *event, sfRenderWindow *window, sfView *view)
{
    static bool moving = false;
    static sfVector2f oldpos;
    static sfVector2f newpos;
    static sfVector2f delta_pos;

    if (event->type == sfEvtMouseButtonPressed) {
        if (event->mouseButton.button == sfMouseLeft) {
            moving = true;
            oldpos = sfRenderWindow_mapPixelToCoords(window, (sfVector2i){event->mouseButton.x, event->mouseButton.y}, NULL);
        }
    }
    if (event->type == sfEvtMouseButtonReleased) {
        if (event->mouseButton.button == sfMouseLeft)
            moving = false;
    }
    if (event->type == sfEvtMouseMoved) {
        if (!moving)
            return;
        newpos = sfRenderWindow_mapPixelToCoords(window, (sfVector2i){event->mouseMove.x, event->mouseMove.y}, NULL);
        delta_pos = (sfVector2f){oldpos.x - newpos.x, oldpos.y - newpos.y};
        sfView_setCenter(view, (sfVector2f){sfView_getCenter(view).x + delta_pos.x,
            sfView_getCenter(view).y + delta_pos.y});
        sfRenderWindow_setView(window, view);
        oldpos = sfRenderWindow_mapPixelToCoords(window, (sfVector2i){event->mouseMove.x, event->mouseMove.y}, NULL);
    }
}

static void handle_events(app_t *app, sfEvent *event)
{
    sfView *view = (sfView *)sfRenderWindow_getDefaultView(app->window);

    if (event->type == sfEvtClosed)
        sfRenderWindow_close(app->window);
    if (event->type == sfEvtKeyPressed)
        update_debug_options(&event->key, app->debug_options);
    drag_view(event, app->window, view);
    zoom_view(event, app->window, view);
}

void poll_events(app_t *app, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(app->window, event) &&
        sfRenderWindow_hasFocus(app->window))
        handle_events(app, event);
}
