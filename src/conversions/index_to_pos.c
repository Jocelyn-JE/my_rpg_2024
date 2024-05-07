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

int get_chunk_index_from_coordinates(int x, int y)
{
    return y * 32 + x;
}

sfVector2i get_chunk_coordinates_from_index(int index)
{
    int x = index % 32;
    int y = index / 32;

    return (sfVector2i){y, x};
}
