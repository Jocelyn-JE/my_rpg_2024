/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** click_buton
*/

#include "rpg.h"

void handle_button_click(app_t *app, sfMouseButtonEvent *mouse_event)
{
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(app->window,
        (sfVector2i){mouse_event->x, mouse_event->y}, NULL);

    if (sfFloatRect_contains(&app->buton[0].hitbox,
        mouse_pos.x, mouse_pos.y))
        printf("jeux\n");
    if (sfFloatRect_contains(&app->buton[1].hitbox,
        mouse_pos.x, mouse_pos.y)) {
        setting(app);
        destroy_menu(app);
    }
    if (sfFloatRect_contains(&app->buton[2].hitbox,
        mouse_pos.x, mouse_pos.y))
        exit(0);
}
