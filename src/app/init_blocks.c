/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** init_blocks
*/
#include "blocks.h"
#include "rpg.h"

// static void add_top_face(sfVertexArray *vertices, sfVector2f)
// {
//     sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(0, 0, 0, 100), sfWhite,
//         (sfVector2f){0, 0}});
//     sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(1, 0, 0, 100), sfWhite,
//         (sfVector2f){16, 0}});
//     sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(1, 1, 0, 100), sfWhite,
//         (sfVector2f){16, 16}});
//     sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(1, 1, 0, 100), sfWhite,
//         (sfVector2f){16, 16}});
//     sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(0, 1, 0, 100), sfWhite,
//         (sfVector2f){0, 16}});
//     sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(0, 0, 0, 100), sfWhite,
//         (sfVector2f){0, 0}});
// }

// static void add_left_face(sfVertexArray *vertices)
// {
//     sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(1, 0, 0, 100), sfWhite,
//         (sfVector2f){0, 0}});
//     sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(2, 1, 0, 100), sfWhite,
//         (sfVector2f){0, 16}});
//     sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(1, 1, 0, 100), sfWhite,
//         (sfVector2f){16, 0}});
//     sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(1, 1, 0, 100), sfWhite,
//         (sfVector2f){16, 0}});
//     sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(2, 2, 0, 100), sfWhite,
//         (sfVector2f){16, 16}});
//     sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(2, 1, 0, 100), sfWhite,
//         (sfVector2f){0, 16}});
// }

// static void add_right_face(sfVertexArray *vertices)
// {
//     sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(1, 1, 0, 100), sfWhite,
//         (sfVector2f){0, 0}});
//     sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(2, 2, 0, 100), sfWhite,
//         (sfVector2f){0, 16}});
//     sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(0, 1, 0, 100), sfWhite,
//         (sfVector2f){16, 0}});
//     sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(0, 1, 0, 100), sfWhite,
//         (sfVector2f){16, 0}});
//     sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(1, 2, 0, 100), sfWhite,
//         (sfVector2f){16, 16}});
//     sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(2, 2, 0, 100), sfWhite,
//         (sfVector2f){0, 16}});
// }

block_t *init_null(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->transparent = false;
    return block;
}

block_t *init_stone(void)
{
    block_t *block = malloc(sizeof(block_t));

    return block;
}

block_t **init_blocks(void)
{
    block_t **blocks = malloc(sizeof(block_t) * (9 + 1));

    blocks[0] = init_null();
    blocks[10] = NULL;
    return blocks;
}
