/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** main
*/
#include "rpg.h"

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

static void draw_chunks(list_t *list, app_t *app)
{
    chunk_t *data;
    sfRenderStates renderstate = sfRenderStates_default();

    renderstate.texture = app->game_ressources->block_atlas;
    for (list_t *current = list; current != NULL; current =
        current->next) {
        data = current->data;
        renderstate.transform = sfTransformable_getTransform(data->transform);
        if (app->debug_options->wireframe)
            sfVertexArray_setPrimitiveType(data->vertices, sfLines);
        else
            sfVertexArray_setPrimitiveType(data->vertices, sfTriangles);
        if (is_vertexarray_visible(app->view, data->bounding_box,
            sfTransformable_getPosition(data->transform), app->window))
            sfRenderWindow_drawVertexArray(app->window, data->vertices,
                &renderstate);
        if (app->debug_options->bounding_box)
            draw_bounding_box(app->window, app->view, data->bounding_box,
                sfTransformable_getPosition(data->transform));
    }
}

int main(int argc, char **argv)
{
    app_t *app = create_app();
    sfEvent events;

    while (sfRenderWindow_isOpen(app->window)) {
        print_framerate();
        poll_events(app, &events);
        sfRenderWindow_clear(app->window, sfBlack);
        draw_chunks(app->game_ressources->map, app);
        sfRenderWindow_setView(app->window, app->view);
        sfRenderWindow_display(app->window);
    }
    destroy_app(app);
    return 0;
}
