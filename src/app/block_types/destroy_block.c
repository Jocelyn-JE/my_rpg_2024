/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** destroy_block
*/
#include "rpg.h"
#include "blocks.h"

void destroy_block(block_t *block)
{
    for (int i = 0; block->faces && block->faces[i] != NULL; i++)
        free(block->faces[i]);
    free(block->faces);
    free(block);
}
