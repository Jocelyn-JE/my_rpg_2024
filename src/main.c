/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** main
*/
#include "rpg.h"

int main(int argc, char **argv)
{
    app_t *app = create_app();
    sfEvent events;

    while (sfRenderWindow_isOpen(app->window)) {
        poll_events(app, &events);
        sfRenderWindow_clear(app->window, sfWhite);
        app->map->renderstate.transform = sfTransformable_getTransform(app->map->transform);
        sfRenderWindow_drawVertexArray(app->window, app->map->vertices,
            &app->map->renderstate);
        sfRenderWindow_display(app->window);
    }
    destroy_app(app);
    return 0;
}
