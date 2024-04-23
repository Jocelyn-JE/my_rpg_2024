/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** 3d_to_1d
*/
#include "rpg.h"

int get_index_from_pos(int x, int y, int z)
{
    return (z * 256) + (y * 16) + x;
}

vector3uint8_t get_pos_from_index(int i)
{
    return (vector3uint8_t){i % 16, (i / 16) % 16, i / 256};
}
