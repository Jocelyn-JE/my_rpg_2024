/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** add_cube
*/
#include "rpg.h"
#include "blocks.h"
#include <time.h>
#include <math.h>

static void add_face(sfVertexArray *vertices, vector3uint8_t pos,
    sfVertex *face, float shading_factor)
{
    if (!face)
        return;
    for (int i = 0; !is_null_vertex(face[i]); i++) {
        sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(
            face[i].position.x + pos.x, face[i].position.y + pos.y, pos.z,
            100), (sfColor){face[i].color.r * shading_factor,
            face[i].color.g * shading_factor,
            face[i].color.b * shading_factor, face[i].color.a},
            face[i].texCoords});
    }
}

static bool is_cullable(block_t *current_block, block_t **block_types)
{
    if (current_block == block_types[b_water])
        return false;
    return true;
}

void add_cube(sfVertexArray *vertices, int index, uint8_t *blocks,
    block_t **block_types)
{
    vector3uint8_t pos = get_pos_from_index(index);
    block_t *current_block = block_types[blocks[index]];

    if ((!(pos.z + 1 > 15 || pos.x + 1 > 15 || pos.y + 1 > 15) &&
        !block_types[blocks[get_idx_from_pos(pos.x + 1, pos.y + 1, pos.z +
        1)]]->transparent))
        return;
    if (pos.z + 1 > 15 || block_types[blocks[get_idx_from_pos(pos.x, pos.y,
        pos.z + 1)]]->transparent || !is_cullable(current_block, block_types))
        add_face(vertices, pos, current_block->faces[0], 1);
    if (pos.x + 1 > 15 || block_types[blocks[get_idx_from_pos(pos.x + 1, pos.y,
        pos.z)]]->transparent || !is_cullable(current_block, block_types))
        add_face(vertices, pos, current_block->faces[1], 0.6);
    if (pos.y + 1 > 15 || block_types[blocks[get_idx_from_pos(pos.x, pos.y + 1,
        pos.z)]]->transparent || !is_cullable(current_block, block_types))
        add_face(vertices, pos, current_block->faces[2], 0.8);
}
