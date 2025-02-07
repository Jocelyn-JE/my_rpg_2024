/*
** EPITECH PROJECT, 2023
** my_rpg: setup_combat.c
** File description:
** combat initialization file
*/

#include "../../../include/rpg.h"

static sfSprite *setup_player_sprite(app_t *app)
{
    sfTexture *texture =
        sfTexture_createFromFile("./assets/textures/atlas.png", NULL);
    sfSprite *playerSprite = sfSprite_create();
    sfIntRect textureRect = {533, 0, 119, 240};
    sfVector2f viewSize = sfView_getSize(app->view);
    sfVector2f spritePosition = {viewSize.x / 3.7f, viewSize.y / 1.9f};

    sfSprite_setTexture(playerSprite, texture, sfTrue);
    sfSprite_setTextureRect(playerSprite, textureRect);
    sfSprite_setPosition(playerSprite, spritePosition);
    sfSprite_setScale(playerSprite, (sfVector2f){1.2, 1.2});
    return playerSprite;
}

static sfSprite *setup_enemy_sprite(app_t *app)
{
    sfTexture *texture =
        sfTexture_createFromFile("./assets/textures/atlas.png", NULL);
    sfSprite *enemySprite = sfSprite_create();
    sfIntRect textureRect = {414, 240, 119, 191};
    sfVector2f viewSize = sfView_getSize(app->view);
    sfVector2f spritePosition = {viewSize.x / 1.55f, viewSize.y / 3.35f};

    sfSprite_setTexture(enemySprite, texture, sfTrue);
    sfSprite_setTextureRect(enemySprite, textureRect);
    sfSprite_setPosition(enemySprite, spritePosition);
    sfSprite_setScale(enemySprite, (sfVector2f){1.2, 1.2});
    return enemySprite;
}

static void setup_combat(app_t *app, sfSprite **player_sprite,
    sfSprite **enemy_sprite, sfSprite **hotbar_sprite)
{
    if (*player_sprite != NULL)
        sfSprite_destroy(*player_sprite);
    *player_sprite = setup_player_sprite(app);
    if (*enemy_sprite != NULL)
        sfSprite_destroy(*enemy_sprite);
    *enemy_sprite = setup_enemy_sprite(app);
    if (*hotbar_sprite != NULL)
        sfSprite_destroy(*hotbar_sprite);
    *hotbar_sprite = setup_hotbar_sprite(app);
    app->game_ressources->selected_item = 0;
    app->game_ressources->combat_state = PLAYER_TURN;
}

static void setup_bg_sprite(app_t *app, sfSprite **background_sprite)
{
    sfTexture *texture =
        sfTexture_createFromFile("./assets/combat_background.png", NULL);
    sfVector2f viewSize = sfView_getSize(app->view);
    sfFloatRect spriteBounds = {0, 0, 0, 0};
    float scaleX = 0.f;
    float scaleY = 0.f;

    if (*background_sprite != NULL)
        sfSprite_destroy(*background_sprite);
    *background_sprite = sfSprite_create();
    sfSprite_setTexture(*background_sprite, texture, sfTrue);
    spriteBounds = sfSprite_getLocalBounds(*background_sprite);
    scaleX = viewSize.x / spriteBounds.width;
    scaleY = viewSize.y / spriteBounds.height;
    sfSprite_setScale(*background_sprite, (sfVector2f){scaleX, scaleY});
    sfSprite_setPosition(*background_sprite, (sfVector2f){0, 0});
}

void play_enemy_turn(app_t *app, player_t *player,
    entity_t *enemy, sfSprite *hotbarSprite)
{
    display_hotbar_unavailable(app, hotbarSprite);
    wait_for_seconds(0.7f);
    sfSound_play(app->sound->sounds[1]);
    attack_player(enemy, player);
    wait_for_seconds(0.7f);
    app->game_ressources->combat_state = PLAYER_TURN;
}

entity_t *find_entity_by_type(list_t *start, uint32_t type)
{
    list_t *current = start;
    entity_t *entity = NULL;

    while (current != NULL) {
        entity = (entity_t *)current->data;
        if (entity->type == type) {
            return entity;
        }
        current = current->next;
    }
    return NULL;
}

int check_combat_end(app_t *app, sfSprite *hotbarSprite)
{
    if (app->game_ressources->player->stats.health <= 0) {
        app->game_ressources->combat_state = PLAYER_LOST;
        display_hotbar_unavailable(app, hotbarSprite);
        sfSound_play(app->sound->sounds[2]);
        wait_for_seconds(0.7f);
        reset_player_stats(app->game_ressources->player);
        switch_to_game(app);
        return 1;
    }
    if (app->game_ressources->player->enemy->stats.health <= 0) {
        app->game_ressources->combat_state = PLAYER_WON;
        display_hotbar_unavailable(app, hotbarSprite);
        wait_for_seconds(0.7f);
        list_del(&app->game_ressources->entities,
            app->game_ressources->player->enemy);
        switch_to_game(app);
        return 1;
    }
    return 0;
}

void draw_game_sprites(app_t *app, sfSprite *playerSprite,
    sfSprite *enemySprite, sfSprite *backgroundSprite)
{
    sfRenderWindow_clear(app->window, sfBlack);
    sfRenderWindow_drawSprite(app->window, backgroundSprite, NULL);
    sfRenderWindow_drawSprite(app->window, playerSprite, NULL);
    sfRenderWindow_drawSprite(app->window, enemySprite, NULL);
    sfRenderWindow_drawSprite(app->window,
        app->game_ressources->player->health_sprite, NULL);
}

static void draw_combat(app_t *app)
{
    static sfSprite *playerSprite = NULL;
    static sfSprite *enemySprite = NULL;
    static sfSprite *hotbarSprite = NULL;
    static sfSprite *backgroundSprite = NULL;
    static bool initialized = false;

    if (!initialized) {
        setup_combat(app, &playerSprite, &enemySprite, &hotbarSprite);
        setup_bg_sprite(app, &backgroundSprite);
        initialized = true;
    }
    draw_game_sprites(app, playerSprite, enemySprite, backgroundSprite);
    draw_hotbar_items_game(app, hotbarSprite);
    if (check_combat_end(app, hotbarSprite) == 1) {
        initialized = false;
        return;
    }
    if (app->game_ressources->combat_state == ENEMY_TURN)
        play_enemy_turn(app, app->game_ressources->player,
        app->game_ressources->player->enemy, hotbarSprite);
}

void switch_to_combat(app_t *app)
{
    app->event_handler = manage_combat_events;
    app->draw_function = draw_combat;
    get_letterbox_view(app->view, sfRenderWindow_getSize(app->window));
    sfRenderWindow_setView(app->window, app->view);
}
