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
    sfRenderWindow_clear(app->window, sfBlack);
    sfRenderWindow_drawSprite(app->window, app->menu->backsprite, NULL);
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

    if (is_on_sprite(app->button[3].sprite, mouse_pos))
        return switch_to_sound_settings(app);
    if (is_on_sprite(app->button[4].sprite, mouse_pos))
        return switch_to_video_settings(app);
    if (is_on_sprite(app->button[5].sprite, mouse_pos))
        return switch_to_menu(app);
}

static void handle_events_setting(app_t *app, sfEvent *event)
{
    sfMouseButtonEvent mouse_event = event->mouseButton;

    if (event->type == sfEvtMouseButtonPressed) {
        if (mouse_event.button == sfMouseLeft)
            handle_setting_click(app, &mouse_event);
    }
}

static void poll_events_setting(app_t *app, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(app->window, event) &&
        sfRenderWindow_hasFocus(app->window)) {
        handle_events_setting(app, event);
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(app->window);
        if (event->type == sfEvtResized)
            get_letterbox_view(app->view,
                (sfVector2u){event->size.width, event->size.height});
    }
    sfRenderWindow_setView(app->window, app->view);
}

void switch_to_settings(app_t *app)
{
    app->event_handler = poll_events_setting;
    app->draw_function = draw_setting_button;
    sfTexture_destroy(app->menu->backtexture);
    app->menu->backtexture = sfTexture_createFromFile("assets/widgets/set_back"
        ".png", NULL);
    sfTexture_setRepeated(app->menu->backtexture, true);
    sfSprite_setTexture(app->menu->backsprite, app->menu->backtexture,
        sfFalse);
    get_letterbox_view(app->view, sfRenderWindow_getSize(app->window));
}
