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

static void render_player(sfVertexArray *vertices, entity_t *entity,
    e_state_t dir)
{
    sfVector2f pos = get_entity_chunk_coords(entity);
    sfVector2f texture_coords[] = {{295 + 119 * dir, 0}, {295 + 119 * dir, 240}
        , {176 + 119 * dir, 0}, {176 + 119 * dir, 240}};
    sfVertex vertices_data[] = {
        (sfVertex){cartesian_to_isometric(1 + pos.x - 0.205, 0 + pos.y +
            0.205, 3.5, 100), sfWhite, texture_coords[0]},
        (sfVertex){cartesian_to_isometric(2 + pos.x - 0.205, 1 + pos.y +
            0.205, 2.5, 100), sfWhite, texture_coords[1]},
        (sfVertex){cartesian_to_isometric(0 + pos.x + 0.205, 1 + pos.y -
            0.205, 3.5, 100), sfWhite, texture_coords[2]},
        (sfVertex){cartesian_to_isometric(0 + pos.x + 0.205, 1 + pos.y -
            0.205, 3.5, 100), sfWhite, texture_coords[2]},
        (sfVertex){cartesian_to_isometric(1 + pos.x + 0.205, 2 + pos.y -
            0.205, 2.5, 100), sfWhite, texture_coords[3]},
        (sfVertex){cartesian_to_isometric(2 + pos.x - 0.205, 1 + pos.y +
            0.205, 2.5, 100), sfWhite, texture_coords[1]},
    };

    for (uint32_t i = 0; i < 6; i++)
        sfVertexArray_append(vertices, vertices_data[i]);
}

static void render_zombie(sfVertexArray *vertices, entity_t *entity,
    e_state_t dir)
{
    sfVector2f pos = get_entity_chunk_coords(entity);
    sfVector2f texture_coords[] = {{295 + 119 * dir, 240}, {295 + 119 * dir,
        480}, {176 + 119 * dir, 240}, {176 + 119 * dir, 480}};
    sfVertex vertices_data[] = {
        (sfVertex){cartesian_to_isometric(1 + pos.x - 0.205, 0 + pos.y +
            0.205, 3.5, 100), sfWhite, texture_coords[0]},
        (sfVertex){cartesian_to_isometric(2 + pos.x - 0.205, 1 + pos.y +
            0.205, 2.5, 100), sfWhite, texture_coords[1]},
        (sfVertex){cartesian_to_isometric(0 + pos.x + 0.205, 1 + pos.y -
            0.205, 3.5, 100), sfWhite, texture_coords[2]},
        (sfVertex){cartesian_to_isometric(0 + pos.x + 0.205, 1 + pos.y -
            0.205, 3.5, 100), sfWhite, texture_coords[2]},
        (sfVertex){cartesian_to_isometric(1 + pos.x + 0.205, 2 + pos.y -
            0.205, 2.5, 100), sfWhite, texture_coords[3]},
        (sfVertex){cartesian_to_isometric(2 + pos.x - 0.205, 1 + pos.y +
            0.205, 2.5, 100), sfWhite, texture_coords[1]},
    };

    for (uint32_t i = 0; i < 6; i++)
        sfVertexArray_append(vertices, vertices_data[i]);
}

void add_entity(sfVertexArray *vertices, entity_t *entity)
{
    if (entity->type == e_player)
        render_player(vertices, entity, entity->state);
    if (entity->type == e_zombie)
        render_zombie(vertices, entity, entity->state);
}
