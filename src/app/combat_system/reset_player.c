/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** rpg
*/

#include "rpg.h"

void reset_player_stats(player_t *player)
{
    player->stats.health = 20;
    player->pos = (sfVector2f){410.f, 194.f};
}
