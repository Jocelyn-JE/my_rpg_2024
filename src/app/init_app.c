/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** init_app
*/
#include "../../include/rpg.h"
#include <time.h>
#include "../../include/blocks.h"

static debug_t *init_debug_options(void)
{
    debug_t *debug_options = malloc(sizeof(debug_t));

    debug_options->bounding_box = false;
    debug_options->wireframe = false;
    debug_options->fps = false;
    return debug_options;
}

static void place_chunks(list_t *chunks)
{
    int i = 0;
    int j = 0;
    chunk_t *data;

    for (list_t *current = chunks; current != NULL; current = current->next) {
        data = current->data;
        sfTransformable_move(data->transform, cartesian_to_isometric(16 * j,
            16 * i, 0, 100));
        i++;
        if (i == 32) {
            j++;
            i = 0;
        }
    }
}

static sfView *create_view(sfVector2f res)
{
    sfView *view = sfView_create();

    sfView_setSize(view, (sfVector2f){res.x, res.y});
    sfView_setCenter(view, cartesian_to_isometric(8 * 32, 8 * 32, 0, 100));
    get_letterbox_view(view, (sfVector2f){res.x, res.y});
    return view;
}

app_t *create_app(void)
{
    app_t *app = malloc(sizeof(app_t));
    sfVector2f res = {1920, 1080};
    block_t **blocks = init_blocks();
    int map_fd = open("tests/map.ioc", O_RDONLY);

    srand(time(NULL));
    app->block_atlas = sfTexture_createFromFile("assets/textures/atlas.png",
        NULL);
    app->map = NULL;
    app->game_state = GAME;
    app->zoom = 1.0f;
    for (int i = 0; i != 32 * 32; i++)
        list_add(&app->map, create_chunk(app->block_atlas, blocks, map_fd));
    list_reverse(&app->map);
    place_chunks(app->map);
    app->debug_options = init_debug_options();
    app->view = create_view(res);
    app->window = create_window(res, 32);
    sfRenderWindow_setView(app->window, app->view);
    return app;
}
