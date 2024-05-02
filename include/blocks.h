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
    b_sand,
    b_cobblestone,
    b_dead_bush,
    b_sandstone,
    b_smooth_sandstone,
    b_cut_sandstone,
    b_ice,
    b_water,
    b_jungle_log,
    b_mossy_cobblestone,
    b_fern
};

enum entities {
    e_player,
    e_villager,
    e_skeleton,
    e_zombie,
    e_enderman,
    e_pig,
    e_cow,
    e_sheep
};

typedef struct block_s {
    sfVertex **faces;
    bool transparent;
    bool solid;
} block_t;

typedef struct init_func_s {
    block_t *(*function)();
} init_func_t;

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
block_t *init_grass(void);
block_t *init_cobblestone(void);
block_t *init_dead_bush(void);
block_t *init_sandstone(void);
block_t *init_smooth_sandstone(void);
block_t *init_cut_sandstone(void);
block_t *init_ice(void);
block_t *init_water(void);
block_t *init_jungle_log(void);
block_t *init_mossy_cobblestone(void);
block_t *init_fern(void);

// Colors

sfColor grass_green(void);
sfColor water_blue(void);
