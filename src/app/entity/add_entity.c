/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** add_entity
*/
#include "rpg.h"

void add_entity(sfVertexArray *vertices, int index, entity_t *entity)
{
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(0 +
        entity->pos.x, 0 + entity->pos.y, 1, 100), sfRed, (sfVector2f){0, 0}});
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(1 +
        entity->pos.x, 0 + entity->pos.y, 1, 100), sfRed, (sfVector2f){0, 0}});
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(0 +
        entity->pos.x, 1 + entity->pos.y, 1, 100), sfRed, (sfVector2f){0, 0}});
}
