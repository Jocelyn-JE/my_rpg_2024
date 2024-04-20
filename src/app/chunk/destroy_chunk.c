/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** free_chunk
*/
#include "rpg.h"

void destroy_chunk(chunk_t *chunk)
{
    sfTransformable_destroy(chunk->transform);
    sfVertexArray_destroy(chunk->vertices);
    free(chunk->blocks);
    free(chunk);
}