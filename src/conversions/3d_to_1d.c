/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** 3d_to_1d
*/
#include "rpg.h"

int volumetric_to_linear(int x, int y, int z)
{
    return (z * 16 * 16) + (y * 16) + x;
}