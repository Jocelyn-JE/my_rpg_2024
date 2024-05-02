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

    app->menu->backsprite = sfSprite_create();
    app->menu->backtexture = sfTexture_createFromFile("assets/widgets/"
        "menu.png", NULL);
    app->menu->backscale = scale_menu;
    sfSprite_setScale(app->menu->backsprite, app->menu->backscale);
    sfSprite_setPosition(app->menu->backsprite, pos_menu);
    sfSprite_setTexture(app->menu->backsprite, app->menu->backtexture, sfTrue);
}

void handle_button_click(app_t *app, sfMouseButtonEvent *mouse_event,
    int num_buttons)
{
    if (sfFloatRect_contains(&app->buton[0].hitbox,
        mouse_event->x, mouse_event->y)) {
        printf("Cliqué sur le bouton play\n");
    }
    if (sfFloatRect_contains(&app->buton[1].hitbox,
        mouse_event->x, mouse_event->y)) {
        printf("Cliqué sur le bouton setting\n");
    }
    if (sfFloatRect_contains(&app->buton[2].hitbox,
        mouse_event->x, mouse_event->y)) {
        exit (1);
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

static void draw_buton(app_t *app)
{
    sfRenderWindow_drawSprite(app->window, app->buton[0].sprite, NULL);
    sfRenderWindow_drawSprite(app->window, app->buton[1].sprite, NULL);
    sfRenderWindow_drawSprite(app->window, app->buton[2].sprite, NULL);
}

void menu(app_t *app)
{
    set_menu(app);
    set_buton(app);
    set_title(app);
    while (sfRenderWindow_isOpen(app->window)) {
        poll_events(app, &app->event->event);
        sfRenderWindow_clear(app->window, sfBlack);
        sfRenderWindow_drawSprite(app->window, app->menu->backsprite, NULL);
        sfRenderWindow_drawSprite(app->window, app->logo->sprite, NULL);
        draw_buton(app);
        assert(app->window != NULL);
        sfRenderWindow_display(app->window);
    }
}
