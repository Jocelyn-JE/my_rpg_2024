/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** draw_bounding_box
*/
#include "rpg.h"

void draw_bounding_box(sfRenderWindow *window, sfFloatRect box,
    sfVector2f position)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setSize(rect, (sfVector2f){box.width, box.height});
    sfRectangleShape_setPosition(rect, (sfVector2f){box.left + position.x,
        box.top + position.y});
    sfRectangleShape_setOutlineColor(rect, sfRed);
    sfRectangleShape_setOutlineThickness(rect,
        sfView_getSize(sfRenderWindow_getDefaultView(window)).x / 1000);
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    sfRectangleShape_destroy(rect);
}
