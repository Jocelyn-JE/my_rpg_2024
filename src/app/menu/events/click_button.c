/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** click_button
*/

#include "rpg.h"

bool is_on_sprite(sfSprite *button, sfVector2f pos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(button);

    return sfFloatRect_contains(&rect, pos.x, pos.y);
}

void handle_button_click(app_t *app, sfMouseButtonEvent *mouse_event)
{
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(app->window,
        (sfVector2i){mouse_event->x, mouse_event->y}, NULL);

    if (is_on_sprite(app->button[0].sprite, mouse_pos)) {
        sfSound_play(app->sound->sounds[0]);
        sfMusic_stop(app->sound->music);
        return switch_to_game(app);
    }
    if (is_on_sprite(app->button[1].sprite, mouse_pos)) {
        sfSound_play(app->sound->sounds[0]);
        return switch_to_settings(app);
    }
    if (is_on_sprite(app->button[2].sprite, mouse_pos)) {
        sfSound_play(app->sound->sounds[0]);
        sfRenderWindow_close(app->window);
    }
}
