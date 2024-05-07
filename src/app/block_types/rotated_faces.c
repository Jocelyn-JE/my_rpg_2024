/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** rotated_faces
*/
#include "blocks.h"

sfVertex *get_top_face_rot(sfVector2f text_pos1, sfVector2f text_pos2,
    sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 7);

    vertices[0] = (sfVertex){(sfVector2f){0 + offset.x, 0 + offset.y}, sfWhite,
        (sfVector2f){text_pos1.x, text_pos1.y}};
    vertices[1] = (sfVertex){(sfVector2f){1 + offset.x, 0 + offset.y}, sfWhite,
        (sfVector2f){text_pos1.x, text_pos2.y}};
    vertices[2] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){text_pos2.x, text_pos2.y}};
    vertices[3] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){text_pos2.x, text_pos2.y}};
    vertices[4] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){text_pos2.x, text_pos1.y}};
    vertices[5] = (sfVertex){(sfVector2f){0 + offset.x, 0 + offset.y}, sfWhite,
        (sfVector2f){text_pos1.x, text_pos1.y}};
    vertices[6] = null_vertex();
    return vertices;
}

sfVertex *get_left_face_rot(sfVector2f text_pos1, sfVector2f text_pos2,
    sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 7);

    vertices[0] = (sfVertex){(sfVector2f){1 + offset.x, 0 + offset.y}, sfWhite,
        (sfVector2f){text_pos1.x, text_pos1.y}};
    vertices[1] = (sfVertex){(sfVector2f){2 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){text_pos2.x, text_pos1.y}};
    vertices[2] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){text_pos1.x, text_pos2.y}};
    vertices[3] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){text_pos1.x, text_pos2.y}};
    vertices[4] = (sfVertex){(sfVector2f){2 + offset.x, 2 + offset.y}, sfWhite,
        (sfVector2f){text_pos2.x, text_pos2.y}};
    vertices[5] = (sfVertex){(sfVector2f){2 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){text_pos2.x, text_pos1.y}};
    vertices[6] = null_vertex();
    return vertices;
}

sfVertex *get_right_face_rot(sfVector2f text_pos1, sfVector2f text_pos2,
    sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 7);

    vertices[0] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){text_pos1.x, text_pos1.y}};
    vertices[1] = (sfVertex){(sfVector2f){2 + offset.x, 2 + offset.y}, sfWhite,
        (sfVector2f){text_pos2.x, text_pos1.y}};
    vertices[2] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){text_pos1.x, text_pos2.y}};
    vertices[3] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){text_pos1.x, text_pos2.y}};
    vertices[4] = (sfVertex){(sfVector2f){1 + offset.x, 2 + offset.y}, sfWhite,
        (sfVector2f){text_pos2.x, text_pos2.y}};
    vertices[5] = (sfVertex){(sfVector2f){2 + offset.x, 2 + offset.y}, sfWhite,
        (sfVector2f){text_pos2.x, text_pos1.y}};
    vertices[6] = null_vertex();
    return vertices;
}
