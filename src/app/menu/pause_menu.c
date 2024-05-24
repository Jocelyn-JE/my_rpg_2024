/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** pause_menu
*/
#include "rpg.h"

static void button_actions(app_t *app, sfMouseButtonEvent *mouse_event)
{
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(app->window,
        (sfVector2i){mouse_event->x, mouse_event->y}, NULL);

    if (is_on_sprite(app->button[17].sprite, mouse_pos)) {
        sfSound_play(app->sound->sounds[0]);
        return switch_to_settings(app, s_pause_menu);
    }
    if (is_on_sprite(app->button[18].sprite, mouse_pos)) {
        sfSound_play(app->sound->sounds[0]);
        return switch_to_game(app);
    }
    if (is_on_sprite(app->button[19].sprite, mouse_pos)) {
        sfSound_play(app->sound->sounds[0]);
        switch_to_help_menu(app);
    }
    if (is_on_sprite(app->button[20].sprite, mouse_pos)) {
        sfSound_play(app->sound->sounds[0]);
        return switch_to_menu(app, s_pause_menu);
    }
}

static void manage_events_pause_menu(app_t *app, sfEvent *events)
{
    while (sfRenderWindow_pollEvent(app->window, events) &&
        sfRenderWindow_hasFocus(app->window)) {
        if (events->type == sfEvtResized) {
            get_letterbox_view(app->game_view,
                (sfVector2u){events->size.width, events->size.height});
            get_letterbox_view(app->view,
                (sfVector2u){events->size.width, events->size.height});
        }
        if (events->type == sfEvtClosed)
            sfRenderWindow_close(app->window);
        if (events->type == sfEvtKeyPressed && events->key.code == sfKeyEscape)
            switch_to_game(app);
        if (events->type == sfEvtMouseButtonReleased &&
            events->mouseButton.button == sfMouseLeft)
            button_actions(app, &events->mouseButton);
    }
    update_buttons(app);
}

static void draw_pause_menu(app_t *app)
{
    sfRenderWindow_clear(app->window, sfBlack);
    sfRenderWindow_setView(app->window, app->game_view);
    draw_chunks(app->game_ressources->map, app);
    draw_hotbar(app);
    sfRenderWindow_setView(app->window, app->view);
    sfRenderWindow_drawSprite(app->window,
        app->game_ressources->player->health_sprite, NULL);
    sfRenderWindow_setView(app->window, app->game_view);
    draw_semi_transparent_rect(app->window, app->game_view);
    sfRenderWindow_setView(app->window, app->view);
    draw_button(app->window, app->button[17].sprite, app->text[26].text);
    draw_button(app->window, app->button[18].sprite, app->text[27].text);
    draw_button(app->window, app->button[19].sprite, app->text[30].text);
    draw_button(app->window, app->button[20].sprite, app->text[28].text);
    sfRenderWindow_drawText(app->window, app->text[29].text, NULL);
}

void switch_to_pause_menu(app_t *app)
{
    app->event_handler = manage_events_pause_menu;
    app->draw_function = draw_pause_menu;
    sfMusic_pause(app->sound->music[1]);
    get_letterbox_view(app->view, sfRenderWindow_getSize(app->window));
}
