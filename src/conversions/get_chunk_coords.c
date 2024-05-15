/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** get_chunk_coords
*/
#include "rpg.h"

sfVector2f get_chunk_coords(sfVector2f pos)
{
    sfVector2f mod = {16.f, 16.f};
    sfVector2f chunk_pos = {modff(pos.x, &mod.x) + (int)mod.x % 16, modff(pos.y,
        &mod.y) + (int)mod.y % 16};

    return chunk_pos;
}
