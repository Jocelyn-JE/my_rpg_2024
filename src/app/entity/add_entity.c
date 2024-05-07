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

// static void add_face(sfVertexArray *vertices, sfVector2f pos,
//     sfVertex *face, float shading_factor)
// {
//     if (!face)
//         return;
//     for (int i = 0; !is_null_vertex(face[i]); i++) {
//         sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(
//             face[i].position.x + pos.x, face[i].position.y + pos.y, 0,
//             100), (sfColor){face[i].color.r * shading_factor,
//             face[i].color.g * shading_factor,
//             face[i].color.b * shading_factor, face[i].color.a},
//             face[i].texCoords});
//     }
// }

// static void add_player(sfVertexArray *vertices, sfVector2f pos,
//     block_t *player_model)
// {
//     add_face(vertices, pos, player_model->faces[0], 1);
//     add_face(vertices, pos, player_model->faces[1], 0.6);
//     add_face(vertices, pos, player_model->faces[2], 0.8);
// }

void add_entity(sfVertexArray *vertices, int index, entity_t *entity,
    block_t **entity_models)
{
    sfVector2f pos = get_entity_chunk_coords(entity);
    pos.x--;
    pos.y--;
    // add_player(vertices, get_entity_chunk_coords(entity),
    //     entity_models[b_stone]);
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(0 + pos.x, 0 + pos.y, 0,
        100), sfWhite, (sfVector2f){0, 0}});
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(-1 + pos.x, 0 + pos.y, 0,
        100), sfWhite, (sfVector2f){0, 0}});
    sfVertexArray_append(vertices, (sfVertex){cartesian_to_isometric(0 + pos.x, -1 + pos.y, 0,
        100), sfWhite, (sfVector2f){0, 0}});
}
