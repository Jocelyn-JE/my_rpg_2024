/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** init_app
*/
#include "rpg.h"
#include <time.h>

app_t *create_app(void)
{
    app_t *app = malloc(sizeof(app_t));

    srand(time(NULL));
    app->window = create_window(1920, 1080, 32);
    app->map = malloc(sizeof(chunk_t *) * 1);
    app->block_atlas = sfTexture_createFromFile("assets/textures/atlas.png",
        NULL);
    app->map[0] = malloc(sizeof(chunk_t));
    create_chunk(app->map[0], app->block_atlas);
    return app;
}
