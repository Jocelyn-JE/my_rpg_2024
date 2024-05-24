/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** poll_events
*/
#include "rpg.h"

void switch_to_game(app_t *app)
{
    app->event_handler = manage_game_events;
    app->draw_function = draw_game;
    get_letterbox_view(app->game_view, sfRenderWindow_getSize(app->window));
    app->game_ressources->player->stats.defense =
        get_total_armor_value(app->inventory);
}

static void handle_events(app_t *app, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        handle_closed(event, app);
    if (event->type == sfEvtResized)
        handle_resized(event, app);
    if (event->type == sfEvtKeyPressed)
        handle_key_pressed_game(event, app);
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyE)
        switch_to_inventory(app);
    if (event->type == sfEvtMouseWheelScrolled)
        handle_mouse_wheeling(event, app);
}

static entity_t *get_player_entity(app_t *app)
{
    list_t *entities = app->game_ressources->entities;
    entity_t *player_entity = NULL;

    for (list_t *current = entities; current; current = current->next) {
        if (((entity_t *)current->data)->type == e_player)
            player_entity = current->data;
    }
    return player_entity;
}

void manage_game_events(app_t *app, sfEvent *event)
{
    player_t *player = app->game_ressources->player;
    sfTime dt = sfClock_getElapsedTime(app->game_clock);

    while (sfRenderWindow_pollEvent(app->window, event) &&
        sfRenderWindow_hasFocus(app->window))
        handle_events(app, event);
    if (sfRenderWindow_hasFocus(app->window))
        handle_movement(player, get_player_entity(app), dt,
            app->game_ressources);
    update_blocks(app->game_ressources->block_types, dt);
    sfView_setCenter(app->game_view, cartesian_to_isometric(player->pos.x + 16,
        player->pos.y, 1.5, 100));
    sfRenderWindow_setView(app->window, app->game_view);
}
