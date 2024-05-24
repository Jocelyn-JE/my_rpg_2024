/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** manage hotbar
*/
#include "../../../include/rpg.h"

static float adjust_texture_scale(inventory_t *inventory, float baseScale,
    float currentZoom)
{
    float scale = 0.f;

    baseScale *= currentZoom;
    scale = baseScale;
    scale *= 3.8462f;
    sfSprite_setScale(inventory->hotbar, (sfVector2f){scale, scale});
    return (scale);
}

static void draw_texture_hotbar(app_t *app)
{
    sfVector2f center = sfView_getCenter(app->game_view);
    sfVector2f size = sfView_getSize(app->game_view);
    sfFloatRect backgroundBounds =
        sfSprite_getGlobalBounds(app->inventory->hotbar);
    float hotbarX = center.x - (backgroundBounds.width / 2);
    float hotbarY = center.y + (size.y / 2) - backgroundBounds.height;

    sfSprite_setPosition(app->inventory->hotbar,
        (sfVector2f){hotbarX, hotbarY});
    adjust_texture_scale(app->inventory, 1.0f, app->zoom);
    sfRenderWindow_drawSprite(app->window, app->inventory->hotbar, NULL);
}

static void draw_selection(app_t *app, float scale,
    float hotbarX, float hotbarY)
{
    float selectedX = hotbarX - (11 * scale) +
        (app->inventory->selected_slot * 45.3 * scale);
    float selectedY = hotbarY - (11.5 * scale);

    sfSprite_setPosition(app->inventory->selection,
        (sfVector2f){selectedX, selectedY});
    sfSprite_setScale(app->inventory->selection, (sfVector2f){scale * 2.25f,
        scale * 2.25f});
    sfRenderWindow_drawSprite(app->window, app->inventory->selection, NULL);
}

static void draw_item_quantity(app_t *app, int i,
    sfVector2f pos, float scale)
{
    char quantity[10];
    item_t *item = app->inventory->slots[i + 27];

    if (item->limit <= 1)
        return;
    sprintf(quantity, "%2d", item->quantity);
    sfText_setString(item->quantity_text, quantity);
    sfText_setCharacterSize(item->quantity_text, (12 * scale));
    sfText_setPosition(item->quantity_text,
        (sfVector2f){pos.x + (16 * scale) + (i * 45.3) *
            scale, pos.y + 19 * scale});
    sfRenderWindow_drawText(app->window, item->quantity_text, NULL);
}

static void draw_hotbar_items(app_t *app, float scale)
{
    sfFloatRect bounds =
        sfSprite_getGlobalBounds(app->inventory->hotbar);
    const sfVector2f center = sfView_getCenter(app->game_view);
    const sfVector2f size = sfView_getSize(app->game_view);
    sfVector2f hotbar_pos = {center.x - ((bounds.width - 18 * scale) / 2),
        center.y + (size.y / 2) - bounds.height + 10 * scale};

    for (int i = 0; i < 9; i++) {
        if (app->inventory->slots[i + 27] == NULL)
            continue;
        sfSprite_setPosition(app->inventory->slots[i + 27]->sprite,
            (sfVector2f){hotbar_pos.x + (i * 45.3 * scale), hotbar_pos.y});
        sfSprite_setScale(app->inventory->slots[i + 27]->sprite,
            (sfVector2f){scale * 2.f, scale * 2.f});
        sfRenderWindow_drawSprite(app->window,
            app->inventory->slots[i + 27]->sprite, NULL);
        draw_item_quantity(app, i,
            hotbar_pos, scale);
    }
    draw_selection(app, scale, hotbar_pos.x, hotbar_pos.y);
}

float calculate_scale(inventory_t *inventory, float baseScale,
    float currentZoom)
{
    float scale = 0.f;

    baseScale *= currentZoom;
    scale = baseScale;
    sfSprite_setScale(inventory->background, (sfVector2f){scale, scale});
    return (scale);
}

void draw_hotbar(app_t *app)
{
    float scale = 0.f;

    draw_texture_hotbar(app);
    scale = calculate_scale(app->inventory, 1.0f, app->zoom);
    scale *= 1.7f;
    draw_hotbar_items(app, scale);
}
