/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** add_entity
*/
#include "rpg.h"

void add_entity(sfVertexArray *vertices, int index, entity_t *entity)
{
    sfVector2f mod = {16.f, 16.f};
    sfVector2f pos = {modff(entity->pos.x, &mod.x) + mod.x,
        modff(entity->pos.y, &mod.y) + mod.y};

    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(0 +
        pos.x, 0 + pos.y, 1, 100), sfRed, (sfVector2f){0, 0}});
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(1 +
        pos.x, 0 + pos.y, 1, 100), sfRed, (sfVector2f){0, 0}});
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(0 +
        pos.x, 1 + pos.y, 1, 100), sfRed, (sfVector2f){0, 0}});
}
