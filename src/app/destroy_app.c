/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** destroy_app
*/
#include "rpg.h"

static void destroy_map(map_t *map)
{
    sfVertexArray_destroy(map->vertices);
    sfTexture_destroy((sfTexture *)map->renderstate.texture);
    sfTransformable_destroy(map->transform);
    free(map);
}

void destroy_app(app_t *app)
{
    sfRenderWindow_destroy(app->window);
    destroy_map(app->map);
    free(app);
}
