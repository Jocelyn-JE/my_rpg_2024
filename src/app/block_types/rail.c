/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** rail
*/
#include "blocks.h"

block_t *init_ew_rail(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_top_face_rot((uv_coords_t){(sfVector2f){112, 256},
        (sfVector2f){128, 272}}, (sfVector2f){1.f / 16.f * 15, 1.f / 16.f *
        15});
    block->faces[1] = NULL;
    block->faces[2] = NULL;
    block->faces[3] = NULL;
    block->transparent = true;
    block->solid = true;
    return block;
}

block_t *init_ns_rail(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_top_face((uv_coords_t){(sfVector2f){112, 256},
        (sfVector2f){128, 272}}, (sfVector2f){1.f / 16.f * 15, 1.f / 16.f *
        15});
    block->faces[1] = NULL;
    block->faces[2] = NULL;
    block->faces[3] = NULL;
    block->transparent = true;
    block->solid = true;
    return block;
}

static sfVertex *get_right_diag_face_rot(uv_coords_t uv,
    sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 7);

    vertices[0] = (sfVertex){(sfVector2f){0 + offset.x, 0 + offset.y}, sfWhite,
        (sfVector2f){uv.top_left.x, uv.top_left.y}};
    vertices[1] = (sfVertex){(sfVector2f){2 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){uv.top_left.x, uv.bottom_right.y}};
    vertices[2] = (sfVertex){(sfVector2f){2 + offset.x, 2 + offset.y}, sfWhite,
        (sfVector2f){uv.bottom_right.x, uv.bottom_right.y}};
    vertices[3] = (sfVertex){(sfVector2f){2 + offset.x, 2 + offset.y}, sfWhite,
        (sfVector2f){uv.bottom_right.x, uv.bottom_right.y}};
    vertices[4] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){uv.bottom_right.x, uv.top_left.y}};
    vertices[5] = (sfVertex){(sfVector2f){0 + offset.x, 0 + offset.y}, sfWhite,
        (sfVector2f){uv.top_left.x, uv.top_left.y}};
    vertices[6] = null_vertex();
    return vertices;
}

static sfVertex *get_left_diag_face_rot(uv_coords_t uv,
    sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 7);

    vertices[0] = (sfVertex){(sfVector2f){0 + offset.x, 0 + offset.y}, sfWhite,
        (sfVector2f){uv.top_left.x, uv.top_left.y}};
    vertices[1] = (sfVertex){(sfVector2f){1 + offset.x, 2 + offset.y}, sfWhite,
        (sfVector2f){uv.top_left.x, uv.bottom_right.y}};
    vertices[2] = (sfVertex){(sfVector2f){2 + offset.x, 2 + offset.y}, sfWhite,
        (sfVector2f){uv.bottom_right.x, uv.bottom_right.y}};
    vertices[3] = (sfVertex){(sfVector2f){2 + offset.x, 2 + offset.y}, sfWhite,
        (sfVector2f){uv.bottom_right.x, uv.bottom_right.y}};
    vertices[4] = (sfVertex){(sfVector2f){1 + offset.x, 0 + offset.y}, sfWhite,
        (sfVector2f){uv.bottom_right.x, uv.top_left.y}};
    vertices[5] = (sfVertex){(sfVector2f){0 + offset.x, 0 + offset.y}, sfWhite,
        (sfVector2f){uv.top_left.x, uv.top_left.y}};
    vertices[6] = null_vertex();
    return vertices;
}

block_t *init_aw_rail(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_right_diag_face_rot((uv_coords_t){(sfVector2f){112,
        256}, (sfVector2f){128, 272}}, (sfVector2f){-1.f / 16.f, -1.f / 16.f});
    block->faces[1] = NULL;
    block->faces[2] = NULL;
    block->faces[3] = NULL;
    block->transparent = true;
    block->solid = true;
    return block;
}

block_t *init_an_rail(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_left_diag_face_rot((uv_coords_t){(sfVector2f){112,
        256}, (sfVector2f){128, 272}}, (sfVector2f){-1.f / 16.f, -1.f / 16.f});
    block->faces[1] = NULL;
    block->faces[2] = NULL;
    block->faces[3] = NULL;
    block->transparent = true;
    block->solid = true;
    return block;
}
