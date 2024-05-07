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

static void draw_chunks(list_t *list, app_t *app)
{
    chunk_t *data;
    sfRenderStates renderstate = sfRenderStates_default();

    renderstate.texture = app->block_atlas;
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

void draw_game(app_t *app)
{
    draw_chunks(app->map, app);
    draw_hotbar(app);
}

void setup_global_handlers(app_t *app)
{
    app->game_handler = draw_game;
    app->event_handler = manage_game_events;
}

void poll_events(app_t *app, sfEvent *events)
{
    if (events->type == sfEvtClosed)
        handle_closed(events, app);
    if (events->type == sfEvtResized)
        handle_resized(events, app);
    app->event_handler(app, events);
}

int main(int argc, char **argv)
{
    app_t *app = create_app();
    sfEvent events;

    setup_inventory(app);
    setup_global_handlers(app);
    while (sfRenderWindow_isOpen(app->window)) {
        while (sfRenderWindow_pollEvent(app->window, &events)) {
            poll_events(app, &events);
        }
        sfRenderWindow_clear(app->window, sfBlack);
        sfRenderWindow_setView(app->window, app->view);
        app->game_handler(app);
        sfRenderWindow_display(app->window);
    }
    destroy_app(app);
    return 0;
}
