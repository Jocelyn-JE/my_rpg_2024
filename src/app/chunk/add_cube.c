/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** add_cube
*/
#include "rpg.h"
#include "blocks.h"

void add_cube(sfVertexArray *vertices, sfVector3f f_position, char ***blocks, char level_size)
{
    sfVector3i position = {f_position.x, f_position.y, f_position.z};
    int block_id = blocks[position.x][position.y][position.z];
    int size = 100;

    if (block_id == b_air || (!(position.z + 1 > level_size - 1 ||
        position.x + 1 > level_size - 1 ||
        position.y + 1 > level_size - 1) &&
        blocks[position.x + 1][position.y + 1][position.z + 1] != 1))
        return;
    // Top
    if (position.z + 1 > level_size - 1 || blocks[position.x][position.y][position.z + 1] == b_air) {
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(0 + f_position.x, 0 + f_position.y, f_position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 0}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(0 + f_position.x, 1 + f_position.y, f_position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 0}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(1 + f_position.x, 1 + f_position.y, f_position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 16}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(0 + f_position.x, 0 + f_position.y, f_position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 0}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(1 + f_position.x, 0 + f_position.y, f_position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 16}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(1 + f_position.x, 1 + f_position.y, f_position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 16}});
    }
    // Left
    if (position.x + 1 > level_size - 1 || blocks[position.x + 1][position.y][position.z] == b_air) {
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(1 + f_position.x, 0 + f_position.y, f_position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 0 + 16}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(2 + f_position.x, 1 + f_position.y, f_position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 16 + 16}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(1 + f_position.x, 1 + f_position.y, f_position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 0 + 16}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(1 + f_position.x, 1 + f_position.y, f_position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 0 + 16}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(2 + f_position.x, 2 + f_position.y, f_position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 16 + 16}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(2 + f_position.x, 1 + f_position.y, f_position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 16 + 16}});
    }
    // Right
    if (position.y + 1 > level_size - 1 || blocks[position.x][position.y + 1][position.z] == b_air) {
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(1 + f_position.x, 1 + f_position.y, f_position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 0 + 32}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(2 + f_position.x, 2 + f_position.y, f_position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 16 + 32}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(0 + f_position.x, 1 + f_position.y, f_position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 0 + 32}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(0 + f_position.x, 1 + f_position.y, f_position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 0 + 32}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(1 + f_position.x, 2 + f_position.y, f_position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 16 + 32}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(2 + f_position.x, 2 + f_position.y, f_position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 16 + 32}});
    }
}