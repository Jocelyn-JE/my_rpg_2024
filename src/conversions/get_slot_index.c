/*
** EPITECH PROJECT, 2023
** rpg: get_slot_index.c
** File description:
** get_slot_index source file
*/

#include "../../include/rpg.h"

inventory_params_t setup_inventory_params(int x, int y, app_t *app)
{
    inventory_params_t params;

    params.world_pos = sfRenderWindow_mapPixelToCoords(
        app->window, (sfVector2i){x, y}, app->view);
    params.center = sfView_getCenter(app->view);
    params.size = sfView_getSize(app->view);
    params.scale = adjust_sprite_scale(app->inventory, 1.0f, app->zoom);
    params.offset_X = 639 * params.scale;
    params.offset_Y = 542.5 * params.scale;
    params.slot_width = 66.5 * params.scale;
    params.slot_height = 66.5 * params.scale;
    params.spacing = 5.3 * params.scale;
    return params;
}

static int thing_indexing(sfVector2f start_cor, int column, int row,
    inventory_params_t params)
{
    float slotLeft = start_cor.x + column *
        (params.slot_width + params.spacing);
    float slotTop = start_cor.y + row *
        (params.slot_height + params.spacing);
    float slotRight = slotLeft + params.slot_width;
    float slotBottom = slotTop + params.slot_height;

    if (params.world_pos.x >= slotLeft && params.world_pos.x <= slotRight &&
        params.world_pos.y >= slotTop && params.world_pos.y <= slotBottom) {
        return row * 9 + column;
    }
    return -1;
}

static int calculate_slot_index(inventory_params_t params)
{
    float start_x = params.center.x - params.size.x / 2 + params.offset_X;
    float start_y = params.center.y - params.size.y / 2 + params.offset_Y;
    sfVector2f start_cor = {start_x, start_y};
    int column = (int)((params.world_pos.x - start_x) /
        (params.slot_width + params.spacing));
    int row = (int)((params.world_pos.y - start_y) /
        (params.slot_height + params.spacing));
    float trash_canX = start_x + 10 * (params.slot_width + params.spacing);
    float trash_canY = start_y + 3 * (params.slot_height + params.spacing);

    if (params.world_pos.x >= trash_canX && params.world_pos.x
        <= trash_canX + params.slot_width &&
        params.world_pos.y >= trash_canY &&
        params.world_pos.y <= trash_canY + params.slot_height) {
        return 1000;
    }
    if (row >= 0 && row < 4 && column >= 0 && column < 9)
        return thing_indexing(start_cor, column, row, params);
    return -1;
}

int get_slot_index(int x, int y, app_t *app)
{
    inventory_params_t params = setup_inventory_params(x, y, app);

    return calculate_slot_index(params);
}
