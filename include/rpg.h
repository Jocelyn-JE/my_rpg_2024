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
#include "linked_list.h"
#include "mystr.h"

// Structures

typedef struct vector3uint8_s {
    uint8_t x;
    uint8_t y;
    uint8_t z;
} vector3uint8_t;

typedef struct chunk_s {
    uint8_t *blocks;
    sfTransformable *transform;
    sfVertexArray *vertices;
    sfRenderStates renderstate;
} chunk_t;

typedef struct debug_s {
    bool wireframe;
    bool bounding_box;
} debug_t;

typedef struct app_s {
    debug_t *debug_options;
    sfRenderWindow *window;
    sfClock *game_clock;
    sfTexture *block_atlas;
    list_t *map;
} app_t;

// Create / init functions

sfRenderWindow *create_window(unsigned int w,
    unsigned int h, unsigned int bpp);
app_t *create_app(void);
void add_cube(sfVertexArray *vertices, vector3uint8_t position,
    uint8_t *blocks);
chunk_t *create_chunk(sfTexture *atlas);

// Destroy / free functions

void destroy_chunk(chunk_t *chunk);
void destroy_app(app_t *app);

// Coordinates conversion

sfVector2f cartesian_to_isometric(float x, float y, float z, float size);
sfVector2f isometric_to_cartesian(float x, float y, float size);

// Other

void vertex_array_cat(sfVertexArray *array, sfVertexArray *add,
    sfVector2f offset);
int get_random_nb(int min_value, int max_value);
void poll_events(app_t *app, sfEvent *event);
double clamp(double d, double min, double max);
void drag_view(sfEvent *event, sfRenderWindow *window, sfView *view);

// Debug
void draw_bounding_box(sfRenderWindow *window, sfFloatRect box,
    sfVector2f position);

// Conversions

int get_index_from_pos(int x, int y, int z);
vector3uint8_t get_pos_from_index(int i);
