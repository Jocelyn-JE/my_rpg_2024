/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** destroy_app
*/
#include "../../include/rpg.h"

static void free_player(player_t *player)
{
    sfTexture_destroy(player->health_texture);
    sfSprite_destroy(player->health_sprite);
    free(player);
}

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
    free_player(game->player);
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
    for (int i = 0; i < 22; i++) {
        sfSprite_destroy(app->button[i].sprite);
        sfTexture_destroy(app->button[i].texture);
    }
    for (int i = 0; i < 39; i++)
        sfText_destroy(app->text[i].text);
    for (int i = 0; app->sound->sounds[i]; i++) {
        sfSound_destroy(app->sound->sounds[i]);
        sfSoundBuffer_destroy(app->sound->sound_buffers[i]);
    }
    for (int i = 0; app->sound->music[i]; i++)
        sfMusic_destroy(app->sound->music[i]);
    free(app->sound->sound_buffers);
    free(app->sound->sounds);
    free(app->sound);
    free(app->button);
    free(app->text);
}

static void free_fonts(sfFont **fonts)
{
    for (int i = 0; fonts[i]; i++)
        sfFont_destroy(fonts[i]);
    free(fonts);
}

static void free_menu(menu_t *menu)
{
    sfTexture_destroy(menu->backtexture);
    sfSprite_destroy(menu->backsprite);
    sfTexture_destroy(menu->helptexture);
    sfSprite_destroy(menu->helpsprite);
    free(menu);
}

void destroy_app(app_t *app)
{
    sfRenderWindow_destroy(app->window);
    sfView_destroy(app->game_view);
    sfView_destroy(app->view);
    sfClock_destroy(app->game_clock);
    destroy_game_ressources(app->game_ressources);
    free_menu(app->menu);
    free_inventory(app->inventory);
    free_fonts(app->fonts);
    free_ui(app);
    free(app->debug_options);
    free(app);
}
