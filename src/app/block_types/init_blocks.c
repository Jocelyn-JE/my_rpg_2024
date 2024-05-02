/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** init_blocks
*/
#include "blocks.h"
#include "rpg.h"

sfVertex *get_top_face(sfVector2f text_pos1, sfVector2f text_pos2,
    sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 7);

    vertices[0] = (sfVertex){(sfVector2f){0 + offset.x, 0 + offset.y}, sfWhite,
        text_pos1};
    vertices[1] = (sfVertex){(sfVector2f){1 + offset.x, 0 + offset.y}, sfWhite,
        (sfVector2f){text_pos2.x, text_pos1.y}};
    vertices[2] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        text_pos2};
    vertices[3] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        text_pos2};
    vertices[4] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){text_pos1.x, text_pos2.y}};
    vertices[5] = (sfVertex){(sfVector2f){0 + offset.x, 0 + offset.y}, sfWhite,
        text_pos1};
    vertices[6] = (sfVertex){(sfVector2f){0, 0},
        (sfColor){0, 0, 0, 0}, (sfVector2f){0, 0}};
    return vertices;
}

sfVertex *get_left_face(sfVector2f text_pos1, sfVector2f text_pos2,
    sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 7);

    vertices[0] = (sfVertex){(sfVector2f){1 + offset.x, 0 + offset.y}, sfWhite,
        text_pos1};
    vertices[1] = (sfVertex){(sfVector2f){2 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){text_pos1.x, text_pos2.y}};
    vertices[2] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){text_pos2.x, text_pos1.y}};
    vertices[3] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){text_pos2.x, text_pos1.y}};
    vertices[4] = (sfVertex){(sfVector2f){2 + offset.x, 2 + offset.y}, sfWhite,
        text_pos2};
    vertices[5] = (sfVertex){(sfVector2f){2 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){text_pos1.x, text_pos2.y}};
    vertices[6] = (sfVertex){(sfVector2f){0, 0},
        (sfColor){0, 0, 0, 0}, (sfVector2f){0, 0}};
    return vertices;
}

sfVertex *get_right_face(sfVector2f text_pos1, sfVector2f text_pos2,
    sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 7);

    vertices[0] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        text_pos1};
    vertices[1] = (sfVertex){(sfVector2f){2 + offset.x, 2 + offset.y}, sfWhite,
        (sfVector2f){text_pos1.x, text_pos2.y}};
    vertices[2] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y},
        sfWhite, (sfVector2f){text_pos2.x, text_pos1.y}};
    vertices[3] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){text_pos2.x, text_pos1.y}};
    vertices[4] = (sfVertex){(sfVector2f){1 + offset.x, 2 + offset.y}, sfWhite,
        text_pos2};
    vertices[5] = (sfVertex){(sfVector2f){2 + offset.x, 2 + offset.y}, sfWhite,
        (sfVector2f){text_pos1.x, text_pos2.y}};
    vertices[6] = (sfVertex){(sfVector2f){0, 0},
        (sfColor){0, 0, 0, 0}, (sfVector2f){0, 0}};
    return vertices;
}

const init_func_t init_block_functions[] = {
    {init_null},
    {init_air},
    {init_stone},
    {init_oak_planks},
    {init_oak_log},
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
    {init_fern}
};

block_t **init_blocks(void)
{
    block_t **blocks = malloc(sizeof(block_t *) * 24);

    for (int i = 0; i != 23; i++) {
        blocks[i] = init_block_functions[i].function();
    }
    blocks[23] = NULL;
    return blocks;
}
