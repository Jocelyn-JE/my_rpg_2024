/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** lava
*/
#include "blocks.h"

sfVertex *get_lava_face(uv_coords_t uv, sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 7);

    vertices[0] = (sfVertex){(sfVector2f){0 + offset.x, 0 + offset.y},
        sfWhite, uv.top_left};
    vertices[1] = (sfVertex){(sfVector2f){1 + offset.x, 0 + offset.y},
        sfWhite, (sfVector2f){uv.bottom_right.x, uv.top_left.y}};
    vertices[2] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y},
        sfWhite, uv.bottom_right};
    vertices[3] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y},
        sfWhite, uv.bottom_right};
    vertices[4] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y},
        sfWhite, (sfVector2f){uv.top_left.x, uv.bottom_right.y}};
    vertices[5] = (sfVertex){(sfVector2f){0 + offset.x, 0 + offset.y},
        sfWhite, uv.top_left};
    vertices[6] = null_vertex();
    return vertices;
}

block_t *init_lava(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_lava_face((uv_coords_t){(sfVector2f){160, 144},
        (sfVector2f){176, 160}}, (sfVector2f){(1.f / 16.f) * 2,
        (1.f / 16.f) * 2});
    block->faces[1] = NULL;
    block->faces[2] = NULL;
    block->faces[3] = NULL;
    block->transparent = true;
    block->solid = false;
    return block;
}
