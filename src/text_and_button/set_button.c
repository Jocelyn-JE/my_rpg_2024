/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** set_button
*/

#include "rpg.h"

static void create_button_sprite(app_t *app, int index, const char *filename)
{
    app->button[index].sprite = sfSprite_create();
    app->button[index].texture = sfTexture_createFromFile(filename, NULL);
    sfSprite_setTexture(app->button[index].sprite,
        app->button[index].texture, sfTrue);
}

static void set_button_scale(app_t *app, int index, sfVector2f scale)
{
    app->button[index].scale = scale;
    sfSprite_setScale(app->button[index].sprite, app->button[index].scale);
}

static void set_button_position(app_t *app, int index, sfVector2f position)
{
    sfSprite_setPosition(app->button[index].sprite, position);
}

static void set_button_hitbox(app_t *app, int index)
{
    app->button[index].hitbox = sfSprite_getGlobalBounds(
        app->button[index].sprite);
}

static void button(app_t *app, int index, int x, int y)
{
    sfVector2f pos_button = {x, y};
    sfVector2f scale_button = {0.4, 0.4};
    sfFloatRect hitbox = {x, y, 490.8, 48.8};

    create_button_sprite(app, index, "assets/widgets/bouton.png");
    set_button_scale(app, index, scale_button);
    set_button_hitbox(app, index);
    pos_button = (sfVector2f){x - hitbox.width / 2, y - hitbox.height / 2};
    set_button_position(app, index, pos_button);
    set_button_hitbox(app, index);
}

void set_button(app_t *app)
{
    app->button->largeur_fenetre = sfRenderWindow_getSize(app->window).x;
    app->button->hauteur_fenetre = sfRenderWindow_getSize(app->window).y;
    button(app, 0, 1920 / 2, 1080 / 2);
    button(app, 1, 1920 / 2, 1080 / 2 + 150);
    button(app, 2, 1920 / 2, 1080 / 2 + 300);
}

void set_button_setting(app_t *app)
{
    app->button->largeur_sprite =
        sfSprite_getGlobalBounds(app->button[0].sprite).width;
    app->button->hauteur_sprite =
        sfSprite_getGlobalBounds(app->button[0].sprite).height;
    button(app, 3, 1920 / 3, 1080 / 2);
    button(app, 4, 1920 / 3 * 2, 1080 / 2);
    button(app, 5, 1920 / 2, 1080 / 3 * 2);
}

void set_button_video(app_t *app)
{
    button(app, 6, (app->button->largeur_fenetre / 4) -
        (app->button->largeur_sprite / 2), 500);
    button(app, 7, (app->button->largeur_fenetre / 4 * 3) -
        (app->button->largeur_sprite / 2), 500);
    button(app, 8, (app->button->largeur_fenetre / 2) -
        (app->button->largeur_sprite / 2), 700);
}

void set_button_sound(app_t *app)
{
    button(app, 9, 350, 200);
    button(app, 10, 1050, 200);
    button(app, 11, 350, 350);
    button(app, 12, 1050, 350);
    button(app, 13, 350, 500);
    button(app, 14, 1050, 500);
    button(app, 15, 690, 700);
}
