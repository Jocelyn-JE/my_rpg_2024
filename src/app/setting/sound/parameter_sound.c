/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** parameter_sound
*/

#include "rpg.h"

static void draw_volume_settings(app_t *app)
{
    sfRenderWindow_clear(app->window, sfBlack);
    sfRenderWindow_drawSprite(app->window, app->menu->backsprite, NULL);
    for (int i = 9; i != 16; i++)
        sfRenderWindow_drawSprite(app->window, app->button[i].sprite, NULL);
    for (int i = 10; i != 23; i++)
        sfRenderWindow_drawText(app->window, app->text[i].text, NULL);
}

static void text_effect_sound(app_t *app)
{
    char volume_effect[9];

    snprintf(volume_effect, sizeof(volume_effect), "%d",
        app->sound->volume_effect);
    set_text(app, (sfVector2f){1920 / 2, 1080 / 3 + 150}, "Effects", 18);
    set_text(app, (sfVector2f){1920 / 3, 1080 / 3 + 200}, "Reduce", 19);
    set_text(app, (sfVector2f){1920 / 3 * 2, 1080 / 3 + 200}, "Increase", 20);
    set_text(app, (sfVector2f){1920 / 2, 1080 / 3 + 150}, volume_effect, 21);
    set_text(app, (sfVector2f){1920 / 2, 1080 / 3 * 2}, "Done", 22);
}

void text_sound(app_t *app)
{
    char volume_general[9];
    char volume_music[9];

    snprintf(volume_general, sizeof(volume_general), "%d",
        app->sound->volume_general);
    set_text(app, (sfVector2f){1920 / 2, 1080 / 3 - 150}, "General", 10);
    set_text(app, (sfVector2f){1920 / 3, 1080 / 3 - 100}, "Reduce", 11);
    set_text(app, (sfVector2f){1920 / 3 * 2, 1080 / 3 - 100}, "Increase", 12);
    set_text(app, (sfVector2f){1920 / 2, 1080 / 3 - 100}, volume_general, 13);
    snprintf(volume_music, sizeof(volume_music), "%d",
        app->sound->volume_music);
    set_text(app, (sfVector2f){1920 / 2, 1080 / 3}, "Music", 14);
    set_text(app, (sfVector2f){1920 / 3, 1080 / 3 + 50}, "Reduce", 15);
    set_text(app, (sfVector2f){1920 / 3 * 2, 1080 / 3 + 50}, "Increase", 16);
    set_text(app, (sfVector2f){1920 / 2, 1080 / 3}, volume_music, 17);
    text_effect_sound(app);
}

static void update_volume_text(app_t *app)
{
    char volume_general[4];
    char volume_effect[4];
    char volume_music[4];

    snprintf(volume_general, 4, "%d", app->sound->volume_general);
    update_text(app->text, (sfVector2f){1920 / 2, 1080 / 3 - 100},
        volume_general, 13);
    snprintf(volume_effect, 4, "%d", app->sound->volume_effect);
    update_text(app->text, (sfVector2f){1920 / 2, 1080 / 3 + 200},
        volume_effect, 21);
    snprintf(volume_music, 4, "%d", app->sound->volume_music);
    update_text(app->text, (sfVector2f){1920 / 2, 1080 / 3 + 50},
        volume_music, 17);
}

static void play_sound(app_t *app)
{
    for (int i = 0; app->sound->music[i]; i++)
        sfMusic_setVolume(app->sound->music[i], (app->sound->volume_general *
            app->sound->volume_music) / 100);
    sfSound_setVolume(app->sound->sounds[0], (app->sound->volume_general *
        app->sound->volume_effect) / 100);
    sfSound_setVolume(app->sound->sounds[1], (app->sound->volume_general *
        app->sound->volume_effect) / 100);
    sfSound_setVolume(app->sound->sounds[2], (app->sound->volume_general *
        app->sound->volume_effect) / 100);
    sfSound_setVolume(app->sound->sounds[3], (app->sound->volume_general *
        app->sound->volume_effect) / 100);
    sfSound_play(app->sound->sounds[0]);
}

static void handle_effect_music(app_t *app, sfVector2f mouse_pos)
{
    if (is_on_sprite(app->button[11].sprite, mouse_pos)) {
        if (app->sound->volume_effect > 0)
            app->sound->volume_effect -= 5;
        play_sound(app);
    }
    if (is_on_sprite(app->button[12].sprite, mouse_pos)) {
        if (app->sound->volume_effect < 100)
            app->sound->volume_effect += 5;
        play_sound(app);
    }
    if (is_on_sprite(app->button[13].sprite, mouse_pos)) {
        if (app->sound->volume_music > 0)
            app->sound->volume_music -= 5;
        play_sound(app);
    }
    if (is_on_sprite(app->button[14].sprite, mouse_pos)) {
        if (app->sound->volume_music < 100)
            app->sound->volume_music += 5;
        play_sound(app);
    }
}

static void handle_volume_click(app_t *app, sfMouseButtonEvent *mouse_event)
{
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(app->window,
        (sfVector2i){mouse_event->x, mouse_event->y}, NULL);

    if (is_on_sprite(app->button[9].sprite, mouse_pos)) {
        if (app->sound->volume_general > 0)
            app->sound->volume_general -= 5;
        play_sound(app);
    }
    if (is_on_sprite(app->button[10].sprite, mouse_pos)) {
        if (app->sound->volume_general < 100)
            app->sound->volume_general += 5;
        play_sound(app);
    }
    if (is_on_sprite(app->button[15].sprite, mouse_pos)) {
        play_sound(app);
        return switch_to_settings(app, app->previous_scene);
    }
    handle_effect_music(app, mouse_pos);
}

static void handle_events_volume(app_t *app, sfEvent *event)
{
    sfMouseButtonEvent mouse_event = event->mouseButton;

    if (event->type == sfEvtMouseButtonReleased) {
        if (mouse_event.button == sfMouseLeft)
            handle_volume_click(app, &mouse_event);
    }
}

static void poll_events_volume(app_t *app, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(app->window, event) &&
        sfRenderWindow_hasFocus(app->window)) {
        handle_events_volume(app, event);
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(app->window);
        if (event->type == sfEvtResized)
            get_letterbox_view(app->view,
                (sfVector2u){event->size.width, event->size.height});
    }
    update_volume_text(app);
    sfRenderWindow_setView(app->window, app->view);
    update_buttons(app);
}

void switch_to_sound_settings(app_t *app)
{
    app->event_handler = poll_events_volume;
    app->draw_function = draw_volume_settings;
    get_letterbox_view(app->view, sfRenderWindow_getSize(app->window));
}
