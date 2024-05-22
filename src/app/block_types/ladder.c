/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** ladder
*/
#include "blocks.h"

block_t *init_ladder_east(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_left_face((uv_coords_t){(sfVector2f){128, 256},
        (sfVector2f){144, 272}}, (sfVector2f){-1.f / 16.f * 15, 0});
    block->faces[1] = NULL;
    block->faces[2] = NULL;
    block->faces[3] = NULL;
    block->transparent = true;
    block->solid = true;
    return block;
}

block_t *init_ladder_south(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_right_face((uv_coords_t){(sfVector2f){128, 256},
        (sfVector2f){144, 272}}, (sfVector2f){0, -1.f / 16.f * 15});
    block->faces[1] = NULL;
    block->faces[2] = NULL;
    block->faces[3] = NULL;
    block->transparent = true;
    block->solid = true;
    return block;
}
