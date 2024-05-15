/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** add_entity
*/
#include "rpg.h"

sfVector2f get_entity_chunk_coords(entity_t *entity)
{
    sfVector2f mod = {16.f, 16.f};
    sfVector2f pos = {modff(entity->pos.x, &mod.x) + (int)mod.x % 16,
        modff(entity->pos.y, &mod.y) + (int)mod.y % 16};

    return pos;
}

void add_entity(sfVertexArray *vertices, int index, entity_t *entity)
{
    sfVector2f pos = get_entity_chunk_coords(entity);

    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(1 +
        pos.x, 0 + pos.y, 5, 100), sfWhite, (sfVector2f){274, 0}});
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(2 +
        pos.x, 1 + pos.y, 2.5, 100), sfWhite, (sfVector2f){274, 212}});
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(0 +
        pos.x, 1 + pos.y, 5, 100), sfWhite, (sfVector2f){176, 0}});
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(0 +
        pos.x, 1 + pos.y, 5, 100), sfWhite, (sfVector2f){176, 0}});
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(1 +
        pos.x, 2 + pos.y, 2.5, 100), sfWhite, (sfVector2f){176, 212}});
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(2 +
        pos.x, 1 + pos.y, 2.5, 100), sfWhite, (sfVector2f){274, 212}});
}
