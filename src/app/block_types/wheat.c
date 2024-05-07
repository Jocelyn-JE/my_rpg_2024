/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** wheat
*/
#include "blocks.h"

sfVertex *get_wheat_vertex(sfVector2f text_pos1, sfVector2f text_pos2)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 25);

    vertices[0] = null_vertex();
    cat_vertex_array(vertices, get_left_face(text_pos1, text_pos2,
        (sfVector2f){-12.f / 16.f, 0}));
    cat_vertex_array(vertices, get_right_face(text_pos1, text_pos2,
        (sfVector2f){0, -12.f / 16.f}));
    cat_vertex_array(vertices, get_left_face(text_pos1, text_pos2,
        (sfVector2f){-4.f / 16.f, 0}));
    cat_vertex_array(vertices, get_right_face(text_pos1, text_pos2,
        (sfVector2f){0, -4.f / 16.f}));
    return vertices;
}

block_t *init_wheat(void)
{
    block_t *block = malloc(sizeof(block_t));
    sfVector2f text_pos1 = {128, 224};
    sfVector2f text_pos2 = {144, 240};

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_wheat_vertex(text_pos1, text_pos2);
    block->faces[1] = NULL;
    block->faces[2] = NULL;
    block->faces[3] = NULL;
    block->transparent = true;
    block->solid = false;
    return block;
}
