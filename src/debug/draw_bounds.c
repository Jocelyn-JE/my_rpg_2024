/*
** EPITECH PROJECT, 2023
** rpg: draw_bounds.c
** File description:
** draw bounds of a sprite
*/

#include "../../include/rpg.h"

void draw_bounds(sfRenderWindow *window, sfSprite *sprite, float scale)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setPosition(shape, (sfVector2f){bounds.left, bounds.top});
    sfRectangleShape_setSize(shape, (sfVector2f){bounds.width, bounds.height});
    sfRectangleShape_setOutlineThickness(shape, (2.f * scale));
    sfRectangleShape_setOutlineColor(shape, sfRed);
    sfRectangleShape_setFillColor(shape, sfTransparent);
    sfRenderWindow_drawRectangleShape(window, shape, NULL);
    sfRectangleShape_destroy(shape);
}
