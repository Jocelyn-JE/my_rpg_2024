/*
** EPITECH PROJECT, 2023
** myrpg: is_armor.c
** File description:
** check if item is armor
*/

#include "../../../include/rpg.h"

bool is_helmet(p_items_t item)
{
    if (item == p_diamond_helmet)
        return true;
    return false;
}

bool is_chestplate(p_items_t item)
{
    if (item == p_diamond_chestplate)
        return true;
    return false;
}

bool is_leggings(p_items_t item)
{
    if (item == p_diamond_leggings)
        return true;
    return false;
}

bool is_boots(p_items_t item)
{
    if (item == p_diamond_boots)
        return true;
    return false;
}
