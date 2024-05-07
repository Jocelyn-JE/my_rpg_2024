/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** leaves
*/
#include "blocks.h"

static sfVertex *get_leaf_top_face(sfVector2f text_pos1, sfVector2f text_pos2,
    sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 7);

    vertices[0] = (sfVertex){(sfVector2f){0 + offset.x, 0 + offset.y},
        grass_green(), text_pos1};
    vertices[1] = (sfVertex){(sfVector2f){1 + offset.x, 0 + offset.y},
        grass_green(), (sfVector2f){text_pos2.x, text_pos1.y}};
    vertices[2] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y},
        grass_green(), text_pos2};
    vertices[3] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y},
        grass_green(), text_pos2};
    vertices[4] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y},
        grass_green(), (sfVector2f){text_pos1.x, text_pos2.y}};
    vertices[5] = (sfVertex){(sfVector2f){0 + offset.x, 0 + offset.y},
        grass_green(), text_pos1};
    vertices[6] = null_vertex();
    return vertices;
}

static sfVertex *get_leaf_left_face(sfVector2f text_pos1,
    sfVector2f text_pos2, sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 7);

    vertices[0] = (sfVertex){(sfVector2f){1 + offset.x, 0 + offset.y},
        grass_green(), text_pos1};
    vertices[1] = (sfVertex){(sfVector2f){2 + offset.x, 1 + offset.y},
        grass_green(), (sfVector2f){text_pos1.x, text_pos2.y}};
    vertices[2] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y},
        grass_green(), (sfVector2f){text_pos2.x, text_pos1.y}};
    vertices[3] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y},
        grass_green(), (sfVector2f){text_pos2.x, text_pos1.y}};
    vertices[4] = (sfVertex){(sfVector2f){2 + offset.x, 2 + offset.y},
        grass_green(), text_pos2};
    vertices[5] = (sfVertex){(sfVector2f){2 + offset.x, 1 + offset.y},
        grass_green(), (sfVector2f){text_pos1.x, text_pos2.y}};
    vertices[6] = null_vertex();
    return vertices;
}

static sfVertex *get_leaf_right_face(sfVector2f text_pos1,
    sfVector2f text_pos2, sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 7);

    vertices[0] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y},
        grass_green(), text_pos1};
    vertices[1] = (sfVertex){(sfVector2f){2 + offset.x, 2 + offset.y},
        grass_green(), (sfVector2f){text_pos1.x, text_pos2.y}};
    vertices[2] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y},
        grass_green(), (sfVector2f){text_pos2.x, text_pos1.y}};
    vertices[3] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y},
        grass_green(), (sfVector2f){text_pos2.x, text_pos1.y}};
    vertices[4] = (sfVertex){(sfVector2f){1 + offset.x, 2 + offset.y},
        grass_green(), text_pos2};
    vertices[5] = (sfVertex){(sfVector2f){2 + offset.x, 2 + offset.y},
        grass_green(), (sfVector2f){text_pos1.x, text_pos2.y}};
    vertices[6] = null_vertex();
    return vertices;
}

block_t *init_oak_leaves(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_leaf_top_face((sfVector2f){32, 96},
        (sfVector2f){48, 112}, (sfVector2f){0, 0});
    block->faces[1] = get_leaf_left_face((sfVector2f){32, 96},
        (sfVector2f){48, 112}, (sfVector2f){0, 0});
    block->faces[2] = get_leaf_right_face((sfVector2f){32, 96},
        (sfVector2f){48, 112}, (sfVector2f){0, 0});
    block->faces[3] = NULL;
    block->transparent = true;
    block->solid = true;
    return block;
}

block_t *init_jungle_leaves(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_leaf_top_face((sfVector2f){48, 96},
        (sfVector2f){64, 112}, (sfVector2f){0, 0});
    block->faces[1] = get_leaf_left_face((sfVector2f){48, 96},
        (sfVector2f){64, 112}, (sfVector2f){0, 0});
    block->faces[2] = get_leaf_right_face((sfVector2f){48, 96},
        (sfVector2f){64, 112}, (sfVector2f){0, 0});
    block->faces[3] = NULL;
    block->transparent = true;
    block->solid = true;
    return block;
}

block_t *init_spruce_leaves(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_leaf_top_face((sfVector2f){64, 96},
        (sfVector2f){80, 112}, (sfVector2f){0, 0});
    block->faces[1] = get_leaf_left_face((sfVector2f){64, 96},
        (sfVector2f){80, 112}, (sfVector2f){0, 0});
    block->faces[2] = get_leaf_right_face((sfVector2f){64, 96},
        (sfVector2f){80, 112}, (sfVector2f){0, 0});
    block->faces[3] = NULL;
    block->transparent = true;
    block->solid = true;
    return block;
}
