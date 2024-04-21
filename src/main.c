/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** main
*/
#include "rpg.h"

sfBool is_vertexarray_visible(sfView *view, sfVertexArray *vertices,
    sfVector2f position)
{
    sfFloatRect bounds = sfVertexArray_getBounds(vertices);
    sfFloatRect renderdistance = sfView_getViewport(view);
    sfVector2f viewpos = sfView_getCenter(view);
    sfVector2f size = sfView_getSize(view);

    bounds.left += position.x;
    bounds.top += position.y;
    renderdistance.width *= size.x;
    renderdistance.height *= size.y;
    renderdistance.left = viewpos.x - renderdistance.width / 2;
    renderdistance.top = viewpos.y - renderdistance.height / 2;
    return sfFloatRect_intersects(&bounds, &renderdistance, NULL);
}

static void draw_chunks(list_t *list, sfRenderWindow *window,
    debug_t *debug_options)
{
    chunk_t *data;
    sfView *view = (sfView *)sfRenderWindow_getDefaultView(window);

    for (list_t *current = list; current != NULL; current =
        current->next) {
        data = current->data;
        if (debug_options->wireframe)
            sfVertexArray_setPrimitiveType(data->vertices, sfLines);
        else
            sfVertexArray_setPrimitiveType(data->vertices, sfTriangles);
        if (is_vertexarray_visible(view, data->vertices,
            sfTransformable_getPosition(data->transform)))
            sfRenderWindow_drawVertexArray(window, data->vertices,
                &data->renderstate);
        if (debug_options->bounding_box)
            draw_bounding_box(window, sfVertexArray_getBounds(data->vertices),
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
        draw_chunks(app->map, app->window, app->debug_options);
        sfRenderWindow_display(app->window);
    }
    destroy_app(app);
    return 0;
}
