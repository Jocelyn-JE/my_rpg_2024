/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** create_chunk
*/
#include "rpg.h"
#include "blocks.h"

static char ***create_blocks(char chunk_size)
{
    char ***array = malloc(sizeof(char **) * chunk_size);

    for (int x = 0; x != chunk_size; x++) {
        array[x] = malloc(sizeof(char *) * chunk_size);
        for (int y = 0; y != chunk_size; y++)
            array[x][y] = malloc(sizeof(char) * chunk_size);
    }
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

void create_chunk(chunk_t *chunk, sfTexture *atlas)
{
    init_chunk(chunk, atlas);
    for (int x = 0; x < 16; x++) {
        for (int y = 0; y < 16; y++) {
            for (int z = 0; z < 16; z++) {
                if (z > 0)
                    chunk->blocks[x][y][z] = b_air;
                else 
                    chunk->blocks[x][y][z] = b_grass;
            }
        }
    }
    for (int y = 0; y < 16; y++) {
        for (int x = 0; x < 16; x++) {
            for (int z = 0; z < 16; z++)
                add_cube(chunk->vertices, (sfVector3f){x, y, z}, chunk->blocks,
                    16);
        }
    }
}