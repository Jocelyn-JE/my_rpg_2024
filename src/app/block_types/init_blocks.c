/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** init_blocks
*/
#include "blocks.h"
#include "rpg.h"

const init_func_t init_block_functions[] = {
    {init_null},
    {init_air},
    {init_stone},
    {init_oak_planks},
    {init_y_oak_log},
    {init_grass_block},
    {init_barrel},
    {init_beehive},
    {init_bookshelf},
    {init_cactus},
    {init_sand},
    {init_dirt_path},
    {init_grass},
    {init_cobblestone},
    {init_dead_bush},
    {init_sandstone},
    {init_smooth_sandstone},
    {init_cut_sandstone},
    {init_ice},
    {init_water},
    {init_jungle_log},
    {init_mossy_cobblestone},
    {init_fern},
    {init_snowy_grass_block},
    {init_poppy},
    {init_dandelion},
    {init_wheat},
    {init_beetroots},
    {init_white_wool},
    {init_y_oak_wood},
    {init_x_oak_wood},
    {init_z_oak_wood},
    {init_oak_leaves},
    {init_jungle_leaves},
    {init_spruce_leaves},
    {init_snow},
    {init_end_stone_bricks},
    {init_end_stone},
    {init_special_sandstone},
    {init_y_stripped_birch_wood},
    {init_y_hay_block},
    {init_x_hay_block},
    {init_z_hay_block},
    {init_dirt},
    {init_coarse_dirt},
    {init_rooted_dirt},
    {init_brown_concrete_powder},
    {init_podzol},
    {init_brown_concrete},
    {init_dead_brain_coral_block},
    {init_dead_fire_coral_block},
    {init_moss_block},
    {init_white_concrete_powder},
    {init_smooth_quartz},
    {init_diorite},
    {init_birch_planks},
    {init_spruce_planks},
    {init_calcite},
    {init_dark_oak_planks},
    {init_jungle_planks},
    {init_x_oak_log},
    {init_z_oak_log},
    {init_y_spruce_log},
    {init_x_spruce_log},
    {init_z_spruce_log},
    {init_lava},
    {init_andesite},
    {init_blackstone},
    {init_polished_blackstone},
    {init_polished_blackstone_bricks},
    {init_gilded_blackstone},
    {init_cracked_polished_blackstone_bricks},
    {init_chiseled_polished_blackstone},
    {init_coal_block}
};

sfVertex *get_top_face(uv_coords_t uv,
    sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 7);

    vertices[0] = (sfVertex){(sfVector2f){0 + offset.x, 0 + offset.y}, sfWhite,
        uv.top_left};
    vertices[1] = (sfVertex){(sfVector2f){1 + offset.x, 0 + offset.y}, sfWhite,
        (sfVector2f){uv.bottom_right.x, uv.top_left.y}};
    vertices[2] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        uv.bottom_right};
    vertices[3] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        uv.bottom_right};
    vertices[4] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){uv.top_left.x, uv.bottom_right.y}};
    vertices[5] = (sfVertex){(sfVector2f){0 + offset.x, 0 + offset.y}, sfWhite,
        uv.top_left};
    vertices[6] = null_vertex();
    return vertices;
}

sfVertex *get_left_face(uv_coords_t uv,
    sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 7);

    vertices[0] = (sfVertex){(sfVector2f){1 + offset.x, 0 + offset.y}, sfWhite,
        uv.top_left};
    vertices[1] = (sfVertex){(sfVector2f){2 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){uv.top_left.x, uv.bottom_right.y}};
    vertices[2] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){uv.bottom_right.x, uv.top_left.y}};
    vertices[3] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){uv.bottom_right.x, uv.top_left.y}};
    vertices[4] = (sfVertex){(sfVector2f){2 + offset.x, 2 + offset.y}, sfWhite,
        uv.bottom_right};
    vertices[5] = (sfVertex){(sfVector2f){2 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){uv.top_left.x, uv.bottom_right.y}};
    vertices[6] = null_vertex();
    return vertices;
}

sfVertex *get_right_face(uv_coords_t uv,
    sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 7);

    vertices[0] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        uv.top_left};
    vertices[1] = (sfVertex){(sfVector2f){2 + offset.x, 2 + offset.y}, sfWhite,
        (sfVector2f){uv.top_left.x, uv.bottom_right.y}};
    vertices[2] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y},
        sfWhite, (sfVector2f){uv.bottom_right.x, uv.top_left.y}};
    vertices[3] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){uv.bottom_right.x, uv.top_left.y}};
    vertices[4] = (sfVertex){(sfVector2f){1 + offset.x, 2 + offset.y}, sfWhite,
        uv.bottom_right};
    vertices[5] = (sfVertex){(sfVector2f){2 + offset.x, 2 + offset.y}, sfWhite,
        (sfVector2f){uv.top_left.x, uv.bottom_right.y}};
    vertices[6] = null_vertex();
    return vertices;
}

// The block_count is the last added block + 1
block_t **init_blocks(void)
{
    uint8_t block_count = b_coal_block + 1;
    block_t **blocks = malloc(sizeof(block_t *) * (block_count + 1));

    for (int i = 0; i != block_count; i++)
        blocks[i] = init_block_functions[i].function();
    blocks[block_count] = NULL;
    return blocks;
}
