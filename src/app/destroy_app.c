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
    free_list(app->map, destroy_chunk);
    free(app->debug_options);
    free(app);
}
