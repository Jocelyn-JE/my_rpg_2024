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
            sfSprite_setPosition(inventory->slots[i]->sprite,
                (sfVector2f){x, y});
            sfRenderWindow_drawSprite(window,
                inventory->slots[i]->sprite, NULL);
        }
    }
}

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
    draw_inventory_items(app->window, app->inventory, center, size);
}
