/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** beetroots
*/
#include "blocks.h"

block_t *init_beetroots(void)
{
    block_t *block = malloc(sizeof(block_t));
    sfVector2f text_pos1 = {144, 224};
    sfVector2f text_pos2 = {160, 240};

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_wheat_vertex((uv_coords_t){text_pos1, text_pos2});
    block->faces[1] = NULL;
    block->faces[2] = NULL;
    block->faces[3] = NULL;
    block->transparent = true;
    block->solid = false;
    return block;
}
