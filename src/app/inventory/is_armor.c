/*
** EPITECH PROJECT, 2023
** myrpg: is_armor.c
** File description:
** check if item is armor
*/

#include "../../../include/rpg.h"

bool is_helmet(p_items_t item)
{
    if (item == p_diamond_helmet || item == p_iron_helmet ||
        item == p_gold_helmet || item == p_netherite_helmet)
        return true;
    return false;
}

bool is_chestplate(p_items_t item)
{
    if (item == p_diamond_chestplate || item == p_iron_chestplate ||
        item == p_gold_chestplate || item == p_netherite_chestplate)
        return true;
    return false;
}

bool is_leggings(p_items_t item)
{
    if (item == p_diamond_leggings || item == p_iron_leggings ||
        item == p_gold_leggings || item == p_netherite_leggings)
        return true;
    return false;
}

bool is_boots(p_items_t item)
{
    if (item == p_diamond_boots || item == p_iron_boots ||
        item == p_gold_boots || item == p_netherite_boots)
        return true;
    return false;
}
