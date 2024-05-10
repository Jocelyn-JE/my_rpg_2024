/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** grass_block
*/
#include "blocks.h"

static sfVertex *get_grass_top_face(uv_coords_t uv,
    sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 7);

    vertices[0] = (sfVertex){(sfVector2f){0 + offset.x, 0 + offset.y},
        grass_green(), uv.top_left};
    vertices[1] = (sfVertex){(sfVector2f){1 + offset.x, 0 + offset.y},
        grass_green(), (sfVector2f){uv.bottom_right.x, uv.top_left.y}};
    vertices[2] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y},
        grass_green(), uv.bottom_right};
    vertices[3] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y},
        grass_green(), uv.bottom_right};
    vertices[4] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y},
        grass_green(), (sfVector2f){uv.top_left.x, uv.bottom_right.y}};
    vertices[5] = (sfVertex){(sfVector2f){0 + offset.x, 0 + offset.y},
        grass_green(), uv.top_left};
    vertices[6] = null_vertex();
    return vertices;
}

static sfVertex *get_grass_left_face(uv_coords_t uv, sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 13);

    vertices[0] = null_vertex();
    cat_vertex_array(vertices, get_left_face((uv_coords_t){(sfVector2f){16,
        32}, (sfVector2f){32, 48}}, (sfVector2f){0, 0}));
    vertices[6] = (sfVertex){(sfVector2f){1 + offset.x, 0 + offset.y},
        grass_green(), uv.top_left};
    vertices[7] = (sfVertex){(sfVector2f){2 + offset.x, 1 + offset.y},
        grass_green(), (sfVector2f){uv.top_left.x, uv.bottom_right.y}};
    vertices[8] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y},
        grass_green(), (sfVector2f){uv.bottom_right.x, uv.top_left.y}};
    vertices[9] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y},
        grass_green(), (sfVector2f){uv.bottom_right.x, uv.top_left.y}};
    vertices[10] = (sfVertex){(sfVector2f){2 + offset.x, 2 + offset.y},
        grass_green(), uv.bottom_right};
    vertices[11] = (sfVertex){(sfVector2f){2 + offset.x, 1 + offset.y},
        grass_green(), (sfVector2f){uv.top_left.x, uv.bottom_right.y}};
    vertices[12] = null_vertex();
    return vertices;
}

static sfVertex *get_grass_right_face(uv_coords_t uv, sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 13);

    vertices[0] = null_vertex();
    cat_vertex_array(vertices, get_right_face((uv_coords_t){(sfVector2f){16,
        32}, (sfVector2f){32, 48}}, (sfVector2f){0, 0}));
    vertices[6] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y},
        grass_green(), uv.top_left};
    vertices[7] = (sfVertex){(sfVector2f){2 + offset.x, 2 + offset.y},
        grass_green(), (sfVector2f){uv.top_left.x, uv.bottom_right.y}};
    vertices[8] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y},
        grass_green(), (sfVector2f){uv.bottom_right.x, uv.top_left.y}};
    vertices[9] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y},
        grass_green(), (sfVector2f){uv.bottom_right.x, uv.top_left.y}};
    vertices[10] = (sfVertex){(sfVector2f){1 + offset.x, 2 + offset.y},
        grass_green(), uv.bottom_right};
    vertices[11] = (sfVertex){(sfVector2f){2 + offset.x, 2 + offset.y},
        grass_green(), (sfVector2f){uv.top_left.x, uv.bottom_right.y}};
    vertices[12] = null_vertex();
    return vertices;
}

block_t *init_grass_block(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_grass_top_face((uv_coords_t){(sfVector2f){16, 16},
        (sfVector2f){32, 32}}, (sfVector2f){0, 0});
    block->faces[1] = get_grass_left_face((uv_coords_t){(sfVector2f){160, 176},
        (sfVector2f){176, 192}}, (sfVector2f){0, 0});
    block->faces[2] = get_grass_right_face((uv_coords_t){(sfVector2f){160,
        176}, (sfVector2f){176, 192}}, (sfVector2f){0, 0});
    block->faces[3] = NULL;
    block->transparent = false;
    block->solid = true;
    return block;
}

block_t *init_snowy_grass_block(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_grass_top_face((uv_coords_t){(sfVector2f){16, 16},
        (sfVector2f){32, 32}}, (sfVector2f){0, 0});
    block->faces[1] = get_left_face((uv_coords_t){(sfVector2f){64, 64},
        (sfVector2f){80, 80}}, (sfVector2f){0, 0});
    block->faces[2] = get_right_face((uv_coords_t){(sfVector2f){64, 64},
        (sfVector2f){80, 80}}, (sfVector2f){0, 0});
    block->faces[3] = NULL;
    block->transparent = false;
    block->solid = true;
    return block;
}

block_t *init_podzol(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_top_face((uv_coords_t){(sfVector2f){16, 208},
        (sfVector2f){32, 224}}, (sfVector2f){0, 0});
    block->faces[1] = get_left_face((uv_coords_t){(sfVector2f){32, 208},
        (sfVector2f){48, 224}}, (sfVector2f){0, 0});
    block->faces[2] = get_right_face((uv_coords_t){(sfVector2f){32, 208},
        (sfVector2f){48, 224}}, (sfVector2f){0, 0});
    block->faces[3] = NULL;
    block->transparent = false;
    block->solid = true;
    return block;
}
