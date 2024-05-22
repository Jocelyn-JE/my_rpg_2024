/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** poll_events_menu
*/

#include "rpg.h"

static void update_button(sfRenderWindow *window, sfSprite *sprite)
{
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(window,
        sfMouse_getPositionRenderWindow(window), NULL);

    if (is_on_sprite(sprite, mouse_pos)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfSprite_setTextureRect(sprite, (sfIntRect){0, 40, 200,
            20});
        } else {
            sfSprite_setTextureRect(sprite, (sfIntRect){0, 20, 200,
            20});
        }
    } else {
        sfSprite_setTextureRect(sprite, (sfIntRect){0, 00, 200,
        20});
    }
}

void update_buttons(app_t *app)
{
    for (int i = 0; i != 16; i++) {
        update_button(app->window, app->button[i].sprite);
    }
}
