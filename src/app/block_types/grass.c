/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** grass
*/
#include "rpg.h"
#include "blocks.h"

sfColor grass_green(void)
{
    return (sfColor){145, 189, 89, 255};
}

block_t *init_grass(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_diagonal_face((uv_coords_t){(sfVector2f){128, 32},
        (sfVector2f){144, 48}}, (sfVector2f){0, 0}, grass_green());
    block->faces[1] = NULL;
    block->faces[2] = NULL;
    block->faces[3] = NULL;
    block->transparent = true;
    block->solid = false;
    return block;
}

block_t *init_tall_grass_bottom(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_diagonal_face((uv_coords_t){(sfVector2f){128, 16},
        (sfVector2f){144, 32}}, (sfVector2f){0, 0}, grass_green());
    block->faces[1] = NULL;
    block->faces[2] = NULL;
    block->faces[3] = NULL;
    block->transparent = true;
    block->solid = false;
    return block;
}

block_t *init_tall_grass_top(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_diagonal_face((uv_coords_t){(sfVector2f){128, 0},
        (sfVector2f){144, 16}}, (sfVector2f){0, 0}, grass_green());
    block->faces[1] = NULL;
    block->faces[2] = NULL;
    block->faces[3] = NULL;
    block->transparent = true;
    block->solid = false;
    return block;
}
