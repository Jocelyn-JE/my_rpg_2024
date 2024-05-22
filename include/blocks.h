/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** blocks
*/

#pragma once
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

enum blocks {
    b_null,
    b_air,
    b_stone,
    b_oak_planks,
    b_y_oak_log,
    b_grass_block,
    b_barrel,
    b_beehive,
    b_bookshelf,
    b_cactus,
    b_sand,
    b_dirt_path,
    b_grass,
    b_cobblestone,
    b_dead_bush,
    b_sandstone,
    b_smooth_sandstone,
    b_cut_sandstone,
    b_ice,
    b_water,
    b_jungle_log,
    b_mossy_cobblestone,
    b_fern,
    b_snowy_grass_block,
    b_poppy,
    b_dandelion,
    b_wheat,
    b_beetroots,
    b_white_wool,
    b_y_oak_wood,
    b_x_oak_wood,
    b_z_oak_wood,
    b_oak_leaves,
    b_jungle_leaves,
    b_spruce_leaves,
    b_snow,
    b_end_stone_bricks,
    b_end_stone,
    b_special_sandstone,
    b_y_stripped_birch_wood,
    b_y_hay_block,
    b_x_hay_block,
    b_z_hay_block,
    b_dirt,
    b_coarse_dirt,
    b_rooted_dirt,
    b_brown_concrete_powder,
    b_podzol,
    b_brown_concrete,
    b_dead_brain_coral_block,
    b_dead_fire_coral_block,
    b_moss_block,
    b_white_concrete_powder,
    b_smooth_quartz,
    b_diorite,
    b_birch_planks,
    b_spruce_planks,
    b_calcite,
    b_dark_oak_planks,
    b_jungle_planks,
    b_x_oak_log,
    b_z_oak_log,
    b_y_spruce_log,
    b_x_spruce_log,
    b_z_spruce_log,
    b_lava,
    b_andesite,
    b_blackstone,
    b_polished_blackstone,
    b_polished_blackstone_bricks,
    b_gilded_blackstone,
    b_cracked_polished_blackstone_bricks,
    b_chiseled_polished_blackstone,
    b_coal_block,
    b_obsidian,
    b_crying_obsidian,
    b_dead_fire_coral
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

typedef struct uv_coords_s {
    sfVector2f top_left;
    sfVector2f bottom_right;
} uv_coords_t;

typedef struct block_s {
    sfVertex **faces;
    bool transparent;
    bool solid;
} block_t;

typedef struct init_func_s {
    block_t *(*function)();
} init_func_t;

// Basic cube faces with possibility of offset

sfVertex *get_top_face(uv_coords_t uv_mapping, sfVector2f offset);
sfVertex *get_left_face(uv_coords_t uv_mapping, sfVector2f offset);
sfVertex *get_right_face(uv_coords_t uv_mapping, sfVector2f offset);
sfVertex *get_top_face_rot(uv_coords_t uv_mapping, sfVector2f offset);
sfVertex *get_left_face_rot(uv_coords_t uv_mapping, sfVector2f offset);
sfVertex *get_right_face_rot(uv_coords_t uv_mapping, sfVector2f offset);
sfVertex *get_water_face(uv_coords_t uv, sfVector2f offset);
sfVertex *get_lava_face(uv_coords_t uv, sfVector2f offset);
sfVertex *get_wheat_vertex(uv_coords_t uv_mapping);
sfVertex *get_diagonal_face(uv_coords_t uv, sfVector2f offset, sfColor color);

// Block inits

block_t *init_cactus(void);
block_t *init_bookshelf(void);
block_t *init_beehive(void);
block_t *init_grass_block(void);
block_t *init_barrel(void);
block_t *init_y_oak_log(void);
block_t *init_x_oak_log(void);
block_t *init_z_oak_log(void);
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
block_t *init_snowy_grass_block(void);
block_t *init_poppy(void);
block_t *init_dandelion(void);
block_t *init_wheat(void);
block_t *init_beetroots(void);
block_t *init_white_wool(void);
block_t *init_y_oak_wood(void);
block_t *init_x_oak_wood(void);
block_t *init_z_oak_wood(void);
block_t *init_oak_leaves(void);
block_t *init_jungle_leaves(void);
block_t *init_spruce_leaves(void);
block_t *init_snow(void);
block_t *init_end_stone_bricks(void);
block_t *init_end_stone(void);
block_t *init_special_sandstone(void);
block_t *init_y_stripped_birch_wood(void);
block_t *init_y_hay_block(void);
block_t *init_x_hay_block(void);
block_t *init_z_hay_block(void);
block_t *init_dirt(void);
block_t *init_coarse_dirt(void);
block_t *init_rooted_dirt(void);
block_t *init_brown_concrete_powder(void);
block_t *init_podzol(void);
block_t *init_brown_concrete(void);
block_t *init_dead_brain_coral_block(void);
block_t *init_dead_fire_coral_block(void);
block_t *init_moss_block(void);
block_t *init_white_concrete_powder(void);
block_t *init_smooth_quartz(void);
block_t *init_diorite(void);
block_t *init_birch_planks(void);
block_t *init_spruce_planks(void);
block_t *init_calcite(void);
block_t *init_dark_oak_planks(void);
block_t *init_jungle_planks(void);
block_t *init_y_spruce_log(void);
block_t *init_x_spruce_log(void);
block_t *init_z_spruce_log(void);
block_t *init_lava(void);
block_t *init_andesite(void);
block_t *init_blackstone(void);
block_t *init_polished_blackstone(void);
block_t *init_polished_blackstone_bricks(void);
block_t *init_gilded_blackstone(void);
block_t *init_cracked_polished_blackstone_bricks(void);
block_t *init_chiseled_polished_blackstone(void);
block_t *init_coal_block(void);
block_t *init_obsidian(void);
block_t *init_crying_obsidian(void);
block_t *init_dead_fire_coral(void);

// Colors

sfColor grass_green(void);
sfColor water_blue(void);

// Other

bool is_null_vertex(sfVertex vertex);
sfVertex null_vertex(void);
void cat_vertex_array(sfVertex *arr1, sfVertex *arr2);

// Animations

void update_blocks(block_t **blocks, sfTime dt);
