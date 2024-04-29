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

static int button_counter = 0;
void set_buton(app_t *app, int num_buttons)
{
    sfVector2f pos_buton[] = {{620, 300}, {620, 450}, {620, 600}};
    sfVector2f scale_buton = {0.4, 0.4};
    sfFloatRect hitbox = {213, 523, 1227, 122};

    for (int i = 0; i < num_buttons; i++) {
        create_buton_sprite(app, i, "assets/widgets/bouton.png");
        app->buton[i].number = ++button_counter;
        set_buton_scale(app, i, scale_buton);
        set_buton_position(app, i, pos_buton[i]);
        set_buton_hitbox(app, i, hitbox);
    }
}
