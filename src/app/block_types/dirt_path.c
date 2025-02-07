/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** dirt_path
*/
#include "blocks.h"

block_t *init_dirt_path(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_top_face((uv_coords_t){(sfVector2f){80, 16},
        (sfVector2f){96, 32}}, (sfVector2f){1.f / 16.f, 1.f / 16.f});
    block->faces[1] = get_left_face((uv_coords_t){(sfVector2f){80, 32},
        (sfVector2f){96, 48}}, (sfVector2f){0, 0});
    block->faces[2] = get_right_face((uv_coords_t){(sfVector2f){80, 32},
        (sfVector2f){96, 48}}, (sfVector2f){0, 0});
    block->faces[3] = NULL;
    block->transparent = true;
    block->solid = true;
    return block;
}
