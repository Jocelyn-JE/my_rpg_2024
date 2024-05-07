/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** main
*/
#include "../include/rpg.h"

sfBool is_vertexarray_visible(sfView *view, sfFloatRect bounds,
    sfVector2f position, sfRenderWindow *window)
{
    sfFloatRect renderdistance = {0, 0, 0, 0};
    sfVector2f viewpos = sfView_getCenter(view);
    sfVector2f size = sfView_getSize(view);

    bounds.left += position.x;
    bounds.top += position.y;
    renderdistance.height = size.y;
    renderdistance.width = size.x;
    renderdistance.left = viewpos.x - renderdistance.width / 2;
    renderdistance.top = viewpos.y - renderdistance.height / 2;
    return sfFloatRect_intersects(&bounds, &renderdistance, NULL);
}

void draw_chunks(chunk_t **list, app_t *app)
{
    sfRenderStates renderstate = sfRenderStates_default();

    renderstate.texture = app->game_ressources->block_atlas;
    for (int i = 0; list[i] != NULL; i++) {
        renderstate.transform =
            sfTransformable_getTransform(list[i]->transform);
        if (is_vertexarray_visible(app->view, list[i]->bounding_box,
            sfTransformable_getPosition(list[i]->transform), app->window)) {
            update_chunk(list[i], app->game_ressources->block_types,
                app->game_ressources->entities, i);
            sfRenderWindow_drawVertexArray(app->window, list[i]->vertices,
                &renderstate);
        }
        if (app->debug_options->bounding_box)
            draw_bounding_box(app->window, app->view, list[i]->bounding_box,
                sfTransformable_getPosition(list[i]->transform));
    }
}

void draw_game(app_t *app)
{
    draw_chunks(app->game_ressources->map, app);
    draw_hotbar(app);
}

static void setup_global_handlers(app_t *app)
{
    app->game_handler = draw_game;
    app->event_handler = manage_game_events;
}

int main(int argc, char **argv)
{
    app_t *app = create_app();
    sfEvent events;

    setup_global_handlers(app);
    while (sfRenderWindow_isOpen(app->window)) {
        app->event_handler(app, &events);
        sfRenderWindow_clear(app->window, sfBlack);
        sfRenderWindow_setView(app->window, app->view);
        app->game_handler(app);
        sfRenderWindow_display(app->window);
    }
    destroy_app(app);
    return 0;
}
