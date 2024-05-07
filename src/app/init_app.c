/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** init_app
*/
#include "rpg.h"
#include <time.h>
#include "blocks.h"

static debug_t *init_debug_options(void)
{
    debug_t *debug_options = malloc(sizeof(debug_t));

    debug_options->bounding_box = false;
    debug_options->fps = false;
    return debug_options;
}

static void place_chunks(chunk_t **chunks)
{
    int j = 0;

    for (int i = 0; chunks[i] != NULL; i++) {
        if (i % 32 == 0)
            j++;
        sfTransformable_move(chunks[i]->transform,
            cartesian_to_isometric(16 * j, 16 * (i % 32), 0, 100));
    }
}

static sfView *create_view(sfVector2f res, sfVector2f pos)
{
    sfView *view = sfView_create();

    sfView_setSize(view, (sfVector2f){res.x, res.y});
    sfView_setCenter(view, cartesian_to_isometric(pos.x, pos.y, 0, 100));
    get_letterbox_view(view, (sfVector2f){res.x, res.y});
    return view;
}

static player_t *init_player(void)
{
    player_t *new_player = malloc(sizeof(player_t));

    new_player->pos.x = 1.0f;
    new_player->pos.y = 510.0f;
    return new_player;
}

static game_t *init_game(void)
{
    game_t *new_game = malloc(sizeof(game_t));
    int map_fd = open("tests/fmap.ioc", O_RDONLY);

    new_game->block_types = init_blocks();
    new_game->block_atlas = sfTexture_createFromFile(
        "assets/textures/atlas.png", NULL);
    new_game->map = malloc(sizeof(chunk_t *) * (32 * 32 + 1));
    new_game->entities = NULL;
    new_game->player = init_player();
    list_add(&new_game->entities, create_entity(new_game->player->pos,
        e_player));
    for (int i = 0; i != 32 * 32; i++)
        new_game->map[i] = create_chunk(new_game->block_atlas,
            new_game->block_types, map_fd);
    new_game->map[1024] = NULL;
    place_chunks(new_game->map);
    return new_game;
}

app_t *create_app(void)
{
    app_t *app = malloc(sizeof(app_t));
    sfVector2f res = {1920, 1080};

    srand(time(NULL));
    app->game_clock = sfClock_create();
    app->game_ressources = init_game();
    app->debug_options = init_debug_options();
    app->view = create_view(res, app->game_ressources->player->pos);
    app->window = create_window(res, 32);
    sfRenderWindow_setView(app->window, app->view);
    return app;
}
