/*
** EPITECH PROJECT, 2023
** rpg: handle_mouse_wheel.c
** File description:
** functions for handling mouse wheel events
*/

#include "../../../../include/rpg.h"

static void zoom_view(sfEvent *event, app_t *app)
{
    float zoom = 0;

    if (!sfKeyboard_isKeyPressed(sfKeyLShift))
        return;
    zoom = event->mouseWheelScroll.delta > 0.0f ? 0.9f : 1.1f;
    if ((app->zoom * zoom) > 500 || (app->zoom * zoom) < 0.2)
        return;
    app->zoom *= zoom;
    sfView_zoom(app->game_view, zoom);
}

void handle_mouse_wheel(app_t *app, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        return;
    if (event.mouseWheelScroll.delta > 0) {
        app->inventory->selected_slot--;
        if (app->inventory->selected_slot < 0) {
            app->inventory->selected_slot = 8;
        }
    } else {
        app->inventory->selected_slot++;
        if (app->inventory->selected_slot > 8) {
            app->inventory->selected_slot = 0;
        }
    }
}

void handle_mouse_wheeling(sfEvent *event, app_t *app)
{
    handle_mouse_wheel(app, *event);
    zoom_view(event, app);
}
