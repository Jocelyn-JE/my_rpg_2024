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
    uint8_t *array = malloc(sizeof(uint8_t) * (16 * 16 * 32));

    read(map_fd, array, sizeof(uint8_t) * (16 * 16 * 32));
    return array;
}

static void init_chunk(chunk_t *chunk, sfTexture *atlas, int map_fd)
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
    entity_t *data = (entity_t *)entities->data;

    for (list_t *current = entities; current != NULL;
        current = current->next) {
        data = current->data;
        if (floor(data->pos.x) == pos.x && floor(data->pos.y) == pos.y &&
            pos.z == 0)
            add_entity(vertices, index, data);
    }
}

chunk_t *create_chunk(sfTexture *atlas, block_t **blocks, int map_fd)
{
    chunk_t *new_chunk = malloc(sizeof(chunk_t));

    init_chunk(new_chunk, atlas, map_fd);
    for (int i = 0; i < (16 * 16 * 32); i++) {
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
    for (int i = 0; i < (16 * 16 * 32); i++) {
        add_entities(chunk->vertices, i, entities, chunk_index);
        if (chunk->blocks[i] != b_air)
            add_cube(chunk->vertices, i, chunk->blocks, blocks);
    }
    chunk->bounding_box = sfVertexArray_getBounds(chunk->vertices);
}
