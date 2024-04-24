/*
** EPITECH PROJECT, 2024
** project
** File description:
** splash_screen
*/

#include "rpg.h"

// static void animation_splash(app_t *app)
// {
//     sfColor color = sfSprite_getColor(app->logo->sprite);

//     for (int i = 1; i != 255; i++) {
//         color.a = 0 + i;
//         sfSprite_setColor(app->logo->sprite, color);
//         usleep(20000);
//     }
// }

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
    // animation_splash(app);
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
        usleep(5000000);
        menu(a);
    }
}
