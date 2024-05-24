/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** snow
*/
#include "blocks.h"

static sfVertex *get_snow_left_face(uv_coords_t uv, sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 7);

    vertices[0] = (sfVertex){(sfVector2f){1 + offset.x, 0 + offset.y}, sfWhite,
        uv.top_left};
    vertices[1] = (sfVertex){(sfVector2f){2, 1}, sfWhite,
        (sfVector2f){uv.top_left.x, uv.bottom_right.y}};
    vertices[2] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){uv.bottom_right.x, uv.top_left.y}};
    vertices[3] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){uv.bottom_right.x, uv.top_left.y}};
    vertices[4] = (sfVertex){(sfVector2f){2, 2}, sfWhite,
        uv.bottom_right};
    vertices[5] = (sfVertex){(sfVector2f){2, 1}, sfWhite,
        (sfVector2f){uv.top_left.x, uv.bottom_right.y}};
    vertices[6] = null_vertex();
    return vertices;
}

static sfVertex *get_snow_right_face(uv_coords_t uv, sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 7);

    vertices[0] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        uv.top_left};
    vertices[1] = (sfVertex){(sfVector2f){2, 2}, sfWhite,
        (sfVector2f){uv.top_left.x, uv.bottom_right.y}};
    vertices[2] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y},
        sfWhite, (sfVector2f){uv.bottom_right.x, uv.top_left.y}};
    vertices[3] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){uv.bottom_right.x, uv.top_left.y}};
    vertices[4] = (sfVertex){(sfVector2f){1, 2}, sfWhite,
        uv.bottom_right};
    vertices[5] = (sfVertex){(sfVector2f){2, 2}, sfWhite,
        (sfVector2f){uv.top_left.x, uv.bottom_right.y}};
    vertices[6] = null_vertex();
    return vertices;
}

block_t *init_snow(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_top_face((uv_coords_t){(sfVector2f){80, 64},
        (sfVector2f){96, 80}}, (sfVector2f){14.f / 16.f, 14.f / 16.f});
    block->faces[1] = get_snow_left_face((uv_coords_t){(sfVector2f){80, 64},
        (sfVector2f){96, 66}}, (sfVector2f){14.f / 16.f, 14.f / 16.f});
    block->faces[2] = get_snow_right_face((uv_coords_t){(sfVector2f){80, 64},
        (sfVector2f){96, 66}}, (sfVector2f){14.f / 16.f, 14.f / 16.f});
    block->faces[3] = NULL;
    block->transparent = true;
    block->solid = false;
    return block;
}
