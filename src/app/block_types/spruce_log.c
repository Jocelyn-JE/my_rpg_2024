/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** logs
*/
#include "blocks.h"

block_t *init_y_spruce_log(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_top_face((sfVector2f){96, 96},
        (sfVector2f){112, 112}, (sfVector2f){0, 0});
    block->faces[1] = get_left_face((sfVector2f){80, 96},
        (sfVector2f){96, 112}, (sfVector2f){0, 0});
    block->faces[2] = get_right_face((sfVector2f){80, 96},
        (sfVector2f){96, 112}, (sfVector2f){0, 0});
    block->faces[3] = NULL;
    block->transparent = false;
    block->solid = true;
    return block;
}

block_t *init_x_spruce_log(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_top_face_rot((sfVector2f){80, 96},
        (sfVector2f){96, 112}, (sfVector2f){0, 0});
    block->faces[1] = get_left_face((sfVector2f){96, 96},
        (sfVector2f){112, 112}, (sfVector2f){0, 0});
    block->faces[2] = get_right_face_rot((sfVector2f){80, 96},
        (sfVector2f){96, 112}, (sfVector2f){0, 0});
    block->faces[3] = NULL;
    block->transparent = false;
    block->solid = true;
    return block;
}

block_t *init_z_spruce_log(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_top_face((sfVector2f){80, 96},
        (sfVector2f){96, 112}, (sfVector2f){0, 0});
    block->faces[1] = get_left_face_rot((sfVector2f){80, 96},
        (sfVector2f){96, 112}, (sfVector2f){0, 0});
    block->faces[2] = get_right_face((sfVector2f){96, 96},
        (sfVector2f){112, 112}, (sfVector2f){0, 0});
    block->faces[3] = NULL;
    block->transparent = false;
    block->solid = true;
    return block;
}
