/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** create_chunk
*/
#include "rpg.h"
#include "blocks.h"
#include <time.h>

static uint8_t *create_blocks(int map_fd)
{
    uint8_t *array = malloc(sizeof(uint8_t) * 8192);

    read(map_fd, array, sizeof(uint8_t) * 8192);
    return array;
}

static void init_chunk(chunk_t *chunk, int map_fd)
{
    chunk->vertices = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(chunk->vertices, sfTriangles);
    chunk->transform = sfTransformable_create();
    chunk->blocks = create_blocks(map_fd);
}

static void add_entities(sfVertexArray *vertices, int index, list_t *entities,
    int chunk_index)
{
    vector3uint8_t pos = get_pos_from_index(index);
    sfVector2i chunk_coords = get_chunk_coordinates_from_index(chunk_index);
    entity_t *data = (entity_t *)entities->data;

    if (pos.z != 2)
        return;
    for (list_t *current = entities; current; current = current->next) {
        data = current->data;
        if ((int)floor(data->pos.x / 16) == chunk_coords.x && (int)floor(
            data->pos.y / 16) == chunk_coords.y && (int)data->pos.x % 16 ==
            pos.x && (int)data->pos.y % 16 == pos.y)
            add_entity(vertices, data);
    }
}

chunk_t *create_chunk(block_t **blocks, int map_fd)
{
    chunk_t *new_chunk = malloc(sizeof(chunk_t));

    init_chunk(new_chunk, map_fd);
    for (int i = 0; i < 8192; i++) {
        if (new_chunk->blocks[i] != b_air)
            add_cube(new_chunk->vertices, i, new_chunk->blocks, blocks);
    }
    new_chunk->bounding_box = sfVertexArray_getBounds(new_chunk->vertices);
    return new_chunk;
}

void update_chunk(chunk_t *chunk, block_t **blocks, list_t *entities,
    int chunk_index)
{
    sfVertexArray_clear(chunk->vertices);
    for (int i = 0; i < 8192; i++) {
        add_entities(chunk->vertices, i, entities, chunk_index);
        if (chunk->blocks[i] != b_air)
            add_cube(chunk->vertices, i, chunk->blocks, blocks);
    }
    chunk->bounding_box = sfVertexArray_getBounds(chunk->vertices);
}
