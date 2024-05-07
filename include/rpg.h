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
#include <assert.h>
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
    struct menu_s *menu;
    struct buton_s *buton;
    struct event_s *event;
    struct logo_s *logo;
    struct text_s *text;
    struct sound_s *sound;
} app_t;

typedef struct menu_s {
    sfSprite *backsprite;
    sfTexture *backtexture;
    sfVector2f *backposition;
    sfVector2f backscale;
} menu_t;

typedef struct sound_s {
    sfMusic *music;
    int volume;
} sound_t;

typedef struct buton_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f *position;
    sfVector2f scale;
    sfFloatRect hitbox;
    int number;
} buton_t;

typedef struct text_s {
    sfFont *font;
    sfText *text;
} text_t;

typedef struct event_s {
    sfEvent event;
} event_t;

typedef struct logo_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f *position;
    sfVector2f scale;
    sfColor color;
} logo_t;
// Create / init functions

sfRenderWindow *create_window(sfVector2f res, unsigned int bpp);
app_t *create_app(void);
void add_cube(sfVertexArray *vertices, int index, uint8_t *blocks);
chunk_t *create_chunk(sfTexture *atlas);

// Destroy / free functions

void destroy_chunk(chunk_t *chunk);
void destroy_app(app_t *app);

// Coordinates conversion

sfVector2f cartesian_to_isometric(float x, float y, float z, float size);
sfVector2f isometric_to_cartesian(float x, float y, float size);

// Other

int get_random_nb(int min_value, int max_value);
void poll_events(app_t *app, sfEvent *event);
void splash_screen(app_t *a);
void menu(app_t *app);
void destroy_menu(app_t *app);
double clamp(double d, double min, double max);
void drag_view(sfEvent *event, sfRenderWindow *window, sfView *view);
void get_letterbox_view(sfView *view, sfVector2f size);
void set_buton(app_t *app);
void handle_button_click(app_t *app, sfMouseButtonEvent *mouse_event);
void text_menu(app_t *app);
void setting(app_t *app);
void set_buton_setting(app_t *app);
void set_buton_sound(app_t *app);
void set_buton_video(app_t *app);
void text_setting(app_t *app);
void text_sound(app_t *app);
void text_video(app_t *app);
void set_sound(app_t *app);
void parameter_sound(app_t *app);
void parameter_video(app_t *app);
sfSprite* create_sprite(const char *texture_path,
    sfVector2f position, sfVector2f scale);
void set_text(app_t *app, sfVector2f position, char *filename, int i);

// Debug
void draw_bounding_box(sfRenderWindow *window, sfView *view, sfFloatRect box,
    sfVector2f position);
void print_framerate(void);

// Conversions

int get_index_from_pos(int x, int y, int z);
vector3uint8_t get_pos_from_index(int i);
