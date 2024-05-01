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

static void set_buton_play(app_t *app, int index)
{
    sfVector2f pos_buton = {620, 300};
    sfVector2f scale_buton = {0.4, 0.4};
    sfFloatRect hitbox = {213, 523, 1227, 122};

    create_buton_sprite(app, index, "assets/widgets/bouton.png");
    set_buton_scale(app, index, scale_buton);
    set_buton_position(app, index, pos_buton);
    set_buton_hitbox(app, index, hitbox);
}

static void set_buton_setting(app_t *app, int index)
{
    sfVector2f pos_buton = {620, 450};
    sfVector2f scale_buton = {0.4, 0.4};
    sfFloatRect hitbox = {213, 523, 1227, 122};

    create_buton_sprite(app, index, "assets/widgets/bouton.png");
    set_buton_scale(app, index, scale_buton);
    set_buton_position(app, index, pos_buton);
    set_buton_hitbox(app, index, hitbox);
}

static void set_buton_leave(app_t *app, int index)
{
    sfVector2f pos_buton = {620, 600};
    sfVector2f scale_buton = {0.4, 0.4};
    sfFloatRect hitbox = {213, 523, 1227, 122};

    create_buton_sprite(app, index, "assets/widgets/bouton.png");
    set_buton_scale(app, index, scale_buton);
    set_buton_position(app, index, pos_buton);
    set_buton_hitbox(app, index, hitbox);
}

void set_buton(app_t *app)
{
    set_buton_play(app, 0);
    set_buton_setting(app, 1);
    set_buton_leave(app, 2);


    // for (int i = 0; i < num_buttons; i++) {
    //     create_buton_sprite(app, i, "assets/widgets/bouton.png");
    //     set_buton_scale(app, i, scale_buton);
    //     set_buton_position(app, i, pos_buton[i]);
    //     set_buton_hitbox(app, i, hitbox);
    // }
}
