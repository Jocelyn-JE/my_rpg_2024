/*
** EPITECH PROJECT, 2024
** kk
** File description:
** menu
*/

#include "rpg.h"

static void set_menu(app_t *app)
{
    sfVector2f pos_menu = {0, 0};
    sfVector2f scale_menu = {1, 1};

    app->menu->sprite = sfSprite_create();
    app->menu->texture = sfTexture_createFromFile("assets/widgets/"
        "menu.png", NULL);
    app->menu->scale = scale_menu;
    sfSprite_setScale(app->menu->sprite, app->menu->scale);
    sfSprite_setPosition(app->menu->sprite, pos_menu);
    sfSprite_setTexture(app->menu->sprite, app->menu->texture, sfTrue);
}

static void set_buton(app_t *app)
{
    sfVector2f pos_buton = {0, 0};
    sfVector2f scale_buton = {1, 1};

    app->menu->sprite = sfSprite_create();
    app->menu->texture = sfTexture_createFromFile("assets/widgets/"
        "buton.png", NULL);
    app->menu->scale = scale_buton;
    sfSprite_setScale(app->menu->sprite, app->menu->scale);
    sfSprite_setPosition(app->menu->sprite, pos_buton);
    sfSprite_setTexture(app->menu->sprite, app->menu->texture, sfTrue);
}

void menu(app_t *app)
{
    set_menu(app);
    set_buton(app);
}
