/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** parameter_sound
*/

#include "rpg.h"

static void draw_setting_button(app_t *app)
{
    sfVector2f pos_back = {0, 0};
    sfVector2f scale_back = {2.25, 2.25};
    sfSprite* sprite = create_sprite("assets/widgets"
        "/set_back.png", pos_back, scale_back);

    sfRenderWindow_drawSprite(app->window, sprite, NULL);
    sfSprite_destroy(sprite);
    for (int i = 9; i != 16; i++) {
        sfRenderWindow_drawSprite(app->window, app->button[i].sprite, NULL);
    }
    for (int i = 10; i != 23; i++) {
        sfRenderWindow_drawText(app->window, app->text[i].text, NULL);
    }
}

static void text_effect_sound(app_t *app)
{
    char volume_effect[9];

    snprintf(volume_effect, sizeof(volume_effect), "%d",
        app->sound->volume_effect);
    set_text(app, (sfVector2f){855, 457}, "Volume Effect", 18);
    set_text(app, (sfVector2f){480, 507}, "Reduce", 19);
    set_text(app, (sfVector2f){1190, 507}, "Increase", 20);
    set_text(app, (sfVector2f){945, 507}, volume_effect, 21);
    set_text(app, (sfVector2f){900, 707}, "Done", 22);
}

void text_sound(app_t *app)
{
    char volume_general[9];
    char volume_music[9];

    snprintf(volume_general, sizeof(volume_general), "%d",
        app->sound->volume_general);
    set_text(app, (sfVector2f){845, 157}, "Volume General", 10);
    set_text(app, (sfVector2f){480, 207}, "Reduce", 11);
    set_text(app, (sfVector2f){1190, 207}, "Increase", 12);
    set_text(app, (sfVector2f){945, 207}, volume_general, 13);
    snprintf(volume_music, sizeof(volume_music), "%d",
        app->sound->volume_music);
    set_text(app, (sfVector2f){865, 307}, "Volume Music", 14);
    set_text(app, (sfVector2f){480, 357}, "Reduce", 15);
    set_text(app, (sfVector2f){1190, 357}, "Increase", 16);
    set_text(app, (sfVector2f){945, 357}, volume_music, 17);
    text_effect_sound(app);
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
    if (sfFloatRect_contains(&app->button[11].hitbox,
        mouse_pos.x, mouse_pos.y)) {
        if (app->sound->volume_effect > 0)
            app->sound->volume_effect -= 5;
    }
    if (sfFloatRect_contains(&app->button[12].hitbox,
        mouse_pos.x, mouse_pos.y)) {
        if (app->sound->volume_effect < 100)
            app->sound->volume_effect += 5;
    }
    if (sfFloatRect_contains(&app->button[13].hitbox,
        mouse_pos.x, mouse_pos.y)) {
        if (app->sound->volume_music > 0)
            app->sound->volume_music -= 5;
    }
    if (sfFloatRect_contains(&app->button[14].hitbox,
        mouse_pos.x, mouse_pos.y)) {
        if (app->sound->volume_music < 100)
            app->sound->volume_music += 5;
    }
}

static void handle_volume_click(app_t *app, sfMouseButtonEvent *mouse_event)
{
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(app->window,
        (sfVector2i){mouse_event->x, mouse_event->y}, NULL);

    if (sfFloatRect_contains(&app->button[9].hitbox,
        mouse_pos.x, mouse_pos.y)) {
        if (app->sound->volume_general > 0)
            app->sound->volume_general -= 5;
    }
    if (sfFloatRect_contains(&app->button[10].hitbox,
        mouse_pos.x, mouse_pos.y)) {
        if (app->sound->volume_general < 100)
            app->sound->volume_general += 5;
    }
    if (sfFloatRect_contains(&app->button[15].hitbox,
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
    sfEvent events;

    text_sound(app);
    set_button_sound(app);
    while (sfRenderWindow_isOpen(app->window)) {
        poll_events_volume(app, &events);
        sfRenderWindow_clear(app->window, sfBlack);
        volume_value(app);
        draw_setting_button(app);
        sfRenderWindow_display(app->window);
    }
}
