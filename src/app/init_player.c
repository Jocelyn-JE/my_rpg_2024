/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init_player
*/

#include "rpg.h"

player_t *init_player(void)
{
    player_t *new_player = malloc(sizeof(player_t));

    new_player->stats.defense = 0;
    new_player->stats.health = 20;
    new_player->stats.attack = 1;
    new_player->enemy = NULL;
    new_player->pos.x = 410.0f;
    new_player->pos.y = 194.0f;
    set_life(new_player, 1920 / 2, 1780);
    return new_player;
}
