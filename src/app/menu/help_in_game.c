/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** help_in_game
*/

#include "rpg.h"

static void button_actions(app_t *app, sfMouseButtonEvent *mouse_event)
{
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(app->window,
        (sfVector2i){mouse_event->x, mouse_event->y}, NULL);

    if (is_on_sprite(app->button[21].sprite, mouse_pos)) {
        sfSound_play(app->sound->sounds[0]);
        return switch_to_pause_menu(app);
    }
}

static void manage_events_help_menu(app_t *app, sfEvent *events)
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

static void draw_help_menu(app_t *app)
{
    sfRenderWindow_clear(app->window, sfBlack);
    sfRenderWindow_drawSprite(app->window, app->menu->backsprite, NULL);
    sfRenderWindow_drawSprite(app->window, app->menu->helpsprite, NULL);
    draw_button(app->window, app->button[21].sprite, app->text[31].text);
    sfRenderWindow_drawText(app->window, app->text[33].text, NULL);
    sfRenderWindow_drawText(app->window, app->text[34].text, NULL);
    sfRenderWindow_drawText(app->window, app->text[35].text, NULL);
    sfRenderWindow_drawText(app->window, app->text[36].text, NULL);
    sfRenderWindow_drawText(app->window, app->text[37].text, NULL);
    sfRenderWindow_drawText(app->window, app->text[38].text, NULL);
    sfRenderWindow_setView(app->window, app->view);
}

void switch_to_help_menu(app_t *app)
{
    app->event_handler = manage_events_help_menu;
    app->draw_function = draw_help_menu;
    sfTexture_destroy(app->menu->backtexture);
    app->menu->backtexture = sfTexture_createFromFile("assets/widgets/set_back"
        ".png", NULL);
    sfTexture_setRepeated(app->menu->backtexture, true);
    sfSprite_setTexture(app->menu->backsprite, app->menu->backtexture,
        sfFalse);
    get_letterbox_view(app->view, sfRenderWindow_getSize(app->window));
}
