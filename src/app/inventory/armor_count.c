/*
** EPITECH PROJECT, 2023
** rpg: inventory_management.c
** File description:
** inventory related queries
*/

#include "../../../include/rpg.h"

static int helmet_armor(item_t *item)
{
    if (item == NULL)
        return (0);
    if (item->current_item == p_iron_helmet ||
        item->current_item == p_gold_helmet)
        return (2);
    if (item->current_item == p_diamond_helmet ||
        item->current_item == p_netherite_helmet)
        return (3);
    return (0);
}

static int chestplate_armor(item_t *item)
{
    if (item == NULL)
        return (0);
    if (item->current_item == p_gold_chestplate)
        return (2);
    if (item->current_item == p_iron_chestplate)
        return (3);
    if (item->current_item == p_diamond_chestplate ||
        item->current_item == p_netherite_chestplate)
        return (4);
    return (0);
}

static int leggings_armor(item_t *item)
{
    if (item == NULL)
        return (0);
    if (item->current_item == p_gold_leggings)
        return (2);
    if (item->current_item == p_iron_leggings)
        return (4);
    if (item->current_item == p_diamond_leggings ||
        item->current_item == p_netherite_leggings)
        return (5);
    return (0);
}

static int boots_armor(item_t *item)
{
    if (item == NULL)
        return (0);
    if (item->current_item == p_gold_boots)
        return (1);
    if (item->current_item == p_iron_boots)
        return (2);
    if (item->current_item == p_diamond_boots ||
        item->current_item == p_netherite_boots)
        return (3);
    return (0);
}

int get_total_armor_value(inventory_t *inventory)
{
    int total_armor = 0;

    total_armor += helmet_armor(inventory->armor[0]);
    total_armor += chestplate_armor(inventory->armor[1]);
    total_armor += leggings_armor(inventory->armor[2]);
    total_armor += boots_armor(inventory->armor[3]);
    return (total_armor);
}
