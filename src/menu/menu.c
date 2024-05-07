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
    sfRenderWindow_drawText(app->window, app->text[0].text, NULL);
    sfRenderWindow_drawSprite(app->window, app->buton[1].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[1].text, NULL);
    sfRenderWindow_drawSprite(app->window, app->buton[2].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[2].text, NULL);
}

static void handle_events_menu(app_t *app, sfEvent *event)
{
    sfMouseButtonEvent mouse_event = event->mouseButton;

    if (event->type == sfEvtMouseButtonPressed) {
        if (mouse_event.button == sfMouseLeft) {
            handle_button_click(app, &mouse_event);
        }
    }
}

void poll_events_menu(app_t *app, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(app->window, event) &&
        sfRenderWindow_hasFocus(app->window)) {
        handle_events_menu(app, event);
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(app->window);
    }
}

void menu(app_t *app)
{
    sfTexture_destroy(app->logo->texture);
    sfSprite_destroy(app->logo->sprite);
    set_menu(app);
    set_buton(app);
    set_title(app);
    text_menu(app);
    set_sound(app);
    while (sfRenderWindow_isOpen(app->window)) {
        poll_events_menu(app, &app->event->event);
        sfRenderWindow_clear(app->window, sfBlack);
        sfRenderWindow_drawSprite(app->window, app->menu->backsprite, NULL);
        sfRenderWindow_drawSprite(app->window, app->logo->sprite, NULL);
        draw_buton(app);
        sfRenderWindow_display(app->window);
    }
}
