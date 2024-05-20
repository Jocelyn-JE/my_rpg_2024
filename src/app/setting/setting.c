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

static void draw_setting_button(app_t *app)
{
    sfVector2f pos_back = {0, 0};
    sfVector2f scale_back = {2.25, 2.25};
    sfSprite* sprite = create_sprite("assets/widgets"
        "/set_back.png", pos_back, scale_back);

    sfRenderWindow_drawSprite(app->window, sprite, NULL);
    sfSprite_destroy(sprite);
    sfRenderWindow_drawText(app->window, app->text[3].text, NULL);
    sfRenderWindow_drawSprite(app->window, app->button[3].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[4].text, NULL);
    sfRenderWindow_drawSprite(app->window, app->button[4].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[5].text, NULL);
    sfRenderWindow_drawSprite(app->window, app->button[5].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[6].text, NULL);
}

static void handle_setting_click(app_t *app, sfMouseButtonEvent *mouse_event)
{
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(app->window,
        (sfVector2i){mouse_event->x, mouse_event->y}, NULL);

    if (sfFloatRect_contains(&app->button[3].hitbox,
        mouse_pos.x, mouse_pos.y))
        parameter_sound(app);
    if (sfFloatRect_contains(&app->button[4].hitbox,
        mouse_pos.x, mouse_pos.y))
        parameter_video(app);
    if (sfFloatRect_contains(&app->button[5].hitbox,
        mouse_pos.x, mouse_pos.y));
}

static void handle_events_setting(app_t *app, sfEvent *event)
{
    sfMouseButtonEvent mouse_event = event->mouseButton;

    if (event->type == sfEvtMouseButtonPressed) {
        if (mouse_event.button == sfMouseLeft) {
            handle_setting_click(app, &mouse_event);
        }
    }
}

void poll_events_setting(app_t *app, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(app->window, event) &&
        sfRenderWindow_hasFocus(app->window)) {
        handle_events_setting(app, event);
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(app->window);
    }
}

void destroy_menu(app_t *app)
{
    sfSprite_destroy(app->menu->backsprite);
    sfSprite_destroy(app->logo->sprite);
    sfSprite_destroy(app->button[0].sprite);
    sfSprite_destroy(app->button[1].sprite);
    sfSprite_destroy(app->button[2].sprite);
    sfRenderWindow_drawText(app->window, app->text[0].text, NULL);
    sfRenderWindow_drawText(app->window, app->text[1].text, NULL);
    sfRenderWindow_drawText(app->window, app->text[2].text, NULL);
}

void setting(app_t *app)
{
    sfEvent events;

    set_button_setting(app);
    text_setting(app);
    while (sfRenderWindow_isOpen(app->window)) {
        poll_events_setting(app, &events);
        sfRenderWindow_clear(app->window, sfBlack);
        draw_setting_button(app);
        sfRenderWindow_display(app->window);
    }
}
