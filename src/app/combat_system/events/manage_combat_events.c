/*
** EPITECH PROJECT, 2023
** project_name: manage_combat_events.c
** File description:
** file_description
*/

#include "../../../../include/rpg.h"

void handle_mouse_movnt(app_t *app, sfEvent event)
{
    if (app->game_ressources->combat_state != PLAYER_TURN)
        return;
    if (event.mouseWheelScroll.delta > 0) {
        app->game_ressources->selected_item--;
        if (app->game_ressources->selected_item < 0)
            app->game_ressources->selected_item = 8;
    } else {
        app->game_ressources->selected_item++;
        if (app->game_ressources->selected_item > 8)
            app->game_ressources->selected_item = 0;
    }
}

static void handle_events(app_t *app, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        handle_closed(event, app);
    if (event->type == sfEvtResized)
        get_letterbox_view(app->view, sfRenderWindow_getSize(app->window));
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyF) {
        app->event_handler = manage_game_events;
        app->draw_function = draw_game;
        get_letterbox_view(app->game_view,
            sfRenderWindow_getSize(app->window));
        sfRenderWindow_setView(app->window, app->game_view);
    }
    if (event->type == sfEvtMouseWheelScrolled) {
        handle_mouse_movnt(app, *event);
    }
}

void manage_combat_events(app_t *app, sfEvent *event)
{
    player_t *player = app->game_ressources->player;

    while (sfRenderWindow_pollEvent(app->window, event) &&
           sfRenderWindow_hasFocus(app->window)) {
        handle_events(app, event);
        sfRenderWindow_setView(app->window, app->view);
    }
}
