/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** init_blocks
*/
#include "blocks.h"
#include "rpg.h"

sfVertex *get_top_face(sfVector2f text_pos1, sfVector2f text_pos2,
    sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 6);

    vertices[0] = (sfVertex){(sfVector2f){0 + offset.x, 0 + offset.y}, sfWhite,
        text_pos1};
    vertices[1] = (sfVertex){(sfVector2f){1 + offset.x, 0 + offset.y}, sfWhite,
        (sfVector2f){text_pos2.x, text_pos1.y}};
    vertices[2] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        text_pos2};
    vertices[3] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        text_pos2};
    vertices[4] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){text_pos1.x, text_pos2.y}};
    vertices[5] = (sfVertex){(sfVector2f){0 + offset.x, 0 + offset.y}, sfWhite,
        text_pos1};
    return vertices;
}

sfVertex *get_left_face(sfVector2f text_pos1, sfVector2f text_pos2,
    sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 6);

    vertices[0] = (sfVertex){(sfVector2f){1 + offset.x, 0 + offset.y}, sfWhite,
        text_pos1};
    vertices[1] = (sfVertex){(sfVector2f){2 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){text_pos1.x, text_pos2.y}};
    vertices[2] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){text_pos2.x, text_pos1.y}};
    vertices[3] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){text_pos2.x, text_pos1.y}};
    vertices[4] = (sfVertex){(sfVector2f){2 + offset.x, 2 + offset.y}, sfWhite,
        text_pos2};
    vertices[5] = (sfVertex){(sfVector2f){2 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){text_pos1.x, text_pos2.y}};
    return vertices;
}

sfVertex *get_right_face(sfVector2f text_pos1, sfVector2f text_pos2,
    sfVector2f offset)
{
    sfVertex *vertices = malloc(sizeof(sfVertex) * 6);

    vertices[0] = (sfVertex){(sfVector2f){1 + offset.x, 1 + offset.y}, sfWhite,
        text_pos1};
    vertices[1] = (sfVertex){(sfVector2f){2 + offset.x, 2 + offset.y}, sfWhite,
        (sfVector2f){text_pos1.x, text_pos2.y}};
    vertices[2] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y},
        sfWhite, (sfVector2f){text_pos2.x, text_pos1.y}};
    vertices[3] = (sfVertex){(sfVector2f){0 + offset.x, 1 + offset.y}, sfWhite,
        (sfVector2f){text_pos2.x, text_pos1.y}};
    vertices[4] = (sfVertex){(sfVector2f){1 + offset.x, 2 + offset.y}, sfWhite,
        text_pos2};
    vertices[5] = (sfVertex){(sfVector2f){2 + offset.x, 2 + offset.y}, sfWhite,
        (sfVector2f){text_pos1.x, text_pos2.y}};
    return vertices;
}

block_t **init_blocks(void)
{
    block_t **blocks = malloc(sizeof(block_t *) * 10);

    blocks[0] = init_null();
    blocks[1] = init_air();
    blocks[2] = init_stone();
    blocks[3] = init_oak_planks();
    blocks[4] = init_oak_log();
    blocks[5] = init_grass_block();
    blocks[6] = init_barrel();
    blocks[7] = init_beehive();
    blocks[8] = init_bookshelf();
    blocks[9] = init_cactus();
    return blocks;
}
