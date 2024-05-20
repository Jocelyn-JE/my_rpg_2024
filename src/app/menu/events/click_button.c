/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** click_button
*/

#include "rpg.h"

static void switch_to_game(app_t *app)
{
    app->event_handler = manage_game_events;
    app->draw_function = draw_game;
    get_letterbox_view(app->game_view, sfRenderWindow_getSize(app->window));
}

void handle_button_click(app_t *app, sfMouseButtonEvent *mouse_event)
{
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(app->window,
        (sfVector2i){mouse_event->x, mouse_event->y}, NULL);

    if (sfFloatRect_contains(&app->button[0].hitbox,
        mouse_pos.x, mouse_pos.y))
        return switch_to_game(app);
    if (sfFloatRect_contains(&app->button[1].hitbox,
        mouse_pos.x, mouse_pos.y)) {
        setting(app);
        destroy_menu(app);
    }
    if (sfFloatRect_contains(&app->button[2].hitbox,
        mouse_pos.x, mouse_pos.y))
        exit(0);
}
