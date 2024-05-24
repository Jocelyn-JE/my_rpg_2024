/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** render game
*/

#include "../../../include/rpg.h"

sfBool is_vertexarray_visible(sfView *view, sfFloatRect bounds,
    sfVector2f position)
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
        if (is_vertexarray_visible(app->game_view, list[i]->bounding_box,
            sfTransformable_getPosition(list[i]->transform)))
            sfRenderWindow_drawVertexArray(app->window, list[i]->vertices,
                &renderstate);
        if (app->debug_options->bounding_box)
            draw_bounding_box(app->window, app->game_view,
                list[i]->bounding_box, sfTransformable_getPosition(
                list[i]->transform));
    }
}

void update_chunks(app_t *app)
{
    game_t *game = app->game_ressources;
    chunk_t **chunks = game->map;
    update_chunk_info_t threads_data[] = {{NULL, game->block_types, game->entities, 0}, {NULL, game->block_types, game->entities, 0}, {NULL, game->block_types, game->entities, 0}, {NULL, game->block_types, game->entities, 0}, {NULL, game->block_types, game->entities, 0}, {NULL, game->block_types, game->entities, 0}, {NULL, game->block_types, game->entities, 0}, {NULL, game->block_types, game->entities, 0}, {NULL, game->block_types, game->entities, 0}, {NULL, game->block_types, game->entities, 0}, {NULL, game->block_types, game->entities, 0}, {NULL, game->block_types, game->entities, 0}, {NULL, game->block_types, game->entities, 0}, {NULL, game->block_types, game->entities, 0}, {NULL, game->block_types, game->entities, 0}, {NULL, game->block_types, game->entities, 0}};
    sfThread *threads[] = {sfThread_create(update_chunk, &threads_data[0]),
        sfThread_create(update_chunk, &threads_data[1]), sfThread_create(
        update_chunk, &threads_data[2]), sfThread_create(update_chunk,
        &threads_data[3]), sfThread_create(update_chunk, &threads_data[4]),
        sfThread_create(update_chunk, &threads_data[5]), sfThread_create(
        update_chunk, &threads_data[6]), sfThread_create(update_chunk,
        &threads_data[7]), sfThread_create(update_chunk, &threads_data[8]),
        sfThread_create(update_chunk, &threads_data[9]), sfThread_create(
        update_chunk, &threads_data[10]), sfThread_create(update_chunk,
        &threads_data[11]), sfThread_create(update_chunk, &threads_data[12]),
        sfThread_create(update_chunk, &threads_data[13]), sfThread_create(
        update_chunk, &threads_data[14]), sfThread_create(update_chunk,
        &threads_data[15])};
    int current_thread = 0;

    for (int i = 0; i != 1024; i++) {
        if (is_vertexarray_visible(app->game_view, chunks[i]->bounding_box,
            sfTransformable_getPosition(chunks[i]->transform))) {
            sfThread_wait(threads[current_thread]);
            threads_data[current_thread].chunk = chunks[i];
            threads_data[current_thread].chunk_index = chunks[i];
            sfThread_launch(threads[current_thread]);
            current_thread++;
            if (current_thread == 16)
                current_thread = 0;
        }
    }
    for (int i = 0; i != 16; i++)
        sfThread_wait(threads[i]);
}

void draw_game(app_t *app)
{
    sfRenderWindow_clear(app->window, sfBlack);
    draw_chunks(app->game_ressources->map, app);
    draw_hotbar(app);
    sfRenderWindow_setView(app->window, app->view);
    sfRenderWindow_drawSprite(app->window,
        app->game_ressources->player->health_sprite, NULL);
    sfRenderWindow_setView(app->window, app->game_view);
}
