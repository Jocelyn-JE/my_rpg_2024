/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** get_block
*/
#include "rpg.h"

static sfVector2i get_block_chunk_coords(sfVector2i pos)
{
    return (sfVector2i){pos.x % 16, pos.y % 16};
}

block_t *get_block(sfVector2i coords, block_t **block_types, chunk_t **map,
    int z)
{
    sfVector2i chunk_coords = get_block_chunk_coords(coords);

    return block_types[map[get_chunk_index_from_coordinates(coords.x / 16,
        coords.y / 16)]->blocks[get_index_from_pos(chunk_coords.x,
        chunk_coords.y, z)]];
}
