/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** dandelion
*/
#include "rpg.h"
#include "blocks.h"

sfVertex *get_diagonal_face(uv_coords_t uv, sfVector2f offset, sfColor color)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 7);

    vertices[0] = (sfVertex){(sfVector2f){1 + offset.x, 0 + offset.y}, color,
        uv.top_left};
    vertices[1] = (sfVertex){(sfVector2f){2 + offset.x, 1 + offset.y}, color,
        (sfVector2f){uv.top_left.x, uv.bottom_right.y}};
    vertices[2] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y}, color,
        (sfVector2f){uv.bottom_right.x, uv.top_left.y}};
    vertices[3] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y}, color,
        (sfVector2f){uv.bottom_right.x, uv.top_left.y}};
    vertices[4] = (sfVertex){(sfVector2f){1 + offset.x, 2 + offset.y}, color,
        uv.bottom_right};
    vertices[5] = (sfVertex){(sfVector2f){2 + offset.x, 1 + offset.y}, color,
        (sfVector2f){uv.top_left.x, uv.bottom_right.y}};
    vertices[6] = null_vertex();
    return vertices;
}

block_t *init_dandelion(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_diagonal_face((uv_coords_t){(sfVector2f){160, 32},
        (sfVector2f){176, 48}}, (sfVector2f){0, 0}, sfWhite);
    block->faces[1] = NULL;
    block->faces[2] = NULL;
    block->faces[3] = NULL;
    block->transparent = true;
    block->solid = false;
    return block;
}
