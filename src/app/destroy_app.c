/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** destroy_app
*/
#include "rpg.h"

void destroy_app(app_t *app)
{
    sfRenderWindow_destroy(app->window);
    sfTexture_destroy(app->block_atlas);
    destroy_chunk(app->map[0]);
    free(app->map);
    free(app);
}
