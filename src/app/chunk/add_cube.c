/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** add_cube
*/
#include "rpg.h"
#include "blocks.h"

static void add_top_face(sfVertexArray *vertices, vector3uint8_t pos,
    int block_id, int size)
{
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(0 +
        pos.x, 0 + pos.y, pos.z, size), sfWhite,
        (sfVector2f){0 + (block_id * 16), 0}});
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(1 +
        pos.x, 0 + pos.y, pos.z, size), sfWhite,
        (sfVector2f){16 + (block_id * 16), 0}});
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(1 +
        pos.x, 1 + pos.y, pos.z, size), sfWhite,
        (sfVector2f){16 + (block_id * 16), 16}});
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(1 +
        pos.x, 1 + pos.y, pos.z, size), sfWhite,
        (sfVector2f){16 + (block_id * 16), 16}});
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(0 +
        pos.x, 1 + pos.y, pos.z, size), sfWhite,
        (sfVector2f){0 + (block_id * 16), 16}});
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(0 +
        pos.x, 0 + pos.y, pos.z, size), sfWhite,
        (sfVector2f){0 + (block_id * 16), 0}});
}

static void add_left_face(sfVertexArray *vertices, vector3uint8_t pos,
    int block_id, int size)
{
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(1 +
        pos.x, 0 + pos.y, pos.z, size), sfWhite,
        (sfVector2f){0 + (block_id * 16), 0 + 16}});
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(2 +
        pos.x, 1 + pos.y, pos.z, size), sfWhite,
        (sfVector2f){0 + (block_id * 16), 16 + 16}});
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(1 +
        pos.x, 1 + pos.y, pos.z, size), sfWhite,
        (sfVector2f){16 + (block_id * 16), 0 + 16}});
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(1 +
        pos.x, 1 + pos.y, pos.z, size), sfWhite,
        (sfVector2f){16 + (block_id * 16), 0 + 16}});
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(2 +
        pos.x, 2 + pos.y, pos.z, size), sfWhite,
        (sfVector2f){16 + (block_id * 16), 16 + 16}});
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(2 +
        pos.x, 1 + pos.y, pos.z, size), sfWhite,
        (sfVector2f){0 + (block_id * 16), 16 + 16}});
}

static void add_right_face(sfVertexArray *vertices, vector3uint8_t pos,
    int block_id, int size)
{
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(1 +
        pos.x, 1 + pos.y, pos.z, size), sfWhite,
        (sfVector2f){0 + (block_id * 16), 0 + 32}});
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(2 +
        pos.x, 2 + pos.y, pos.z, size), sfWhite,
        (sfVector2f){0 + (block_id * 16), 16 + 32}});
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(0 +
        pos.x, 1 + pos.y, pos.z, size), sfWhite,
        (sfVector2f){16 + (block_id * 16), 0 + 32}});
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(0 +
        pos.x, 1 + pos.y, pos.z, size), sfWhite,
        (sfVector2f){16 + (block_id * 16), 0 + 32}});
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(1 +
        pos.x, 2 + pos.y, pos.z, size), sfWhite,
        (sfVector2f){16 + (block_id * 16), 16 + 32}});
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(2 +
        pos.x, 2 + pos.y, pos.z, size), sfWhite,
        (sfVector2f){0 + (block_id * 16), 16 + 32}});
}

void add_cube(sfVertexArray *vertices, int index, uint8_t *blocks)
{
    vector3uint8_t pos = get_pos_from_index(index);
    int block_id = blocks[index];
    int size = 100;

    if ((!(pos.z + 1 > 15 || pos.x + 1 > 15 || pos.y + 1 > 15) &&
        blocks[get_index_from_pos(pos.x + 1, pos.y + 1, pos.z + 1)] != 1))
        return;
    if (pos.z + 1 > 15 || blocks[get_index_from_pos(pos.x,
        pos.y, pos.z + 1)] == b_air)
        add_top_face(vertices, pos, block_id, size);
    if (pos.x + 1 > 15 || blocks[get_index_from_pos(pos.x + 1,
        pos.y, pos.z)] == b_air)
        add_left_face(vertices, pos, block_id, size);
    if (pos.y + 1 > 15 || blocks[get_index_from_pos(pos.x,
        pos.y + 1, pos.z)] == b_air)
        add_right_face(vertices, pos, block_id, size);
}
