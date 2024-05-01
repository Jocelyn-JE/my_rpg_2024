/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** poll_events
*/
#include "../include/rpg.h"

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

static void zoom_view(sfEvent *event, app_t *app)
{
    float zoom = 0;

    if (event->type == sfEvtMouseWheelScrolled) {
        zoom = event->mouseWheelScroll.delta > 0.0f ? 0.9f : 1.1f;
        app->zoom *= zoom;
        sfView_zoom(app->view, zoom);
    }
}

void manage_inventory_input(app_t *app, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyE) {
        if (app->game_state == INVENTORY)
            app->game_state = GAME;
        else
            app->game_state = INVENTORY;
    }
}

static void handle_events(app_t *app, sfEvent *event)
{
    if (event->type == sfEvtResized)
        get_letterbox_view(app->view,
            (sfVector2f){event->size.width, event->size.height});
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(app->window);
    manage_inventory_input(app, event);
    if (app->game_state == INVENTORY)
        return;
    if (event->type == sfEvtKeyPressed)
        update_debug_options(&event->key, app->debug_options);
    drag_view(event, app->window, app->view);
    zoom_view(event, app);
}

void poll_events(app_t *app, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(app->window, event) &&
        sfRenderWindow_hasFocus(app->window))
        handle_events(app, event);
}
