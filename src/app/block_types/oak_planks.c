/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** oak_planks
*/
#include "blocks.h"

block_t *init_oak_planks(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 3);
    block->faces[0] = get_top_face((sfVector2f){48, 0}, (sfVector2f){64, 16},
        (sfVector2f){0, 0});
    block->faces[1] = get_left_face((sfVector2f){48, 0}, (sfVector2f){64, 16},
        (sfVector2f){0, 0});
    block->faces[2] = get_right_face((sfVector2f){48, 0}, (sfVector2f){64, 16},
        (sfVector2f){0, 0});
    block->transparent = false;
    return block;
}