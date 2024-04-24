/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** init_app
*/
#include "rpg.h"
#include <time.h>

static debug_t *init_debug_options(void)
{
    debug_t *debug_options = malloc(sizeof(debug_t));

    debug_options->bounding_box = false;
    debug_options->wireframe = false;
    debug_options->fps = false;
    return debug_options;
}

static void place_chunks(list_t *chunks, uint16_t size)
{
    int i = 0;
    int j = 0;
    chunk_t *data;

    for (list_t *current = chunks; current != NULL; current = current->next) {
        data = current->data;
        sfTransformable_move(data->transform, cartesian_to_isometric(16 * j,
            16 * i, 0, 100));
        i++;
        if (i == size) {
            j++;
            i = 0;
        }
    }
}

static sfView *create_view(sfVector2f res, uint16_t map_size[2])
{
    sfView *view = sfView_create();

    sfView_setSize(view, (sfVector2f){res.x, res.y});
    sfView_setCenter(view, cartesian_to_isometric(8 * map_size[0],
        8 * map_size[1], 0, 100));
    get_letterbox_view(view, (sfVector2f){res.x, res.y});
    return view;
}

app_t *create_app(void)
{
    app_t *app = malloc(sizeof(app_t));
    sfVector2f res = {1920, 1080};
    uint16_t map_size[2] = {16, 16};

    app->event = malloc(sizeof(event_t));
    app->logo = malloc(sizeof(logo_t));
    app->menu = malloc(sizeof(menu_t));
    app->buton = malloc(3 * sizeof(buton_t));
    srand(time(NULL));
    app->window = create_window(res, 32);
    app->block_atlas = sfTexture_createFromFile("assets/textures/atlas.png",
        NULL);
    app->map = NULL;
    for (int i = 0; i != map_size[0] * map_size[1]; i++)
        list_add(&app->map, create_chunk(app->block_atlas));
    place_chunks(app->map, map_size[1]);
    app->debug_options = init_debug_options();
    app->view = create_view(res, map_size);
    sfRenderWindow_setView(app->window, app->view);
    return app;
}
