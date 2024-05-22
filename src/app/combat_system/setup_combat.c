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
    sfIntRect textureRect = {415, 0, 117, 238};
    sfVector2f viewSize = sfView_getSize(app->view);
    sfVector2f spritePosition = {viewSize.x / 4.0f, viewSize.y / 1.7f};

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
    sfIntRect textureRect = {415, 0, 117, 238};
    sfVector2f viewSize = sfView_getSize(app->view);
    sfVector2f spritePosition = {viewSize.x * 3.35 / 4.0f, viewSize.y / 3.f};

    sfSprite_setTexture(enemySprite, texture, sfTrue);
    sfSprite_setTextureRect(enemySprite, textureRect);
    sfSprite_setPosition(enemySprite, spritePosition);
    sfSprite_setScale(enemySprite, (sfVector2f){1.2, 1.2});
    return enemySprite;
}

static int set_texture(sfSprite *hotbar_sprite, sfTexture *texture)
{
    sfSprite_setTexture(hotbar_sprite, texture, sfTrue);
    return 0;
}

static sfSprite *setup_hotbar_sprite(app_t *app)
{
    const sfTexture *texture = sfSprite_getTexture(app->inventory->hotbar);
    sfSprite *hotbar_sprite = sfSprite_create();
    int ret = set_texture(hotbar_sprite, (sfTexture *)texture);
    sfVector2f center = sfView_getCenter(app->view);
    sfVector2f size = sfView_getSize(app->view);
    sfFloatRect backgroundBounds = sfSprite_getGlobalBounds(hotbar_sprite);
    float hotbarX = center.x - backgroundBounds.width * 2.46;
    float hotbarY = center.y + (size.y / 2.35) - backgroundBounds.height;

    sfSprite_setPosition(hotbar_sprite, (sfVector2f){hotbarX, hotbarY});
    sfSprite_setScale(hotbar_sprite, (sfVector2f){5, 5});
    return hotbar_sprite;
}

void setup_combat(app_t *app, sfSprite **player_sprite,
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
}

static void setup_bg_sprite(app_t *app, sfSprite **background_sprite)
{
    sfTexture *texture =
        sfTexture_createFromFile("./assets/bg_sprite.png", NULL);
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

void switch_to_combat(app_t *app)
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
    sfRenderWindow_clear(app->window, sfBlack);
    sfRenderWindow_drawSprite(app->window, backgroundSprite, NULL);
    sfRenderWindow_drawSprite(app->window, playerSprite, NULL);
    sfRenderWindow_drawSprite(app->window, enemySprite, NULL);
    sfRenderWindow_drawSprite(app->window, hotbarSprite, NULL);
}
