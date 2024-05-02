/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** water
*/
#include "blocks.h"

sfColor water_blue(void)
{
    return (sfColor){63, 118, 228, 255};
}

static sfVertex *get_water_face(sfVector2f text_pos1, sfVector2f text_pos2,
    sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 7);

    vertices[0] = (sfVertex){(sfVector2f){0 + offset.x, 0 + offset.y},
        water_blue(), text_pos1};
    vertices[1] = (sfVertex){(sfVector2f){1 + offset.x, 0 + offset.y},
        water_blue(), (sfVector2f){text_pos2.x, text_pos1.y}};
    vertices[2] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y},
        water_blue(), text_pos2};
    vertices[3] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y},
        water_blue(), text_pos2};
    vertices[4] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y},
        water_blue(), (sfVector2f){text_pos1.x, text_pos2.y}};
    vertices[5] = (sfVertex){(sfVector2f){0 + offset.x, 0 + offset.y},
        water_blue(), text_pos1};
    vertices[6] = (sfVertex){(sfVector2f){0, 0},
        (sfColor){0, 0, 0, 0}, (sfVector2f){0, 0}};
    return vertices;
}

block_t *init_water(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_water_face((sfVector2f){0, 112},
        (sfVector2f){16, 128}, (sfVector2f){(1.f / 16.f) * 2,
        (1.f / 16.f) * 2});
    block->faces[1] = NULL;
    block->faces[2] = NULL;
    block->faces[3] = NULL;
    block->transparent = true;
    block->solid = true;
    return block;
}
