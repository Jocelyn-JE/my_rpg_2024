/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** dead_bush
*/
#include "rpg.h"
#include "blocks.h"

static sfVertex *get_diagonal_face(sfVector2f text_pos1, sfVector2f text_pos2,
    sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 7);

    vertices[0] = (sfVertex){(sfVector2f){1 + offset.x, 0 + offset.y}, sfWhite,
        text_pos1};
    vertices[1] = (sfVertex){(sfVector2f){2 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){text_pos1.x, text_pos2.y}};
    vertices[2] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){text_pos2.x, text_pos1.y}};
    vertices[3] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){text_pos2.x, text_pos1.y}};
    vertices[4] = (sfVertex){(sfVector2f){1 + offset.x, 2 + offset.y}, sfWhite,
        text_pos2};
    vertices[5] = (sfVertex){(sfVector2f){2 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){text_pos1.x, text_pos2.y}};
    vertices[6] = (sfVertex){(sfVector2f){0, 0},
        (sfColor){0, 0, 0, 0}, (sfVector2f){0, 0}};
    return vertices;
}

block_t *init_dead_bush(void)
{
    block_t *block = malloc(sizeof(block_t));

    block->faces = malloc(sizeof(sfVertex *) * 4);
    block->faces[0] = get_diagonal_face((sfVector2f){112, 48},
        (sfVector2f){128, 64}, (sfVector2f){0, 0});
    block->faces[1] = get_diagonal_face((sfVector2f){112, 48},
        (sfVector2f){128, 64}, (sfVector2f){0, 0});
    block->faces[2] = get_diagonal_face((sfVector2f){112, 48},
        (sfVector2f){128, 64}, (sfVector2f){0, 0});
    block->faces[3] = NULL;
    block->transparent = true;
    block->solid = false;
    return block;
}
