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
    sfFloatRect renderdistance;
    sfVector2f viewpos = sfView_getCenter(view);

    renderdistance.width = 5000;
    renderdistance.height = renderdistance.width / 2;
    renderdistance.left = viewpos.x - renderdistance.width / 2;
    renderdistance.top = viewpos.y - renderdistance.height / 2;
    bounds.left += position.x;
    bounds.top += position.y;
    return sfFloatRect_intersects(&bounds, &renderdistance, NULL);
}

static void set_chunk_transforms(list_t *list)
{
    chunk_t *data;

    for (list_t *current = list; current != NULL; current =
        current->next) {
        data = current->data;
        data->renderstate.transform =
            sfTransformable_getTransform(data->transform);
    }
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
        if (debug_options->bounding_box)
            draw_bounding_box(window, sfVertexArray_getBounds(data->vertices),
                sfTransformable_getPosition(data->transform));
        if (is_vertexarray_visible(view, data->vertices,
            sfTransformable_getPosition(data->transform)))
            sfRenderWindow_drawVertexArray(window, data->vertices,
                &data->renderstate);
    }
}

int main(int argc, char **argv)
{
    app_t *app = create_app();
    sfEvent events;

    while (sfRenderWindow_isOpen(app->window)) {
        poll_events(app, &events);
        sfRenderWindow_clear(app->window, sfBlack);
        set_chunk_transforms(app->map);
        draw_chunks(app->map, app->window, app->debug_options);
        sfRenderWindow_display(app->window);
    }
    destroy_app(app);
    return 0;
}
