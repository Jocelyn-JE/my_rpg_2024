/*
** EPITECH PROJECT, 2023
** my_rpg: setup_combat.c
** File description:
** combat initialization file
*/

#include "../../../include/rpg.h"

void attack_player(entity_t *attacker, player_t *defender)
{
    int defense_delta = get_random_nb(0, 100);
    int damage = attacker->stats.attack;

    if (defense_delta < defender->stats.defense)
        return;
    defender->stats.health -= damage;
    if (defender->stats.health < 0)
        defender->stats.health = 0;
    return;
}

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
