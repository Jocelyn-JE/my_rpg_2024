/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** create_chunk
*/
#include "rpg.h"
#include "blocks.h"

static uint8_t *create_blocks(int map_fd)
{
    uint8_t *array = malloc(sizeof(uint8_t) * powf(16, 3));

    read(map_fd, array, sizeof(uint8_t) * powf(16, 3));
    return array;
}

static void init_chunk(chunk_t *chunk, sfTexture *atlas, int map_fd)
{
    chunk->vertices = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(chunk->vertices, sfTriangles);
    chunk->transform = sfTransformable_create();
    chunk->blocks = create_blocks(map_fd);
}

chunk_t *create_chunk(sfTexture *atlas, int map_fd)
{
    chunk_t *new_chunk = malloc(sizeof(chunk_t));

    init_chunk(new_chunk, atlas, map_fd);
    for (int i = 0; i < powf(16, 3); i++) {
        if (new_chunk->blocks[i] != b_air)
            add_cube(new_chunk->vertices, i, new_chunk->blocks);
    }
    new_chunk->bounding_box = sfVertexArray_getBounds(new_chunk->vertices);
    return new_chunk;
}
