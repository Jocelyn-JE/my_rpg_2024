/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** parameter_sound
*/

#include "rpg.h"

static void draw_setting_buton(app_t *app)
{
    sfVector2f pos_back = {0, 0};
    sfVector2f scale_back = {2.25, 2.25};
    sfSprite* sprite = create_sprite("assets/widgets"
        "/set_back.png", pos_back, scale_back);

    sfRenderWindow_drawSprite(app->window, sprite, NULL);
    sfSprite_destroy(sprite);
    sfRenderWindow_drawSprite(app->window, app->buton[6].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[7].text, NULL);
    sfRenderWindow_drawSprite(app->window, app->buton[7].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[8].text, NULL);
    sfRenderWindow_drawSprite(app->window, app->buton[8].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[9].text, NULL);
}

static void handle_volume_click(app_t *app, sfMouseButtonEvent *mouse_event)
{
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(app->window,
        (sfVector2i){mouse_event->x, mouse_event->y}, NULL);

    if (sfFloatRect_contains(&app->buton[6].hitbox,
        mouse_pos.x, mouse_pos.y))
        app->sound->volume += 1;
    if (sfFloatRect_contains(&app->buton[7].hitbox,
        mouse_pos.x, mouse_pos.y))
        app->sound->volume -= 1;
    if (sfFloatRect_contains(&app->buton[5].hitbox,
        mouse_pos.x, mouse_pos.y))
        setting(app);
}

static void handle_events_volume(app_t *app, sfEvent *event)
{
    sfMouseButtonEvent mouse_event = event->mouseButton;

    if (event->type == sfEvtMouseButtonPressed) {
        if (mouse_event.button == sfMouseLeft) {
            handle_volume_click(app, &mouse_event);
        }
    }
}

void poll_events_volume(app_t *app, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(app->window, event) &&
        sfRenderWindow_hasFocus(app->window)) {
        handle_events_volume(app, event);
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(app->window);
    }
}

static void volume_value(app_t *app)
{
    char volume_str[100000];

    sprintf(volume_str, "%d", app->sound->volume);
    set_text(app, (sfVector2f){880, 307}, volume_str, 13);
    sfRenderWindow_drawText(app->window, app->text[13].text, NULL);
}

void parameter_sound(app_t *app)
{
    text_sound(app);
    set_buton_sound(app);
    while (sfRenderWindow_isOpen(app->window)) {
        poll_events_volume(app, &app->event->event);
        sfRenderWindow_clear(app->window, sfBlack);
        volume_value(app);
        draw_setting_buton(app);
        sfRenderWindow_display(app->window);
    }
}
