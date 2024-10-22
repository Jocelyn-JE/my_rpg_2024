/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** rpg
*/

#pragma once

#include "blocks.h"
#include "linked_list.h"
#include "mystr.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <fcntl.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

// Enumerations

typedef enum p_items {
    p_apple = 0,
    p_arrow = 1,
    p_diamond_axe = 2,
    p_diamond_pickaxe = 3,
    p_diamond_sword = 4,
    p_diamond_helmet = 5,
    p_diamond_chestplate = 6,
    p_diamond_leggings = 7,
    p_diamond_boots = 8,
    p_iron_axe = 9,
    p_iron_pickaxe = 10,
    p_iron_sword = 11,
    p_iron_helmet = 12,
    p_iron_chestplate = 13,
    p_iron_leggings = 14,
    p_iron_boots = 15,
    p_gold_axe = 16,
    p_gold_pickaxe = 17,
    p_gold_sword = 18,
    p_gold_helmet = 19,
    p_gold_chestplate = 20,
    p_gold_leggings = 21,
    p_gold_boots = 22,
    p_netherite_axe = 23,
    p_netherite_pickaxe = 24,
    p_netherite_sword = 25,
    p_netherite_helmet = 26,
    p_netherite_chestplate = 27,
    p_netherite_leggings = 28,
    p_netherite_boots = 29,
} p_items_t;

typedef enum scenes {
    s_menu,
    s_settings,
    s_video_settings,
    s_sound_settings,
    s_game,
    s_splashscreen,
    s_pause_menu,
    s_inventory,
    s_help_menu
} scenes_t;

// Structures

typedef struct switch_scene_s {
    void (*function)();
} switch_scene_t;

typedef struct inventory_params_s {
    sfVector2f world_pos;
    sfVector2f center;
    sfVector2f size;
    float scale;
    float offset_X;
    float offset_Y;
    float slot_width;
    float slot_height;
    float spacing;
} inventory_params_t;

typedef struct item_s {
    p_items_t current_item;
    sfSprite *sprite;
    sfText *quantity_text;
    int limit;
    int quantity;
} item_t;

typedef struct inventory_s {
    sfSprite *background;
    int selected_slot;
    sfSprite *hotbar;
    sfSprite *selection;
    sfSprite *trash;
    int dragging_slot;
    item_t *dragged_item;
    item_t *armor[4];
    item_t *slots[36];
    int current_item_slot;
    int current_armor_slot;
} inventory_t;

typedef struct vector3uint8_s {
    uint8_t x;
    uint8_t y;
    uint8_t z;
} vector3uint8_t;

typedef struct chunk_s {
    uint8_t *blocks;
    sfFloatRect bounding_box;
    sfTransformable *transform;
    sfVertexArray *vertices;
} chunk_t;

typedef struct debug_s {
    bool bounding_box;
    bool fps;
} debug_t;

typedef enum e_state {
    e_north = 0,
    e_south = 1,
    e_west = 2,
    e_east = 3,
} e_state_t;

typedef struct stat_s {
    int health;
    int attack;
    int defense;
} stat_t;

typedef struct entity_s {
    uint32_t type;
    sfVector2f pos;
    e_state_t state;
    stat_t stats;
} entity_t;

typedef struct player_s {
    sfVector2f pos;
    stat_t stats;
    entity_t *enemy;
    sfSprite *health_sprite;
    sfTexture *health_texture;
} player_t;

typedef enum combat_state_s {
    PLAYER_TURN,
    ENEMY_TURN,
    COMBAT_IDLE,
    PLAYER_WON,
    PLAYER_LOST
} combat_state_t;

typedef struct game_s {
    sfTexture *block_atlas;
    block_t **block_types;
    list_t *entities;
    chunk_t **map;
    player_t *player;
    combat_state_t combat_state;
    int selected_item;
} game_t;

typedef struct logo_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfColor color;
} logo_t;

typedef struct menu_s {
    sfSprite *backsprite;
    sfTexture *backtexture;
    sfSprite *helpsprite;
    sfTexture *helptexture;
} menu_t;

typedef struct sound_s {
    sfMusic **music;
    sfSound **sounds;
    sfSoundBuffer **sound_buffers;
    int volume_general;
    int volume_music;
    int volume_effect;
} sound_t;

typedef struct button_s {
    sfSprite *sprite;
    sfTexture *texture;
} button_t;

typedef struct text_s {
    sfFont *font;
    sfText *text;
} text_t;

typedef struct update_chunk_info_s {
    chunk_t *chunk;
    block_t **blocks;
    list_t *entities;
    int chunk_index;
} update_chunk_info_t;

typedef struct app_s {
    float zoom;
    sfRenderWindow *window;
    sfView *game_view;
    sfView *view;
    sfClock *game_clock;
    menu_t *menu;
    button_t *button;
    logo_t *logo;
    text_t *text;
    sound_t *sound;
    debug_t *debug_options;
    game_t *game_ressources;
    inventory_t *inventory;
    sfFont **fonts;
    scenes_t previous_scene;
    void (*draw_function)(struct app_s *);
    void (*event_handler)(struct app_s *, sfEvent *);
} app_t;

// Handlers

typedef void (*event_handler_t)(sfEvent *event, app_t *app);

// Create / init functions
sfRenderWindow *create_window(sfVector2f res, unsigned int bpp,
    sfUint32 style);
app_t *create_app(void);
void add_cube(sfVertexArray *vertices, int index, uint8_t *blocks,
    block_t **block_types);
entity_t *create_entity(sfVector2f a, uint32_t b,
    e_state_t c, stat_t d);
chunk_t *create_chunk(block_t **blocks, int map_fd);
block_t **init_blocks(void);
void set_life(player_t *player, int x, int y);

// Destroy / free functions

void destroy_entity(entity_t *entity);
void destroy_chunk(chunk_t *chunk);
void destroy_block(block_t *block);
void destroy_app(app_t *app);

// Coordinates conversion
sfVector2f cartesian_to_isometric(float x, float y, float z, float size);
sfVector2f isometric_to_cartesian(float x, float y, float size);
sfVector2f get_chunk_coords(sfVector2f pos);
block_t *get_block(sfVector3f coords, block_t **block_types, chunk_t **map);
uint8_t get_block_id(sfVector3f coords, chunk_t **map);

// Other
int get_random_nb(int min_value, int max_value);
double clamp(double d, double min, double max);
void drag_view(sfEvent *event, sfRenderWindow *window, sfView *view);
void get_letterbox_view(sfView *view, sfVector2u size);
void update_chunk(update_chunk_info_t *info);
void update_chunks(app_t *app);
void handle_movement(player_t *player, entity_t *player_entity, sfTime dt,
    game_t *game);
void handle_button_click(app_t *app, sfMouseButtonEvent *mouse_event);
sfSprite* create_sprite(const char *texture_path,
    sfVector2f position, sfVector2f scale);
void set_text(app_t *app, sfVector2f position, char *filename, int i);
void update_text(text_t *text, sfVector2f pos, char *string, int i);
bool is_on_sprite(sfSprite *button, sfVector2f pos);
void update_life(player_t *player);

// Menu

menu_t *create_menu(void);
logo_t *create_logo(void);
void text_menu(app_t *app);
void set_button(app_t *app);
void manage_events_menu(app_t *app, sfEvent *event);
void update_buttons(app_t *app);
void draw_button(sfRenderWindow *window, sfSprite *sprite, sfText *text);


// Setting

void set_button_setting(app_t *app);
void text_setting(app_t *app);

// Video

void set_button_video(app_t *app);
void text_video(app_t *app);

// Musique

void set_button_sound(app_t *app);
void text_sound(app_t *app);
sfSoundBuffer **init_buffers(void);
sfSound **init_sounds(sfSoundBuffer **buffers);
sound_t *init_sound(void);

// Debug

void draw_bounding_box(sfRenderWindow *window, sfView *view, sfFloatRect box,
    sfVector2f position);
void print_framerate(void);
void draw_bounds(sfRenderWindow *, sfSprite *, float);
void wait_for_seconds(float);

// Conversions
int get_idx_from_pos(int x, int y, int z);
vector3uint8_t get_pos_from_index(int i);
int get_chunk_index_from_coordinates(int x, int y);
sfVector2i get_chunk_coordinates_from_index(int index);
sfVector2i get_block_coordinates_from_index(int index);

// Entities

void add_entity(sfVertexArray *vertices, entity_t *entity);
sfVector2f get_entity_chunk_coords(entity_t *entity);
int get_slot_index(int, int, app_t *);
int get_armor_index(int, int, app_t *);
player_t *init_player(void);

// Inventory

void setup_inventory(app_t *);
void draw_semi_transparent_rect(sfRenderWindow *window, const sfView *view);
void draw_inventory(app_t *);
void draw_hotbar(app_t *);
void draw_bounds(sfRenderWindow *, sfSprite *, float);
float adjust_sprite_scale(inventory_t *, float, float);
bool add_item_to_inventory(inventory_t *, item_t *, int);
inventory_params_t setup_inventory_params(int, int, app_t *);
inventory_params_t setup_armor_params(int, int, app_t *);
bool is_helmet(p_items_t);
bool is_chestplate(p_items_t);
bool is_leggings(p_items_t);
bool is_boots(p_items_t);
void draw_highlighted_slot(app_t *);
void manage_dragged_item(app_t *, sfVector2f, float, float);
void free_item(item_t *);
void free_inventory(inventory_t *);
item_t *copy_item(item_t *);
int get_total_armor_value(inventory_t *);

//Draw functions

void draw_chunks(chunk_t **chunks, app_t *app);
void draw_game(app_t *app);
void draw_splashscreen(app_t *app);
void draw_menu(app_t *app);

//Events

void handle_mouse_button(sfEvent *, app_t *);
void handle_closed(sfEvent *, app_t *);
void handle_resized(sfEvent *, app_t *);
void handle_mouse_wheeling(sfEvent *, app_t *);
void handle_key_pressed(sfEvent *, app_t *);
void handle_mouse_moved(sfEvent *, app_t *);
void manage_armor_slots(app_t *, sfEvent *);
void manage_game_events(app_t *, sfEvent *);
void manage_invent_events(app_t *, sfEvent *);
void manage_combat_events(app_t *, sfEvent *);
void handle_key_pressed_game(sfEvent *, app_t *);
void case_picking(app_t *, int, sfVector2f);
void handle_mouse_button_right(app_t *, sfEvent *);

// Scenes

void switch_to_scene(app_t *app, scenes_t scene);
void switch_to_menu(app_t *app, scenes_t previous_scene);
void switch_to_settings(app_t *app, scenes_t previous_scene);
void switch_to_video_settings(app_t *app);
void switch_to_sound_settings(app_t *app);
void switch_to_game(app_t *app);
void switch_to_splashscreen(app_t *app);
void switch_to_pause_menu(app_t *app);
void switch_to_inventory(app_t *app);
void switch_to_help_menu(app_t *app);
void switch_to_combat(app_t *app);

// Combats
entity_t *find_entity_by_type(list_t *, uint32_t);
void attack_player(entity_t *, player_t *);
void attack_entity(player_t *, entity_t *, int);
sfSprite *setup_hotbar_sprite(app_t *app);
void draw_selection_game(app_t *, sfFloatRect, float);
void draw_hotbar_items_game(app_t *app, sfSprite *hotbar_sprite);
void display_hotbar_unavailable(app_t *app, sfSprite *hotbarSprite);
void reset_player_stats(player_t *player);
