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
    sfVector2f scale_menu = {1.5, 1.5};

    app->menu->sprite = sfSprite_create();
    app->menu->texture = sfTexture_createFromFile("assets/widgets/"
        "menu.png", NULL);
    app->menu->scale = scale_menu;
    sfSprite_setScale(app->menu->sprite, app->menu->scale);
    sfSprite_setPosition(app->menu->sprite, pos_menu);
    sfSprite_setTexture(app->menu->sprite, app->menu->texture, sfTrue);
}

static void set_buton(app_t *app, int num_buttons)
{
    sfVector2f pos_buton[] = {{620, 300}, {620, 450}, {620, 600}};
    sfVector2f scale_buton = {0.4, 0.4};

    for (int i = 0; i < num_buttons; i++) {
        app->buton[i].sprite = sfSprite_create();
        app->buton[i].texture = sfTexture_createFromFile("assets/widgets"
            "/bouton.png", NULL);
        app->buton[i].scale = scale_buton;
        sfSprite_setScale(app->buton[i].sprite, app->buton[i].scale);
        sfSprite_setPosition(app->buton[i].sprite, pos_buton[i]);
        sfSprite_setTexture(app->buton[i].sprite,
            app->buton[i].texture, sfTrue);
    }
}

static void set_title(app_t *app)
{
    sfVector2f pos_title = {127, -300};
    sfVector2f scale_title = {1, 1};

    app->logo->sprite = sfSprite_create();
    app->logo->texture = sfTexture_createFromFile("assets/widgets/"
        "logo.png", NULL);
    app->logo->scale = scale_title;
    sfSprite_setScale(app->logo->sprite, app->logo->scale);
    sfSprite_setPosition(app->logo->sprite, pos_title);
    sfSprite_setTexture(app->logo->sprite, app->logo->texture, sfTrue);
}

void menu(app_t *app)
{
    set_menu(app);
    set_buton(app, 3);
    set_title(app);
    while (sfRenderWindow_isOpen(app->window)) {
        poll_events(app, &app->event->event);
        sfRenderWindow_clear(app->window, sfBlack);
        sfRenderWindow_drawSprite(app->window, app->menu->sprite, NULL);
        sfRenderWindow_drawSprite(app->window, app->logo->sprite, NULL);
        for (int i = 0; i < 3; i++)
            sfRenderWindow_drawSprite(app->window, app->buton[i].sprite, NULL);
        sfRenderWindow_display(app->window);
    }
}
