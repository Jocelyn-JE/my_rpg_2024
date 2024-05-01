/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** rpg
*/

#pragma once
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "linked_list.h"
#include "mystr.h"
#include "blocks.h"

// Structures

typedef enum p_items {
    p_cables,
    p_cleaver,
    p_transistor,
} p_items_t;

typedef struct item_s {
    p_items current_item;
    sfTexture* texture;
    int quantity;
} item_t;

typedef struct inventory_s {
    item_t* slots[24];
} inventory_t;

typedef struct hotbar_s {
    item_t* slots[8];
} hotbar_t;

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
    debug_t *debug_options;
    sfRenderWindow *window;
    sfView *view;
    sfClock *game_clock;
    sfTexture *block_atlas;
    list_t *map;
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
