/*
** EPITECH PROJECT, 2023
** rpg: inventory_management.c
** File description:
** inventory related queries
*/

#include "../include/rpg.h"

void draw_inventory_items(sfRenderWindow *window, inventory_t *inventory,
    sfVector2f center, sfVector2f size)
{
    float start_x = center.x - size.x / 2 + 50;
    float start_y = center.y - size.y / 2 + 50;
    float x = 0;
    float y = 0;

    for (int i = 0; i < 32; i++) {
        if (inventory->slots[i] == NULL)
            continue;
        x = start_x + (i % 8) * 50;
        y = start_y + (i / 8) * 50;
        if (inventory->slots[i] != NULL) {
            sfSprite_setScale(inventory->slots[i]->sprite,
                (sfVector2f){0.5f, 0.5f});
            sfSprite_setPosition(inventory->slots[i]->sprite,
                (sfVector2f){x, y});
            sfRenderWindow_drawSprite(window,
                inventory->slots[i]->sprite, NULL);
        }
    }
}

void adjust_sprite_scale(inventory_t *inventory,
    float baseScale, float currentZoom)
{
    float scale = 0.f;

    baseScale *= currentZoom;
    scale = baseScale;
    sfSprite_setScale(inventory->background, (sfVector2f){scale, scale});
    for (size_t i = 0; i < 32; i++) {
        if (inventory->slots[i] != NULL) {
            sfSprite_setScale(inventory->slots[i]->sprite,
                (sfVector2f){scale, scale});
        }
    }
}

void draw_semi_transparent_rect(sfRenderWindow *window, const sfView *view)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfVector2f view_top_left = sfRenderWindow_mapPixelToCoords(window,
        (sfVector2i){0, 0}, view);

    sfRectangleShape_setPosition(shape, view_top_left);
    sfRectangleShape_setSize(shape, (sfVector2f){10000, 10000});
    sfRectangleShape_setFillColor(shape, (sfColor){0, 0, 0, 170});
    sfRenderWindow_drawRectangleShape(window, shape, NULL);
    sfRectangleShape_destroy(shape);
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
    adjust_sprite_scale(app->inventory, 1.0f, app->zoom);
    draw_semi_transparent_rect(app->window, view);
    sfRenderWindow_drawSprite(app->window, app->inventory->background, NULL);
    draw_inventory_items(app->window, app->inventory, center, size);
}
