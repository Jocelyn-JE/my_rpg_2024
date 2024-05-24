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

static void manage_case_empty(app_t *app)
{
    attack_entity(app->game_ressources->player,
        find_entity_by_type(app->game_ressources->entities, e_zombie), 0);
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

static void use_food(item_t *item, app_t *app)
{
    int item_count = item->quantity;

    --item_count;
    if (item_count <= 0) {
        free_item(item);
        app->inventory->slots
            [app->game_ressources->selected_item + 27] = NULL;
    } else {
        item->quantity--;
    }
    app->game_ressources->player->stats.health += 3;
    if (app->game_ressources->player->stats.health > 20)
        app->game_ressources->player->stats.health = 20;
    app->game_ressources->combat_state = ENEMY_TURN;
}

static void manage_response(app_t *app, int attack_delta, item_t *item)
{
    if (attack_delta == -1)
        return;
    if (attack_delta == 1001) {
        use_food(item, app);
        return;
    }
    attack_entity(app->game_ressources->player,
        app->game_ressources->player->enemy, attack_delta);
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
    manage_response(app, attack_delta, item);
}

static void handle_events(app_t *app, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        handle_closed(event, app);
    if (event->type == sfEvtResized)
        get_letterbox_view(app->view, sfRenderWindow_getSize(app->window));
    if (event->type == sfEvtMouseWheelScrolled) {
        handle_mouse_movnt(app, *event);
    }
    if (event->type == sfEvtMouseButtonPressed)
        handle_mouse_button_combat(event, app);
}

void manage_combat_events(app_t *app, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(app->window, event) &&
        sfRenderWindow_hasFocus(app->window)) {
        handle_events(app, event);
        update_life(app->game_ressources->player);
        sfRenderWindow_setView(app->window, app->view);
    }
}
