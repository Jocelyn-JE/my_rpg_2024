/*
** EPITECH PROJECT, 2023
** Random functions
** File description:
** random.c
*/
#include "rpg.h"

int get_random_nb(int min_value, int max_value)
{
    return ((rand() % (max_value - min_value + 1)) + min_value);
}
