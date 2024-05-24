/*
** EPITECH PROJECT, 2023
** my_rpg: setup_combat.c
** File description:
** combat initialization file
*/

#include "rpg.h"

static void create_life_sprite(player_t *player, const char *filename)
{
    player->health_sprite = sfSprite_create();
    player->health_texture = sfTexture_createFromFile(filename, NULL);
    sfSprite_setTexture(player->health_sprite,
        player->health_texture, sfTrue);
}

static void set_life_position(player_t *player, sfVector2f position)
{
    sfSprite_setPosition(player->health_sprite, position);
}

void set_life(player_t *player, int x, int y)
{
    sfVector2f pos_life = {x, y};

    create_life_sprite(player, "assets/spritesheet_vie.png");
    sfSprite_setScale(player->health_sprite, (sfVector2f){3, 3});
    set_life_position(player, pos_life);
}
