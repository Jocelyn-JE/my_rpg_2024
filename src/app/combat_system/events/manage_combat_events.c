/*
** EPITECH PROJECT, 2023
** project_name: manage_combat_events.c
** File description:
** file_description
*/

#include "../../../../include/rpg.h"

static void handle_events(app_t *app, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        handle_closed(event, app);
    if (event->type == sfEvtResized)
        handle_resized(event, app);
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyF) {
        app->event_handler = manage_game_events;
        app->draw_function = draw_game;
    }
}

void manage_combat_events(app_t *app, sfEvent *event)
{
    player_t *player = app->game_ressources->player;

    while (sfRenderWindow_pollEvent(app->window, event) &&
        sfRenderWindow_hasFocus(app->window))
        handle_events(app, event);
    if (sfRenderWindow_hasFocus(app->window))
      sfRenderWindow_setView(app->window, app->view);
}
