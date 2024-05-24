/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** 3d_to_1d
*/
#include "rpg.h"

int get_idx_from_pos(int x, int y, int z)
{
    return (z << 8) + (y << 4) + x;
}

vector3uint8_t get_pos_from_index(int i)
{
    return (vector3uint8_t){i & 15, (i >> 4) & 15, i >> 8};
}

int get_chunk_index_from_coordinates(int x, int y)
{
    return (x << 5) + y;
}

sfVector2i get_chunk_coordinates_from_index(int index)
{
    return (sfVector2i){index >> 5, index & 31};
}

sfVector2i get_block_coordinates_from_index(int index)
{
    return (sfVector2i){index >> 9, index & 511};
}
