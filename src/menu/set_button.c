/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** set_button
*/

#include "rpg.h"

static void create_buton_sprite(app_t *app, int index, const char *filename)
{
    app->buton[index].sprite = sfSprite_create();
    app->buton[index].texture = sfTexture_createFromFile(filename, NULL);
    sfSprite_setTexture(app->buton[index].sprite,
        app->buton[index].texture, sfTrue);
}

static void set_buton_scale(app_t *app, int index, sfVector2f scale)
{
    app->buton[index].scale = scale;
    sfSprite_setScale(app->buton[index].sprite, app->buton[index].scale);
}

static void set_buton_position(app_t *app, int index, sfVector2f position)
{
    sfSprite_setPosition(app->buton[index].sprite, position);
}

static void set_buton_hitbox(app_t *app, int index, sfFloatRect hitbox)
{
    app->buton[index].hitbox = hitbox;
}

static void buton(app_t *app, int index, int x, int y)
{
    sfVector2f pos_buton = {x, y};
    sfVector2f scale_buton = {0.4, 0.4};
    sfFloatRect hitbox = {x, y, 490.8, 48.8};

    create_buton_sprite(app, index, "assets/widgets/bouton.png");
    set_buton_scale(app, index, scale_buton);
    set_buton_position(app, index, pos_buton);
    set_buton_hitbox(app, index, hitbox);
}

void set_buton(app_t *app)
{
    buton(app, 0, 690, 500);
    buton(app, 1, 690, 650);
    buton(app, 2, 690, 800);
}

void set_buton_setting(app_t *app)
{
    buton(app, 3, 350, 500);
    buton(app, 4, 1050, 500);
    buton(app, 5, 690, 700);
}

void set_buton_video(app_t *app)
{
    buton(app, 6, 350, 500);
    buton(app, 7, 1050, 500);
    buton(app, 8, 690, 700);
}

void set_buton_sound(app_t *app)
{
    buton(app, 9, 350, 200);
    buton(app, 10, 1050, 200);
    buton(app, 11, 350, 350);
    buton(app, 12, 1050, 350);
    buton(app, 13, 350, 500);
    buton(app, 14, 1050, 500);
    buton(app, 15, 690, 700);
}
