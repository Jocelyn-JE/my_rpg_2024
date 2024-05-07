/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** cartesian_to_iso
*/
#include "rpg.h"

sfVector2f cartesian_to_isometric(float x, float y, float z, float size)
{
    sfVector2f pos = {((x - z) - (y - z)) * size * 0.5f,
        ((x - z) + (y - z)) * size * 0.25f};

    return pos;
}

sfVector2f isometric_to_cartesian(float x, float y, float size)
{
    sfVector2f pos = {(x + (2.0f * y)) / size, (-x + (2.0f * y)) / size};

    return pos;
}