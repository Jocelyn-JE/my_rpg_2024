/*
** EPITECH PROJECT, 2023
** my_rpg: setup_combat.c
** File description:
** combat initialization file
*/

#include "../../../include/rpg.h"

int calculate_damage(int attack, int defense)
{
    int damage = attack - (defense * get_random_nb(0, 100) / 100);

    if (damage < 0)
        return 0;
    //damage = (damage + 5) / 10 * 10;
    return damage;
}

void player_attack(player_t *player, entity_t *enemy)
{
    int damage = calculate_damage(player->stats.attack, enemy->stats.defense);
    enemy->stats.health -= damage;
    //printf("Player attacks! Enemy takes %d damage, enemy health: %d\n", damage, enemy->stats.health);
}

void enemy_attack(player_t *player, entity_t *enemy)
{
    int damage = calculate_damage(enemy->stats.attack, player->stats.defense);
    player->stats.health -= damage;
    //printf("Enemy attacks! Player takes %d damage, player health: %d\n", damage, player->stats.health);
}

int start_combat(player_t *player, entity_t *enemy, app_t *app)
{
    bool turn = false;

    while (player->stats.health > 0 && enemy->stats.health > 0) {
        if (turn == 0) {
            player_attack(player, enemy);
            if (enemy->stats.health <= 0) {
                printf("Enemy defeated!\n");
                return 1;
            }
            turn = 1;
        } else {
            enemy_attack(player, enemy);
            if (player->stats.health <= 0) {
                printf("Player defeated!\n");
                return -1;
            }
            turn = 0;
        }
    }
    return 0;
}

void switch_to_combat(app_t *app)
{
    sfTexture* texture = sfTexture_createFromFile("./assets/textures/atlas.png", NULL);

    sfSprite* sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfIntRect textureRect = {415, 0, 117, 238};
    sfSprite_setTextureRect(sprite, textureRect);
    sfVector2f viewSize = sfView_getSize(app->view);
    sfVector2f spritePosition = {viewSize.x / 2.0f, viewSize.y / 2.0f};
    sfSprite_setPosition(sprite, spritePosition);
    sfSprite_setScale(sprite, (sfVector2f){2, 2});
    sfRenderWindow_clear(app->window, sfBlack);
    sfRenderWindow_drawSprite(app->window, sprite, NULL);
    sfSprite_destroy(sprite);
}
