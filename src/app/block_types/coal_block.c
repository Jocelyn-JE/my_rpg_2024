/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** coal_block
*/
#include "blocks.h"

block_t *init_coal_block(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_top_face((uv_coords_t){(sfVector2f){64, 240},
        (sfVector2f){80, 256}}, (sfVector2f){0, 0});
    block->faces[1] = get_left_face((uv_coords_t){(sfVector2f){64, 240},
        (sfVector2f){80, 256}}, (sfVector2f){0, 0});
    block->faces[2] = get_right_face((uv_coords_t){(sfVector2f){64, 240},
        (sfVector2f){80, 256}}, (sfVector2f){0, 0});
    block->faces[3] = NULL;
    block->transparent = false;
    block->solid = true;
    return block;
}
