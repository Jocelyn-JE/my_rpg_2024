/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** poll_events
*/
#include "../../../../include/rpg.h"

static void handle_events(app_t *app, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        handle_closed(event, app);
    if (event->type == sfEvtResized)
        handle_resized(event, app);
    if (event->type == sfEvtKeyPressed)
        handle_key_pressed_game(event, app);
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyE) {
        app->event_handler = manage_invent_events;
        app->game_handler = draw_inventory;
    }
    if (event->type == sfEvtMouseWheelScrolled)
        handle_mouse_wheeling(event, app);
}

void manage_game_events(app_t *app, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(app->window, event))
        handle_events(app, event);
    drag_view(event, app->window, app->view);
    handle_movement(app->game_ressources->player,
        app->game_ressources->entities->data,
        sfClock_getElapsedTime(app->game_clock));
    sfView_setCenter(app->view,
        cartesian_to_isometric(app->game_ressources->player->pos.x + 16,
        app->game_ressources->player->pos.y, 2, 100));
}
