/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** setting
*/

#include "rpg.h"

sfSprite* create_sprite(const char *texture_path,
    sfVector2f position, sfVector2f scale)
{
    sfSprite* sprite = sfSprite_create();
    sfTexture* texture = sfTexture_createFromFile(texture_path, NULL);

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, position);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

static void draw_setting_buton(app_t *app)
{
    sfVector2f pos_back = {0, 0};
    sfVector2f scale_back = {2.25, 2.25};
    sfSprite* sprite = create_sprite("assets/widgets"
        "/set_back.png", pos_back, scale_back);

    sfRenderWindow_drawSprite(app->window, sprite, NULL);
    sfSprite_destroy(sprite);
    sfRenderWindow_drawText(app->window, app->text[3].text, NULL);
    sfRenderWindow_drawSprite(app->window, app->buton[3].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[4].text, NULL);
    sfRenderWindow_drawSprite(app->window, app->buton[4].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[5].text, NULL);
    sfRenderWindow_drawSprite(app->window, app->buton[5].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[6].text, NULL);
}

void destroy_menu(app_t *app)
{
    sfSprite_destroy(app->menu->backsprite);
    sfSprite_destroy(app->logo->sprite);
    sfSprite_destroy(app->buton[0].sprite);
    sfSprite_destroy(app->buton[1].sprite);
    sfSprite_destroy(app->buton[2].sprite);
    sfRenderWindow_drawText(app->window, app->text[0].text, NULL);
    sfRenderWindow_drawText(app->window, app->text[1].text, NULL);
    sfRenderWindow_drawText(app->window, app->text[2].text, NULL);
}

void setting(app_t *app)
{
    set_buton_setting(app);
    text_setting(app);
    while (sfRenderWindow_isOpen(app->window)) {
        poll_events(app, &app->event->event);
        sfRenderWindow_clear(app->window, sfBlack);
        draw_setting_buton(app);
        sfRenderWindow_display(app->window);
    }
}
