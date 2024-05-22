/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** stripped_oak_wood
*/
#include "blocks.h"

block_t *init_y_stripped_oak_wood(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_top_face((uv_coords_t){(sfVector2f){32, 48},
        (sfVector2f){48, 64}}, (sfVector2f){0, 0});
    block->faces[1] = get_left_face((uv_coords_t){(sfVector2f){32, 48},
        (sfVector2f){48, 64}}, (sfVector2f){0, 0});
    block->faces[2] = get_right_face((uv_coords_t){(sfVector2f){32, 48},
        (sfVector2f){48, 64}}, (sfVector2f){0, 0});
    block->faces[3] = NULL;
    block->transparent = false;
    block->solid = true;
    return block;
}

block_t *init_x_stripped_oak_wood(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_top_face_rot((uv_coords_t){(sfVector2f){32, 48},
        (sfVector2f){48, 64}}, (sfVector2f){0, 0});
    block->faces[1] = get_left_face((uv_coords_t){(sfVector2f){32, 48},
        (sfVector2f){48, 64}}, (sfVector2f){0, 0});
    block->faces[2] = get_right_face_rot((uv_coords_t){(sfVector2f){32, 48},
        (sfVector2f){48, 64}}, (sfVector2f){0, 0});
    block->faces[3] = NULL;
    block->transparent = false;
    block->solid = true;
    return block;
}

block_t *init_z_stripped_oak_wood(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_top_face((uv_coords_t){(sfVector2f){32, 48},
        (sfVector2f){48, 64}}, (sfVector2f){0, 0});
    block->faces[1] = get_left_face((uv_coords_t){(sfVector2f){32, 48},
        (sfVector2f){48, 64}}, (sfVector2f){0, 0});
    block->faces[2] = get_right_face((uv_coords_t){(sfVector2f){32, 48},
        (sfVector2f){48, 64}}, (sfVector2f){0, 0});
    block->faces[3] = NULL;
    block->transparent = false;
    block->solid = true;
    return block;
}
