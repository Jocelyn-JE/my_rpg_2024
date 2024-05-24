/*
** EPITECH PROJECT, 2023
** project_name: manage_combat_events.c
** File description:
** file_description
*/

#include "../../../../include/rpg.h"

void attack_entity(player_t *attacker, entity_t *defender, int ext_damage)
{
    int defense_delta = get_random_nb(0, 100);
    int damage = attacker->stats.attack + ext_damage;

    if (defense_delta < defender->stats.defense)
        return;
    defender->stats.health -= damage;
    if (defender->stats.health < 0)
        defender->stats.health = 0;
    return;
}

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

static void manage_case_empty(app_t *app)
{
    wait_for_seconds(1.5);
    attack_entity(app->game_ressources->player,
        find_entity_by_type(app->game_ressources->entities, e_zombie), 0);
    wait_for_seconds(1.5);
    app->game_ressources->combat_state = ENEMY_TURN;
}

static int get_item_attack(int item)
{
    if (item == 0)
        return 1001;
    if (item == 18 || item == 10)
        return 4;
    if (item == 3)
        return 5;
    if (item == 11 || item == 24)
        return 6;
    if (item == 4 || item == 16)
        return 7;
    if (item == 25)
        return 8;
    if (item == 9 || item == 2)
        return 9;
    if (item == 23)
        return 10;
    return -1;
}

static void use_food(item_t *item)
{
    wait_for_seconds(1.5);
}

static void manage_response(app_t *app, int type_item,
    int attack_delta, item_t *item)
{
    if (attack_delta == -1)
        return;
    if (type_item == 0) {
        //use_food(item);
        return;
    }
    attack_entity(app->game_ressources->player,
        find_entity_by_type(app->game_ressources->entities, e_zombie),
        attack_delta);
    app->game_ressources->combat_state = ENEMY_TURN;
}

void handle_mouse_button_combat(sfEvent *event, app_t *app)
{
    item_t *item = NULL;
    int type_item = 0;
    int attack_delta = 0;

    if (app->game_ressources->combat_state != PLAYER_TURN ||
        event->mouseButton.button != sfMouseLeft)
        return;
    item = app->inventory->slots
        [app->game_ressources->selected_item + 27];
    if (item == NULL) {
        manage_case_empty(app);
        return;
    }
    type_item = item->current_item;
    attack_delta = get_item_attack(type_item);
    manage_response(app, type_item, attack_delta, item);
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
    if (event->type == sfEvtMouseButtonPressed)
        handle_mouse_button_combat(event, app);
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
