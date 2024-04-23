/*
** EPITECH PROJECT, 2024
** project
** File description:
** splash_screen
*/

#include "rpg.h"

static void modify_opacity(app_t *app)
{
    sfColor color = sfSprite_getColor(app->logo->sprite);
    color.a = 255;
    sfSprite_setColor(app->logo->sprite, color);
}

static void create_logo(app_t *app)
{
    sfVector2f scale_logo = {0.1, 0.1};

    app->logo->sprite = sfSprite_create();
    app->logo->texture =
    sfTexture_createFromFile("assets/widgets/logo.png", NULL);
    sfSprite_setScale(app->logo->sprite, scale_logo);
    sfSprite_setTexture(app->logo->sprite, app->logo->texture, sfTrue);
    modify_opacity(app);
}

void splash_screen(app_t *a)
{
    sfView *view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    sfRenderWindow_setView(a->window, view);
    create_logo(a);
    while (sfRenderWindow_isOpen(a->window)) {
        poll_events(a, &a->event->event);
        sfRenderWindow_clear(a->window, sfWhite);
        sfRenderWindow_drawSprite(a->window, a->logo->sprite, NULL);
        sfRenderWindow_display(a->window);
    }
}
