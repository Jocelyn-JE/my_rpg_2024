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

static void render_player(sfVertexArray *vertices, entity_t *entity)
{
    sfVector2f pos = get_entity_chunk_coords(entity);
    float offset = 0.41 / 2;
    sfVector2f texture_coords[] = {{295, 0}, {295, 240}, {176, 0}, {176, 240}};
    sfVertex vertices_data[] = {
        (sfVertex){cartesian_to_isometric(1 + pos.x - offset, 0 + pos.y +
            offset, 3.5, 100), sfWhite, texture_coords[0]},
        (sfVertex){cartesian_to_isometric(2 + pos.x - offset, 1 + pos.y +
            offset, 2.5, 100), sfWhite, texture_coords[1]},
        (sfVertex){cartesian_to_isometric(0 + pos.x + offset, 1 + pos.y -
            offset, 3.5, 100), sfWhite, texture_coords[2]},
        (sfVertex){cartesian_to_isometric(0 + pos.x + offset, 1 + pos.y -
            offset, 3.5, 100), sfWhite, texture_coords[2]},
        (sfVertex){cartesian_to_isometric(1 + pos.x + offset, 2 + pos.y -
            offset, 2.5, 100), sfWhite, texture_coords[3]},
        (sfVertex){cartesian_to_isometric(2 + pos.x - offset, 1 + pos.y +
            offset, 2.5, 100), sfWhite, texture_coords[1]},
    };

    for (int i = 0; i < sizeof(vertices_data) / sizeof(vertices_data[0]); i++)
        sfVertexArray_append(vertices, vertices_data[i]);
}

void add_entity(sfVertexArray *vertices, int index, entity_t *entity)
{
    if (entity->type == e_player)
        render_player(vertices, entity);
}
