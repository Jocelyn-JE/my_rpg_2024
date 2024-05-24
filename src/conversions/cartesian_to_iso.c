/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** cartesian_to_iso
*/
#include "rpg.h"

sfVector2f cartesian_to_isometric(float x, float y, float z, float size)
{
    float xz = x - z;
    float yz = y - z;

    return (sfVector2f){(xz - yz) * size * 0.5f, (xz + yz) * size * 0.25f};
}

sfVector2f isometric_to_cartesian(float x, float y, float size)
{
    float inv_size = 1.0f / size;
    float two_y = 2.0f * y;

    return (sfVector2f){(x + two_y) * inv_size, (-x + two_y) * inv_size};
}
