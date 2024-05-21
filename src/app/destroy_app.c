/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** destroy_app
*/
#include "../../include/rpg.h"

static void destroy_game_ressources(game_t *game)
{
    sfTexture_destroy(game->block_atlas);
    for (int i = 0; game->map[i] != NULL; i++)
        destroy_chunk(game->map[i]);
    free(game->map);
    free_list(game->entities, destroy_entity);
    for (int i = 0; game->block_types[i] != NULL; i++)
        destroy_block(game->block_types[i]);
    free(game->block_types);
    free(game->player);
    free(game);
}

static void free_logo(logo_t *logo)
{
    sfSprite_destroy(logo->sprite);
    sfTexture_destroy(logo->texture);
    free(logo);
}

static void free_ui(app_t *app)
{
    free_logo(app->logo);
    free(app->button);
    free(app->menu);
    free(app->sound);
    free(app->text);
}

void destroy_app(app_t *app)
{
    sfRenderWindow_destroy(app->window);
    sfView_destroy(app->game_view);
    sfView_destroy(app->view);
    sfClock_destroy(app->game_clock);
    destroy_game_ressources(app->game_ressources);
    free_inventory(app->inventory);
    sfFont_destroy(app->fonts[0]);
    free_ui(app);
    free(app->fonts);
    free(app->debug_options);
    free(app);
}
