/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** create_chunk
*/
#include "rpg.h"
#include "blocks.h"

static char *create_blocks(char chunk_size)
{
    char *array = malloc(sizeof(char) * powf(chunk_size, 3));

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
        for (int y = 0; y < 16; y++) {
            for (int z = 0; z < 16; z++) {
                if (z > 0)
                    new_chunk->blocks[volumetric_to_linear(x, y, z)] = b_air;
                else 
                    new_chunk->blocks[volumetric_to_linear(x, y, z)] = b_grass;
            }
        }
    }
    for (int x = 0; x < 16; x++) {
        for (int y = 0; y < 16; y++) {
            for (int z = 0; z < 16; z++) {
                add_cube(new_chunk->vertices, (vector3uint8_t){x, y, z},
                    new_chunk->blocks);
            }
        }
    }
    return new_chunk;
}