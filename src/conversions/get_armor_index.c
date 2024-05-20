/*
** EPITECH PROJECT, 2023
** rpg: get_armor_index.c
** File description:
** get_armor_slot_index source file
*/

#include "../../include/rpg.h"

inventory_params_t setup_armor_params(int x, int y, app_t *app)
{
    inventory_params_t params;

    params.world_pos = sfRenderWindow_mapPixelToCoords(
        app->window, (sfVector2i){x, y}, app->game_view);
    params.center = sfView_getCenter(app->game_view);
    params.size = sfView_getSize(app->game_view);
    params.scale = adjust_sprite_scale(app->inventory, 1.0f, app->zoom);
    params.offset_X = 640.5 * params.scale;
    params.offset_Y = 239 * params.scale;
    params.slot_width = 64 * params.scale;
    params.slot_height = 66.1 * params.scale;
    params.spacing = 8 * params.scale;
    return params;
}

static int thing_indexing(sfVector2f start_cor, int row,
    inventory_params_t params)
{
    float slotLeft = start_cor.x;
    float slotTop = start_cor.y + row * (params.slot_height + params.spacing);
    float slotRight = slotLeft + params.slot_width;
    float slotBottom = slotTop + params.slot_height;

    if (params.world_pos.x >= slotLeft && params.world_pos.x <= slotRight &&
        params.world_pos.y >= slotTop && params.world_pos.y <= slotBottom) {
        return row;
    }
    return -1;
}

static int calculate_slot_index(inventory_params_t params)
{
    float start_x = params.center.x - params.size.x / 2 + params.offset_X;
    float start_y = params.center.y - params.size.y / 2 + params.offset_Y;
    sfVector2f start_cor = {start_x, start_y};
    int row = (int)((params.world_pos.y - start_y) /
        (params.slot_height + params.spacing));

    if (row >= 0 && row < 4) {
        return thing_indexing(start_cor, row, params);
    }
    return -1;
}

int get_armor_index(int x, int y, app_t *app)
{
    inventory_params_t params = setup_armor_params(x, y, app);

    return calculate_slot_index(params);
}
