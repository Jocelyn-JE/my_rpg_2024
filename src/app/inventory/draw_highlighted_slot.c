/*
** EPITECH PROJECT, 2023
** rpg: draw_highlighted_slot.c
** File description:
** draw highlighted slot
*/

#include "../../../include/rpg.h"

static void draw_inventory_highlight(sfRenderWindow *window,
    app_t *app, int slot_index)
{
        int row = slot_index / 9;
        int column = slot_index % 9;
        inventory_params_t params = setup_inventory_params(0, 0, app);
        float slot_x = params.center.x - params.size.x / 2 + params.offset_X +
            column * (params.slot_width + params.spacing);
        float slot_y = params.center.y - params.size.y / 2 + params.offset_Y +
            row * (params.slot_height + params.spacing);
        sfRectangleShape* highlight_rect = sfRectangleShape_create();

        sfRectangleShape_setPosition(highlight_rect,
            (sfVector2f){slot_x, slot_y});
        sfRectangleShape_setSize(highlight_rect,
            (sfVector2f){params.slot_width, params.slot_height});
        sfRectangleShape_setFillColor(highlight_rect,
            sfColor_fromRGBA(255, 255, 255, 128));
        sfRenderWindow_drawRectangleShape(window, highlight_rect, NULL);
        sfRectangleShape_destroy(highlight_rect);
}

static void draw_armor_highlight(sfRenderWindow *window,
    app_t *app, int slot_index)
{
        inventory_params_t params = setup_armor_params(0, 0, app);
        float slot_x = params.center.x - params.size.x / 2 + params.offset_X;
        float slot_y = params.center.y - params.size.y / 2 + params.offset_Y +
            slot_index * (params.slot_height + params.spacing);
        sfRectangleShape* highlight_rect = sfRectangleShape_create();

        sfRectangleShape_setPosition(highlight_rect,
            (sfVector2f){slot_x, slot_y});
        sfRectangleShape_setSize(highlight_rect,
            (sfVector2f){params.slot_width, params.slot_height});
        sfRectangleShape_setFillColor(highlight_rect,
            sfColor_fromRGBA(255, 255, 255, 128));
        sfRenderWindow_drawRectangleShape(window, highlight_rect, NULL);
        sfRectangleShape_destroy(highlight_rect);
}

void draw_highlighted_slot(app_t *app)
{
    if (app->inventory->current_item_slot != -1)
        draw_inventory_highlight(app->window,
        app, app->inventory->current_item_slot);
    else if (app->inventory->current_armor_slot != -1)
        draw_armor_highlight(app->window,
        app, app->inventory->current_armor_slot);
}
