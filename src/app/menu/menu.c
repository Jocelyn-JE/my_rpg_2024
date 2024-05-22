/*
** EPITECH PROJECT, 2024
** kk
** File description:
** menu
*/

#include "rpg.h"

void switch_to_menu(app_t *app, scenes_t previous_scene)
{
    app->previous_scene = previous_scene;
    app->event_handler = manage_events_menu;
    app->draw_function = draw_menu;
    if (previous_scene != s_settings && previous_scene != s_menu)
        sfMusic_play(app->sound->music);
    sfTexture_destroy(app->menu->backtexture);
    app->menu->backtexture = sfTexture_createFromFile("assets/widgets/menu.png"
        , NULL);
    sfSprite_setTexture(app->menu->backsprite, app->menu->backtexture, sfTrue);
    sfSprite_setColor(app->logo->sprite, sfWhite);
    sfSprite_setPosition(app->logo->sprite, (sfVector2f){1920 / 2, 1080 / 4});
    get_letterbox_view(app->view, sfRenderWindow_getSize(app->window));
}

static void set_menu(menu_t *menu)
{
    sfVector2f pos_menu = {0, 0};
    sfVector2f scale_menu = {1.5, 1.5};

    menu->backsprite = sfSprite_create();
    menu->backtexture = sfTexture_createFromFile("assets/widgets/"
        "menu.png", NULL);
    sfSprite_setScale(menu->backsprite, scale_menu);
    sfSprite_setPosition(menu->backsprite, pos_menu);
    sfSprite_setTexture(menu->backsprite, menu->backtexture, sfTrue);
}

void draw_button(sfRenderWindow *window, sfSprite *sprite, sfText *text)
{
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_drawText(window, text, NULL);
}

void draw_menu(app_t *app)
{
    sfRenderWindow_clear(app->window, sfBlack);
    sfRenderWindow_drawSprite(app->window, app->menu->backsprite, NULL);
    sfRenderWindow_drawSprite(app->window, app->logo->sprite, NULL);
    draw_button(app->window, app->button[0].sprite, app->text[0].text);
    draw_button(app->window, app->button[1].sprite, app->text[1].text);
    draw_button(app->window, app->button[2].sprite, app->text[2].text);
}

menu_t *create_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));

    set_menu(menu);
    return menu;
}
