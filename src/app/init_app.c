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

static sfView *create_view(sfVector2f res)
{
    sfView *view = sfView_create();

    sfView_setCenter(view, (sfVector2f){res.x / 2, res.y / 2});
    sfView_setSize(view, (sfVector2f){res.x, res.y});
    get_letterbox_view(view, (sfVector2u){res.x, res.y});
    return view;
}

static player_t *init_player(void)
{
    player_t *new_player = malloc(sizeof(player_t));

    new_player->pos.x = 410.0f;
    new_player->pos.y = 194.0f;
    return new_player;
}

static void spawn_zombies(list_t **list, chunk_t **map, block_t **types)
{
    sfVector2i pos = {0, 0};

    for (int i = 0; i < 512 * 512; i++) {
        pos = get_block_coordinates_from_index(i);
        if (!get_block((sfVector3f){pos.x, pos.y, 2}, types,
            map)->solid && get_block((sfVector3f){pos.x, pos.y, 1},
            types, map)->solid && get_random_nb(0, 1000) == 0)
            list_add(list, create_entity((sfVector2f){pos.x, pos.y},
                e_zombie));
    }
}

static game_t *init_game(void)
{
    game_t *new_game = malloc(sizeof(game_t));
    int map_fd = open("tests/map.ioc", O_RDONLY);

    new_game->block_types = init_blocks();
    new_game->block_atlas = sfTexture_createFromFile(
        "assets/textures/atlas.png", NULL);
    new_game->map = malloc(sizeof(chunk_t *) * (32 * 32 + 1));
    new_game->entities = NULL;
    new_game->player = init_player();
    list_add(&new_game->entities, create_entity(new_game->player->pos,
        e_player));
    list_add(&new_game->entities, create_entity(new_game->player->pos,
        e_zombie));
    for (int i = 0; i != 32 * 32; i++)
        new_game->map[i] = create_chunk(new_game->block_types, map_fd);
    new_game->map[1024] = NULL;
    spawn_zombies(&new_game->entities, new_game->map, new_game->block_types);
    close(map_fd);
    place_chunks(new_game->map);
    return new_game;
}

static sfFont **init_fonts(void)
{
    sfFont **fonts = malloc(sizeof(sfFont *) * 3);

    fonts[0] = sfFont_createFromFile(
        "assets/fonts/minecraft-font/MinecraftBold-nMK1.otf");
    fonts[1] = sfFont_createFromFile(
        "assets/fonts/minecraft-font/MinecraftRegular-Bmg3.otf");
    fonts[2] = NULL;
    return fonts;
}

static void init_button(app_t *app)
{
    app->button = malloc(22 * sizeof(button_t));
    set_button(app);
    set_button_setting(app);
    set_button_sound(app);
    set_button_video(app);
}

static void init_text(app_t *app)
{
    app->text = calloc(39, sizeof(button_t));
    text_setting(app);
    text_sound(app);
    text_video(app);
    text_menu(app);
}

app_t *create_app(void)
{
    app_t *app = malloc(sizeof(app_t));
    sfVector2f res = {1920, 1080};

    srand(time(NULL));
    app->logo = create_logo();
    app->sound = init_sound();
    app->game_clock = sfClock_create();
    app->game_ressources = init_game();
    app->game_view = create_view(res);
    app->view = create_view(res);
    app->window = create_window(res, 32, sfDefaultStyle);
    app->zoom = 1.0f;
    app->debug_options = init_debug_options();
    app->fonts = init_fonts();
    app->menu = create_menu();
    init_button(app);
    init_text(app);
    sfRenderWindow_setView(app->window, app->view);
    setup_inventory(app);
    return app;
}
