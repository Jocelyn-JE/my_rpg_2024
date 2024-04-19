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
#include "linked_list.h"
#include "mystr.h"

// Structures

typedef struct app_s {
    sfRenderWindow *window;
    struct event_s *e;
} app_t;

typedef struct event_s {
    sfEvent event;
} event_t;
// Create / init functions

sfRenderWindow *create_window(unsigned int w,
    unsigned int h, unsigned int bpp);
app_t *create_app(void);

// Destroy / free functions

void destroy_app(app_t *app);

// Other

void poll_events(app_t *app, sfEvent *event);
void splash_screen(app_t *a);
