/*
** EPITECH PROJECT, 2024
** project
** File description:
** splash_screen
*/

#include "rpg.h"

static void create_logo(app_t *app)
{
    sfVector2f pos_logo = {127, -100};
    sfVector2f scale_logo = {1, 1};

    app->logo->sprite = sfSprite_create();
    app->logo->texture = sfTexture_createFromFile("asset"
    "s/widgets/logo.png", NULL);
    sfSprite_setScale(app->logo->sprite, scale_logo);
    sfSprite_setPosition(app->logo->sprite, pos_logo);
    sfSprite_setTexture(app->logo->sprite, app->logo->texture, sfTrue);
}

static void animation_splash(app_t *app, sfClock *clock)
{
    sfTime finished = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asSeconds(finished);

    if (seconds < 0.03 || app->logo->color.a >= 254)
        return;
    if (app->logo->color.a < 255) {
        app->logo->color.a += 2;
        if (app->logo->color.a > 255)
            app->logo->color.a = 255;
        sfSprite_setColor(app->logo->sprite, app->logo->color);
        sfClock_restart(clock);
    }
}

void splash_screen(app_t *app)
{
    sfView *view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    static sfClock *clock = NULL;

    if (clock == NULL)
        clock = sfClock_create();
    create_logo(app);
    app->logo->color = sfSprite_getColor(app->logo->sprite);
    app->logo->color.a = 0;
    sfRenderWindow_setView(app->window, view);
    while (sfRenderWindow_isOpen(app->window)) {
        poll_events(app, &app->event->event);
        sfRenderWindow_clear(app->window, sfWhite);
        animation_splash(app, clock);
        sfRenderWindow_drawSprite(app->window, app->logo->sprite, NULL);
        sfRenderWindow_display(app->window);
        //menu(a);
    }
}
