/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** fern
*/
#include "rpg.h"
#include "blocks.h"

block_t *init_fern(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_diagonal_face((uv_coords_t){(sfVector2f){112, 32},
        (sfVector2f){128, 48}}, (sfVector2f){0, 0}, grass_green());
    block->faces[1] = NULL;
    block->faces[2] = NULL;
    block->faces[3] = NULL;
    block->transparent = true;
    block->solid = false;
    return block;
}

block_t *init_large_fern_bottom(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_diagonal_face((uv_coords_t){(sfVector2f){112, 16},
        (sfVector2f){128, 32}}, (sfVector2f){0, 0}, grass_green());
    block->faces[1] = NULL;
    block->faces[2] = NULL;
    block->faces[3] = NULL;
    block->transparent = true;
    block->solid = false;
    return block;
}

block_t *init_large_fern_top(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_diagonal_face((uv_coords_t){(sfVector2f){112, 0},
        (sfVector2f){128, 16}}, (sfVector2f){0, 0}, grass_green());
    block->faces[1] = NULL;
    block->faces[2] = NULL;
    block->faces[3] = NULL;
    block->transparent = true;
    block->solid = false;
    return block;
}
