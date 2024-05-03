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
} p_items_t;

typedef enum game_state {
    MENU,
    GAME,
    INVENTORY,
} state_t;

// Structures

typedef struct item_s {
    p_items_t current_item;
    sfSprite *sprite;
    int quantity;
} item_t;

typedef struct inventory_s {
    sfSprite *background;
    int selected_slot;
    sfSprite *hotbar;
    sfSprite *selection;
    int dragging_slot;
    item_t *dragged_item;
    item_t *slots[36];
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
    bool wireframe;
    bool bounding_box;
    bool fps;
} debug_t;

typedef struct app_s {
    float zoom;
    debug_t *debug_options;
    sfRenderWindow *window;
    sfView *view;
    state_t game_state;
    sfClock *game_clock;
    sfTexture *block_atlas;
    list_t *map;
    inventory_t *inventory;
} app_t;

// Create / init functions

sfRenderWindow *create_window(sfVector2f res, unsigned int bpp);
app_t *create_app(void);
void add_cube(sfVertexArray *vertices, int index, uint8_t *blocks,
    block_t **block_types);
chunk_t *create_chunk(sfTexture *atlas, block_t **blocks, int map_fd);
block_t **init_blocks(void);

// Destroy / free functions

void destroy_chunk(chunk_t *chunk);
void destroy_app(app_t *app);

// Coordinates conversion

sfVector2f cartesian_to_isometric(float x, float y, float z, float size);
sfVector2f isometric_to_cartesian(float x, float y, float size);

// Other

int get_random_nb(int min_value, int max_value);
void poll_events(app_t *app, sfEvent *event);
double clamp(double d, double min, double max);
void drag_view(sfEvent *event, sfRenderWindow *window, sfView *view);
void get_letterbox_view(sfView *view, sfVector2f size);

// Debug
void draw_bounding_box(sfRenderWindow *window, sfView *view, sfFloatRect box,
    sfVector2f position);
void print_framerate(void);

// Conversions

int get_index_from_pos(int x, int y, int z);
vector3uint8_t get_pos_from_index(int i);

// Inventory
void setup_inventory(app_t *app);
void draw_inventory(app_t *app);
void draw_hotbar(app_t *app);
void draw_bounds(sfRenderWindow *, sfSprite *, float);
float adjust_sprite_scale(inventory_t *, float, float);
