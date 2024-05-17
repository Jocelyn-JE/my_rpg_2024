/*
** EPITECH PROJECT, 2024
** kk
** File description:
** menu
*/

#include "rpg.h"

static void set_menu(menu_t *menu)
{
    sfVector2f pos_menu = {0, 0};
    sfVector2f scale_menu = {1.5, 1.5};

    menu->backsprite = sfSprite_create();
    menu->backtexture = sfTexture_createFromFile("assets/widgets/"
        "menu.png", NULL);
    menu->backscale = scale_menu;
    sfSprite_setScale(menu->backsprite, menu->backscale);
    sfSprite_setPosition(menu->backsprite, pos_menu);
    sfSprite_setTexture(menu->backsprite, menu->backtexture, sfTrue);
}

static void set_title(logo_t *logo)
{
    sfVector2f pos_title = {127, -300};
    sfVector2f scale_title = {1, 1};

    logo->sprite = sfSprite_create();
    logo->texture = sfTexture_createFromFile("assets/widgets/"
        "logo.png", NULL);
    logo->scale = scale_title;
    sfSprite_setScale(logo->sprite, logo->scale);
    sfSprite_setPosition(logo->sprite, pos_title);
    sfSprite_setTexture(logo->sprite, logo->texture, sfTrue);
}

static void draw_button(app_t *app)
{
    sfRenderWindow_drawSprite(app->window, app->menu->backsprite, NULL);
    sfRenderWindow_drawSprite(app->window, app->logo->sprite, NULL);
    sfRenderWindow_drawSprite(app->window, app->button[0].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[0].text, NULL);
    sfRenderWindow_drawSprite(app->window, app->button[1].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[1].text, NULL);
    sfRenderWindow_drawSprite(app->window, app->button[2].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[2].text, NULL);
}

void set_menu_sprite(app_t *app)
{
    set_menu(app->menu);
    set_button(app);
    set_title(app->logo);
    text_menu(app);
}

void menu(app_t *app)
{
    sfEvent events;

    set_menu_sprite(app);
    while (sfRenderWindow_isOpen(app->window)) {
        manage_events_menu(app, &events);
        sfRenderWindow_clear(app->window, sfBlack);
        draw_button(app);
        sfRenderWindow_display(app->window);
    }
}
