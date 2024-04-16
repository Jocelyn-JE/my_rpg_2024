/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** cartesian_to_iso
*/
#include "rpg.h"

sfVector2f cartesian_to_isometric(float y, float x, float size)
{
    return (sfVector2f){(x - y) * size * 0.5f, (x + y) * size * 0.25f};
}

sfVector2f isometric_to_cartesian(float x, float y, float size)
{
    return (sfVector2f){(x + (2.0f * y)) / size, (-x + (2.0f * y)) / size};
}
