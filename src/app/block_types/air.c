/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** air
*/
#include "blocks.h"

block_t *init_null(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_top_face((sfVector2f){0, 0}, (sfVector2f){16, 16},
        (sfVector2f){0, 0});
    block->faces[1] = get_left_face((sfVector2f){0, 0}, (sfVector2f){16, 16},
        (sfVector2f){0, 0});
    block->faces[2] = get_right_face((sfVector2f){0, 0}, (sfVector2f){16, 16},
        (sfVector2f){0, 0});
    block->faces[3] = NULL;
    block->transparent = false;
    block->solid = true;
    return block;
}

block_t *init_air(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = NULL;
    block->transparent = true;
    block->solid = false;
    return block;
}
