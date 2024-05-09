/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** water
*/
#include "blocks.h"

sfColor water_blue(void)
{
    return (sfColor){63, 118, 228, 255};
}

static sfVertex *get_water_face(uv_coords_t uv, sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 7);

    vertices[0] = (sfVertex){(sfVector2f){0 + offset.x, 0 + offset.y},
        water_blue(), uv.top_left};
    vertices[1] = (sfVertex){(sfVector2f){1 + offset.x, 0 + offset.y},
        water_blue(), (sfVector2f){uv.bottom_right.x, uv.top_left.y}};
    vertices[2] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y},
        water_blue(), uv.bottom_right};
    vertices[3] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y},
        water_blue(), uv.bottom_right};
    vertices[4] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y},
        water_blue(), (sfVector2f){uv.top_left.x, uv.bottom_right.y}};
    vertices[5] = (sfVertex){(sfVector2f){0 + offset.x, 0 + offset.y},
        water_blue(), uv.top_left};
    vertices[6] = null_vertex();
    return vertices;
}

block_t *init_water(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_water_face((uv_coords_t){(sfVector2f){0, 112},
        (sfVector2f){16, 128}}, (sfVector2f){(1.f / 16.f) * 2,
        (1.f / 16.f) * 2});
    block->faces[1] = NULL;
    block->faces[2] = NULL;
    block->faces[3] = NULL;
    block->transparent = true;
    block->solid = false;
    return block;
}
