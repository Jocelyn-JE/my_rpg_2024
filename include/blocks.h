/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** blocks
*/

#pragma once
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

enum blocks {
    b_null,
    b_air,
    b_stone,
    b_oak_planks,
    b_oak_log,
    b_grass,
    b_barrel,
    b_hive,
    b_library,
    b_cactus,
    b_sand
};

typedef struct block_s {
    sfVertex **faces;
    bool transparent;
} block_t;

// Basic cube faces with possibility of offset

sfVertex *get_top_face(sfVector2f text_pos1, sfVector2f text_pos2,
    sfVector2f offset);
sfVertex *get_left_face(sfVector2f text_pos1, sfVector2f text_pos2,
    sfVector2f offset);
sfVertex *get_right_face(sfVector2f text_pos1, sfVector2f text_pos2,
    sfVector2f offset);

// Block inits

block_t *init_cactus(void);
block_t *init_bookshelf(void);
block_t *init_beehive(void);
block_t *init_grass_block(void);
block_t *init_barrel(void);
block_t *init_oak_log(void);
block_t *init_null(void);
block_t *init_air(void);
block_t *init_oak_planks(void);
block_t *init_stone(void);
block_t *init_sand(void);
block_t *init_dirt_path(void);
