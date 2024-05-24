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

static void set_button_position(app_t *app, int index, sfVector2f position)
{
    sfSprite_setPosition(app->button[index].sprite, position);
}

static void button(app_t *app, int index, int x, int y)
{
    sfVector2f pos_button = {x, y};
    sfFloatRect hitbox;

    create_button_sprite(app, index, "assets/widgets/button.png");
    sfSprite_setTextureRect(app->button[index].sprite, (sfIntRect){0, 0, 200,
        20});
    sfSprite_setScale(app->button[index].sprite, (sfVector2f){2.5, 2.5});
    hitbox = sfSprite_getGlobalBounds(app->button[index].sprite);
    pos_button = (sfVector2f){x - hitbox.width / 2, y - hitbox.height / 2};
    set_button_position(app, index, pos_button);
}

void set_button(app_t *app)
{
    button(app, 0, 1920 / 2, 1080 / 2);
    button(app, 1, 1920 / 2, 1080 / 2 + 150);
    button(app, 2, 1920 / 2, 1080 / 2 + 300);
    button(app, 17, 1920 / 2, 1080 / 2);
    button(app, 18, 1920 / 2, 1080 / 2 - 60);
    button(app, 19, 1920 / 2, 1080 / 2 + 60);
    button(app, 20, 1920 / 2, 1080 / 2 + 120);
    button(app, 21, 1920 / 2, 1080 / 3 * 2.5);
}

void set_button_setting(app_t *app)
{
    button(app, 3, 1920 / 3, 1080 / 2);
    button(app, 4, 1920 / 3 * 2, 1080 / 2);
    button(app, 5, 1920 / 2, 1080 / 3 * 2);
}

void set_button_video(app_t *app)
{
    button(app, 16, 1920 / 2, 1080 / 3 * 1.25);
    button(app, 6, 1920 / 2, 1080 / 3 * 1.5);
    button(app, 7, 1920 / 2, 1080 / 3 * 1.75);
    button(app, 8, 1920 / 2, 1080 / 3 * 2);
}

void set_button_sound(app_t *app)
{
    button(app, 9, 1920 / 3, 1080 / 3 - 100);
    button(app, 10, 1920 / 3 * 2, 1080 / 3 - 100);
    button(app, 13, 1920 / 3, 1080 / 3 + 50);
    button(app, 14, 1920 / 3 * 2, 1080 / 3 + 50);
    button(app, 11, 1920 / 3, 1080 / 3 + 200);
    button(app, 12, 1920 / 3 * 2, 1080 / 3 + 200);
    button(app, 15, 1920 / 2, 1080 / 3 * 2);
}
