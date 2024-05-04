/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** manage hotbar
*/
#include "../include/rpg.h"

static float adjust_texture_scale(inventory_t *inventory, float baseScale,
    float currentZoom)
{
    float scale = 0.f;

    baseScale *= currentZoom;
    scale = baseScale;
    sfSprite_setScale(inventory->hotbar, (sfVector2f){scale, scale});
    return (scale);
}

static void draw_texture_hotbar(app_t *app)
{
    float scale = 0.f;
    sfVector2f center = sfView_getCenter(app->view);
    sfVector2f size = sfView_getSize(app->view);
    sfFloatRect backgroundBounds =
        sfSprite_getGlobalBounds(app->inventory->hotbar);
    float hotbarX = center.x - (backgroundBounds.width / 2);
    float hotbarY = center.y + (size.y / 2) - backgroundBounds.height;

    sfSprite_setPosition(app->inventory->hotbar,
        (sfVector2f){hotbarX, hotbarY});
    scale = adjust_texture_scale(app->inventory, 1.0f, app->zoom);
    sfRenderWindow_drawSprite(app->window, app->inventory->hotbar, NULL);
}

static void draw_selection(app_t *app, float scale,
    float hotbarX, float hotbarY)
{
    float selectedX = hotbarX - (13.5 * scale) +
        (app->inventory->selected_slot * 45.3 * scale);
    float selectedY = hotbarY - (14 * scale);

    sfSprite_setPosition(app->inventory->selection,
        (sfVector2f){selectedX, selectedY});
    sfSprite_setScale(app->inventory->selection, (sfVector2f){scale, scale});
    sfRenderWindow_drawSprite(app->window, app->inventory->selection, NULL);
}

static void draw_hotbar_items(app_t *app, float scale)
{
    sfFloatRect hotbarBounds =
        sfSprite_getGlobalBounds(app->inventory->hotbar);
    const sfVector2f center = sfView_getCenter(app->view);
    const sfVector2f size = sfView_getSize(app->view);
    float hotbarX = center.x - ((hotbarBounds.width - 18 * scale) / 2);
    float hotbarY = center.y + (size.y / 2) - hotbarBounds.height + 10 * scale;

    for (int i = 0; i < 9; i++) {
        if (app->inventory->slots[i + 27] == NULL)
            continue;
        sfSprite_setPosition(app->inventory->slots[i + 27]->sprite,
            (sfVector2f){hotbarX + (i * 45.3 * scale), hotbarY});
        sfSprite_setScale(app->inventory->slots[i + 27]->sprite,
            (sfVector2f){scale, scale});
        sfRenderWindow_drawSprite(app->window,
            app->inventory->slots[i + 27]->sprite, NULL);
    }
    draw_selection(app, scale, hotbarX, hotbarY);
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
