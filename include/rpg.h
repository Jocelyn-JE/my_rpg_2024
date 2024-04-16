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
#include "linked_list.h"
#include "mystr.h"

// Structures

typedef struct map_s {
    sfTransformable *transform;
    sfVertexArray *vertices;
    sfRenderStates renderstate;
} map_t;

typedef struct app_s {
    sfRenderWindow *window;
    sfClock *game_clock;
    map_t *map;
} app_t;

// Create / init functions

sfRenderWindow *create_window(unsigned int w,
    unsigned int h, unsigned int bpp);
app_t *create_app(void);

// Destroy / free functions

void destroy_app(app_t *app);

// Coordinates conversion

sfVector2f cartesian_to_isometric(float x, float y, float size);
sfVector2f isometric_to_cartesian(float x, float y, float size);

// Other

int get_random_nb(int min_value, int max_value);
void poll_events(app_t *app, sfEvent *event);
