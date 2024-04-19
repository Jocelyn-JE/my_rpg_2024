/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** free_chunk
*/
#include "rpg.h"

static void destroy_level(char ***blocks)
{
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            free(blocks[i][j]);
        }
        free(blocks[i]);
    }
    free(blocks);
}

void destroy_chunk(chunk_t *chunk)
{
    sfTransformable_destroy(chunk->transform);
    sfVertexArray_destroy(chunk->vertices);
    destroy_level(chunk->blocks);
    free(chunk);
}