/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** create_chunk
*/
#include "rpg.h"
#include "blocks.h"

static uint8_t *create_blocks(uint8_t chunk_size)
{
    uint8_t *array = malloc(sizeof(uint8_t) * powf(chunk_size, 3));

    memset(array, b_air, (size_t)powf(chunk_size, 3));
    return array;
}

static void init_chunk(chunk_t *chunk, sfTexture *atlas)
{
    chunk->vertices = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(chunk->vertices, sfTriangles);
    chunk->renderstate = sfRenderStates_default();
    chunk->transform = sfTransformable_create();
    chunk->renderstate.texture = atlas;
    chunk->renderstate.transform =
        sfTransformable_getTransform(chunk->transform);
    chunk->blocks = create_blocks(16);
}

chunk_t *create_chunk(sfTexture *atlas)
{
    chunk_t *new_chunk = malloc(sizeof(chunk_t));

    init_chunk(new_chunk, atlas);
    for (int x = 0; x < 16; x++) {
        for (int y = 0; y < 16; y++)
            new_chunk->blocks[get_index_from_pos(x, y, 0)] = b_grass;
    }
    for (int i = 0; i < powf(16, 3); i++) {
        add_cube(new_chunk->vertices, get_pos_from_index(i),
            new_chunk->blocks);
    }
    return new_chunk;
}
