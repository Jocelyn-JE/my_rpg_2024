/*
** EPITECH PROJECT, 2023
** rpg: inventory_management.c
** File description:
** inventory related queries
*/

#include "../include/rpg.h"

void adjust_sprite_scale(sfSprite *sprite, float baseScale, float currentZoom)
{
    float scale = 0.f;

    baseScale *= currentZoom;
    scale = baseScale;
    sfSprite_setScale(sprite, (sfVector2f){scale, scale});
}

void draw_inventory(app_t *app)
{
    const sfView *view = sfRenderWindow_getView(app->window);
    sfVector2f center = sfView_getCenter(view);
    sfVector2f size = sfView_getSize(view);
    sfFloatRect backgroundBounds =
        sfSprite_getGlobalBounds(app->inventory->background);

    sfSprite_setPosition(app->inventory->background,
        (sfVector2f){center.x - backgroundBounds.width / 2,
            center.y - backgroundBounds.height / 2});
    adjust_sprite_scale(app->inventory->background, 1.0f, app->zoom);
    sfRenderWindow_drawSprite(app->window, app->inventory->background, NULL);
    // draw_inventory_items(window, inventory, center, size);
}
