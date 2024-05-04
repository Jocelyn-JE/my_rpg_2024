/*
** EPITECH PROJECT, 2023
** rpg: inventory_management.c
** File description:
** inventory related queries
*/

#include "../../../include/rpg.h"

void draw_bounds(sfRenderWindow *window, sfSprite *sprite, float scale)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setPosition(shape, (sfVector2f){bounds.left, bounds.top});
    sfRectangleShape_setSize(shape, (sfVector2f){bounds.width, bounds.height});
    sfRectangleShape_setOutlineThickness(shape, (2.0f * scale));
    sfRectangleShape_setOutlineColor(shape, sfRed);
    sfRectangleShape_setFillColor(shape, sfTransparent);
    sfRenderWindow_drawRectangleShape(window, shape, NULL);
    sfRectangleShape_destroy(shape);
}

static void draw_sprite(app_t *app, int i, sfVector2f pos)
{
    float scale = 0.f;
    float baseScale = 1.0f;

    baseScale *= app->zoom;
    scale = baseScale;
    scale *= 1.6f;
    sfSprite_setPosition(app->inventory->slots[i]->sprite,
        (sfVector2f){pos.x, pos.y});
    sfSprite_setScale(app->inventory->slots[i]->sprite,
        (sfVector2f){scale, scale});
    sfRenderWindow_drawSprite(app->window,
        app->inventory->slots[i]->sprite, NULL);
}

static void draw_dragged_item(app_t *app)
{
    if (app->inventory->dragged_item != NULL) {
        sfRenderWindow_drawSprite(app->window,
        app->inventory->dragged_item->sprite, NULL);
        if (app->inventory->dragged_item->limit > 1)
            sfRenderWindow_drawText(app->window,
            app->inventory->dragged_item->quantity_text, NULL);
    }
}

static void draw_item_quantity(app_t *app, item_t *item,
    sfVector2f pos, float scale)
{
    char quantity[10];

    if (item->limit <= 1)
        return;
    sprintf(quantity, "%d", item->quantity);
    sfText_setString(item->quantity_text, quantity);
    sfText_setCharacterSize(item->quantity_text, (20.5 * scale));
    sfText_setPosition(item->quantity_text, (sfVector2f){pos.x + (29 * scale),
        pos.y + (34 * scale)});
    sfRenderWindow_drawText(app->window, item->quantity_text, NULL);
}

void draw_inventory_items(app_t *app, sfVector2f center,
    sfVector2f size, float scale)
{
    const float offsetX = 645 * scale;
    const float offsetY = 548 * scale;
    const float slotWidth = 72 * scale;
    const float slotHeight = 72 * scale;
    float start_x = center.x - size.x / 2 + offsetX;
    float start_y = center.y - size.y / 2 + offsetY;
    sfVector2f pos = {0, 0};

    for (int i = 0; i < 36; i++) {
        if (app->inventory->slots[i] == NULL)
            continue;
        pos.x = start_x + (i % 9) * slotWidth;
        pos.y = start_y + (i / 9) * slotHeight;
        draw_sprite(app, i, pos);
        draw_item_quantity(app, app->inventory->slots[i], pos, scale);
    }
    draw_dragged_item(app);
}

float adjust_sprite_scale(inventory_t *inventory, float baseScale,
    float currentZoom)
{
    float scale = 0.f;

    baseScale *= currentZoom;
    scale = baseScale;
    sfSprite_setScale(inventory->background, (sfVector2f){scale, scale});
    return (scale);
}

void draw_semi_transparent_rect(sfRenderWindow *window, const sfView *view)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfVector2f view_top_left =
        sfRenderWindow_mapPixelToCoords(window, (sfVector2i){0, 0}, view);

    sfRectangleShape_setPosition(shape, view_top_left);
    sfRectangleShape_setSize(shape, (sfVector2f){10000, 10000});
    sfRectangleShape_setFillColor(shape, (sfColor){0, 0, 0, 170});
    sfRenderWindow_drawRectangleShape(window, shape, NULL);
    sfRectangleShape_destroy(shape);
}

void draw_inventory(app_t *app)
{
    float scale = 0.f;
    sfVector2f center = sfView_getCenter(app->view);
    sfVector2f size = sfView_getSize(app->view);
    sfFloatRect backgroundBounds =
        sfSprite_getGlobalBounds(app->inventory->background);

    sfSprite_setPosition(app->inventory->background,
        (sfVector2f){center.x - backgroundBounds.width / 2,
            center.y - backgroundBounds.height / 2});
    scale = adjust_sprite_scale(app->inventory, 1.0f, app->zoom);
    draw_semi_transparent_rect(app->window, app->view);
    sfRenderWindow_drawSprite(app->window, app->inventory->background, NULL);
    draw_inventory_items(app, center, size, scale);
}
