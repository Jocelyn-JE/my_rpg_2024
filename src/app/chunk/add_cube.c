/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** add_cube
*/
#include "rpg.h"
#include "blocks.h"

static void add_top_face(sfVertexArray *vertices, vector3uint8_t position,
    int block_id, int size)
{
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(0 + position.x, 0 + position.y, position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 0}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(1 + position.x, 0 + position.y, position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 0}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(1 + position.x, 1 + position.y, position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 16}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(1 + position.x, 1 + position.y, position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 16}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(0 + position.x, 1 + position.y, position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 16}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(0 + position.x, 0 + position.y, position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 0}});
}

static void add_left_face(sfVertexArray *vertices, vector3uint8_t position,
    int block_id, int size)
{
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(1 + position.x, 0 + position.y, position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 0 + 16}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(2 + position.x, 1 + position.y, position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 16 + 16}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(1 + position.x, 1 + position.y, position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 0 + 16}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(1 + position.x, 1 + position.y, position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 0 + 16}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(2 + position.x, 2 + position.y, position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 16 + 16}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(2 + position.x, 1 + position.y, position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 16 + 16}});
}

static void add_right_face(sfVertexArray *vertices, vector3uint8_t position,
    int block_id, int size)
{
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(1 + position.x, 1 + position.y, position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 0 + 32}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(2 + position.x, 2 + position.y, position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 16 + 32}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(0 + position.x, 1 + position.y, position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 0 + 32}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(0 + position.x, 1 + position.y, position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 0 + 32}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(1 + position.x, 2 + position.y, position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 16 + 32}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(2 + position.x, 2 + position.y, position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 16 + 32}});
}

void add_cube(sfVertexArray *vertices, vector3uint8_t position, uint8_t *blocks)
{
    int block_id = blocks[volumetric_to_linear(position.x, position.y, position.z)];
    int size = 100;

    if (block_id == b_air || (!(position.z + 1 > 16 - 1 ||
        position.x + 1 > 16 - 1 ||
        position.y + 1 > 16 - 1) &&
        blocks[volumetric_to_linear(position.x + 1, position.y + 1, position.z + 1)] != 1))
        return;
    // Top
    if (position.z + 1 > 16 - 1 || blocks[volumetric_to_linear(position.x, position.y, position.z + 1)] == b_air) {
        add_top_face(vertices, position, block_id, size);
    }
    // Left
    if (position.x + 1 > 16 - 1 || blocks[volumetric_to_linear(position.x + 1, position.y, position.z)] == b_air) {
        add_left_face(vertices, position, block_id, size);
    }
    // Right
    if (position.y + 1 > 16 - 1 || blocks[volumetric_to_linear(position.x, position.y + 1, position.z)] == b_air) {
        add_right_face(vertices, position, block_id, size);
    }
}