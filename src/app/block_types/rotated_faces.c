/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** rotated_faces
*/
#include "blocks.h"

sfVertex *get_top_face_rot(uv_coords_t uv,
    sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 7);

    vertices[0] = (sfVertex){(sfVector2f){0 + offset.x, 0 + offset.y}, sfWhite,
        (sfVector2f){uv.top_left.x, uv.top_left.y}};
    vertices[1] = (sfVertex){(sfVector2f){1 + offset.x, 0 + offset.y}, sfWhite,
        (sfVector2f){uv.top_left.x, uv.bottom_right.y}};
    vertices[2] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){uv.bottom_right.x, uv.bottom_right.y}};
    vertices[3] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){uv.bottom_right.x, uv.bottom_right.y}};
    vertices[4] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){uv.bottom_right.x, uv.top_left.y}};
    vertices[5] = (sfVertex){(sfVector2f){0 + offset.x, 0 + offset.y}, sfWhite,
        (sfVector2f){uv.top_left.x, uv.top_left.y}};
    vertices[6] = null_vertex();
    return vertices;
}

sfVertex *get_left_face_rot(uv_coords_t uv,
    sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 7);

    vertices[0] = (sfVertex){(sfVector2f){1 + offset.x, 0 + offset.y}, sfWhite,
        (sfVector2f){uv.top_left.x, uv.top_left.y}};
    vertices[1] = (sfVertex){(sfVector2f){2 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){uv.bottom_right.x, uv.top_left.y}};
    vertices[2] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){uv.top_left.x, uv.bottom_right.y}};
    vertices[3] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){uv.top_left.x, uv.bottom_right.y}};
    vertices[4] = (sfVertex){(sfVector2f){2 + offset.x, 2 + offset.y}, sfWhite,
        (sfVector2f){uv.bottom_right.x, uv.bottom_right.y}};
    vertices[5] = (sfVertex){(sfVector2f){2 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){uv.bottom_right.x, uv.top_left.y}};
    vertices[6] = null_vertex();
    return vertices;
}

sfVertex *get_right_face_rot(uv_coords_t uv,
    sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 7);

    vertices[0] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){uv.top_left.x, uv.top_left.y}};
    vertices[1] = (sfVertex){(sfVector2f){2 + offset.x, 2 + offset.y}, sfWhite,
        (sfVector2f){uv.bottom_right.x, uv.top_left.y}};
    vertices[2] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){uv.top_left.x, uv.bottom_right.y}};
    vertices[3] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){uv.top_left.x, uv.bottom_right.y}};
    vertices[4] = (sfVertex){(sfVector2f){1 + offset.x, 2 + offset.y}, sfWhite,
        (sfVector2f){uv.bottom_right.x, uv.bottom_right.y}};
    vertices[5] = (sfVertex){(sfVector2f){2 + offset.x, 2 + offset.y}, sfWhite,
        (sfVector2f){uv.bottom_right.x, uv.top_left.y}};
    vertices[6] = null_vertex();
    return vertices;
}
