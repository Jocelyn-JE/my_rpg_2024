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
    for (int i = 9; i != 16; i++) {
        sfRenderWindow_drawSprite(app->window, app->buton[i].sprite, NULL);
    }
    for (int i = 10; i != 23; i++) {
        sfRenderWindow_drawText(app->window, app->text[i].text, NULL);
    }
}

static void volume_value(app_t *app)
{
    char volume_general[100];
    char volume_effect[100];
    char volume_music[100];

    snprintf(volume_general, sizeof(volume_general), "%d",
        app->sound->volume_general);
    sfText_destroy(app->text[13].text);
    set_text(app, (sfVector2f){945, 207}, volume_general, 13);
    snprintf(volume_effect, sizeof(volume_effect), "%d",
        app->sound->volume_effect);
    sfText_destroy(app->text[17].text);
    set_text(app, (sfVector2f){945, 357}, volume_effect, 17);
    snprintf(volume_music, sizeof(volume_music), "%d",
        app->sound->volume_music);
    sfText_destroy(app->text[21].text);
    set_text(app, (sfVector2f){945, 507}, volume_music, 21);
}

static void handle_effect_music(app_t *app, sfVector2f mouse_pos)
{
    if (sfFloatRect_contains(&app->buton[11].hitbox,
        mouse_pos.x, mouse_pos.y)) {
        if (app->sound->volume_effect > 0)
            app->sound->volume_effect -= 1;
    }
    if (sfFloatRect_contains(&app->buton[12].hitbox,
        mouse_pos.x, mouse_pos.y)) {
        if (app->sound->volume_effect < 100)
            app->sound->volume_effect += 1;
    }
    if (sfFloatRect_contains(&app->buton[13].hitbox,
        mouse_pos.x, mouse_pos.y)) {
        if (app->sound->volume_music > 0)
            app->sound->volume_music -= 1;
    }
    if (sfFloatRect_contains(&app->buton[14].hitbox,
        mouse_pos.x, mouse_pos.y)) {
        if (app->sound->volume_music < 100)
            app->sound->volume_music += 1;
    }
}

static void handle_volume_click(app_t *app, sfMouseButtonEvent *mouse_event)
{
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(app->window,
        (sfVector2i){mouse_event->x, mouse_event->y}, NULL);

    if (sfFloatRect_contains(&app->buton[9].hitbox,
        mouse_pos.x, mouse_pos.y)) {
        if (app->sound->volume_general > 0)
            app->sound->volume_general -= 1;
    }
    if (sfFloatRect_contains(&app->buton[10].hitbox,
        mouse_pos.x, mouse_pos.y)) {
        if (app->sound->volume_general < 100)
            app->sound->volume_general += 1;
    }
    if (sfFloatRect_contains(&app->buton[15].hitbox,
        mouse_pos.x, mouse_pos.y))
        setting(app);
    handle_effect_music(app, mouse_pos);
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
