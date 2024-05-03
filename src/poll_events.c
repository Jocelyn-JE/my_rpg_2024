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
    if (event->code == sfKeyF3 && options->fps)
        options->fps = false;
    else if (event->code == sfKeyX)
        options->fps = true;
}

static void zoom_view(sfEvent *event, sfRenderWindow *window, sfView *view)
{
    float zoom = 0;

    if (event->type == sfEvtMouseWheelScrolled) {
        zoom = event->mouseWheelScroll.delta > 0.0f ? 0.9f : 1.1f;
        sfView_zoom(view, zoom);
    }
}

static void handle_events(app_t *app, sfEvent *event)
{
    sfMouseButtonEvent mouse_event = event->mouseButton;

    if (event->type == sfEvtClosed)
        sfRenderWindow_close(app->window);
    if (event->type == sfEvtKeyPressed)
        update_debug_options(&event->key, app->debug_options);
    if (event->type == sfEvtResized)
        get_letterbox_view(app->view, (sfVector2f){event->size.width,
            event->size.height});
    if (event->type == sfEvtMouseButtonPressed) {
        if (mouse_event.button == sfMouseLeft) {
            handle_button_click(app, &mouse_event);
        }
    }
    drag_view(event, app->window, app->view);
    zoom_view(event, app->window, app->view);
}

void poll_events(app_t *app, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(app->window, event) &&
        sfRenderWindow_hasFocus(app->window))
        handle_events(app, event);
}
