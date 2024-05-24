/*
** EPITECH PROJECT, 2023
** rpg: inventory_management.c
** File description:
** inventory related queries
*/

#include "../../../include/rpg.h"

static void draw_sprite(app_t *app, int i, sfVector2f pos, float scale)
{
    sfSprite_setPosition(app->inventory->slots[i]->sprite,
        (sfVector2f){pos.x, pos.y});
    sfSprite_setScale(app->inventory->slots[i]->sprite,
        (sfVector2f){scale * 1.87f * 2.f, scale * 1.94f * 2.f});
    sfRenderWindow_drawSprite(app->window,
        app->inventory->slots[i]->sprite, NULL);
}

static void draw_item_quantity(app_t *app, item_t *item,
    sfVector2f pos, float scale)
{
    char quantity[10];

    if (item->limit <= 1)
        return;
    sprintf(quantity, "%2d", item->quantity);
    sfText_setString(item->quantity_text, quantity);
    sfText_setCharacterSize(item->quantity_text, (20.5 * scale));
    sfText_setPosition(item->quantity_text, (sfVector2f){pos.x + (31 * scale),
        pos.y + (39 * scale)});
    sfRenderWindow_drawText(app->window, item->quantity_text, NULL);
}

static void draw_dragged_item(app_t *app)
{
    char quantity[10];

    if (app->inventory->dragged_item != NULL) {
        sfRenderWindow_drawSprite(app->window,
        app->inventory->dragged_item->sprite, NULL);
        if (app->inventory->dragged_item->limit > 1) {
            sprintf(quantity, "%2d", app->inventory->dragged_item->quantity);
            sfText_setString(app->inventory->dragged_item->quantity_text,
                quantity);
            sfRenderWindow_drawText(app->window,
            app->inventory->dragged_item->quantity_text, NULL);
        }
    }
}

static void draw_inventory_items(app_t *app, sfVector2f center,
    sfVector2f size, float scale)
{
    const float offsetX = 642 * scale;
    const float offsetY = 554 * scale;
    const float slot_x = 72 * scale;
    const float slot_y = 74.4 * scale;
    float start_x = center.x - size.x / 2 + offsetX;
    float start_y = center.y - size.y / 2 + offsetY;
    sfVector2f pos = {0, 0};

    for (int i = 0; i < 36; i++) {
        if (app->inventory->slots[i] == NULL)
            continue;
        pos.x = start_x + (i % 9) * slot_x;
        pos.y = start_y + (i / 9) * slot_y;
        draw_sprite(app, i, pos, scale);
        draw_item_quantity(app, app->inventory->slots[i], pos, scale);
    }
    draw_highlighted_slot(app);
}

void draw_sprite_armor(app_t *app, int i, sfVector2f pos, float scale)
{
    sfSprite_setPosition(app->inventory->armor[i]->sprite,
        (sfVector2f){pos.x, pos.y});
    sfSprite_setScale(app->inventory->armor[i]->sprite,
        (sfVector2f){scale * 1.87f * 2.f, scale * 1.94f * 2.f});
    sfRenderWindow_drawSprite(app->window,
        app->inventory->armor[i]->sprite, NULL);
}

static void draw_armor_items(app_t *app, sfVector2f center,
    sfVector2f size, float scale)
{
    const float offsetX = 642 * scale;
    const float offsetY = 241 * scale;
    const float slot_len = 74.4 * scale;
    float start_x = center.x - size.x / 2 + offsetX;
    float start_y = center.y - size.y / 2 + offsetY;
    sfVector2f pos = {0, 0};

    for (int i = 0; i < 4; i++) {
        if (app->inventory->armor[i] == NULL)
            continue;
        pos.x = start_x;
        pos.y = start_y + i * slot_len;
        draw_sprite_armor(app, i, pos, scale);
    }
    draw_dragged_item(app);
}

float adjust_sprite_scale(inventory_t *inventory, float baseScale,
    float currentZoom)
{
    float scale = 0.f;

    baseScale *= currentZoom;
    scale = baseScale;
    sfSprite_setScale(inventory->background,
        (sfVector2f){scale * 4.0057, scale * 4.1173});
    sfSprite_setScale(inventory->trash,
        (sfVector2f){scale * 1.88, scale * 1.9});
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
    sfVector2f center = sfView_getCenter(app->game_view);
    sfVector2f size = sfView_getSize(app->game_view);
    sfFloatRect background_bounds = sfSprite_getGlobalBounds(
        app->inventory->background);

    sfRenderWindow_clear(app->window, sfBlack);
    scale = adjust_sprite_scale(app->inventory, 1.0f, app->zoom);
    sfSprite_setPosition(app->inventory->background,
        (sfVector2f){center.x - background_bounds.width / 2,
            center.y - background_bounds.height / 2});
    sfSprite_setPosition(app->inventory->trash,
        (sfVector2f){center.x + 400.5 * scale, center.y + 234 * scale});
    draw_chunks(app->game_ressources->map, app);
    draw_semi_transparent_rect(app->window, app->game_view);
    sfRenderWindow_drawSprite(app->window, app->inventory->background, NULL);
    sfRenderWindow_drawSprite(app->window, app->inventory->trash, NULL);
    draw_inventory_items(app, center, size, scale);
    draw_armor_items(app, center, size, scale);
}

void switch_to_inventory(app_t *app)
{
    app->event_handler = manage_invent_events;
    app->draw_function = draw_inventory;
}
