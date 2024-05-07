/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** click_buton
*/

#include "rpg.h"

static void handle_volum_click(app_t *app, sfVector2f mouse_pos)
{
    if (sfFloatRect_contains(&app->buton[3].hitbox,
        mouse_pos.x, mouse_pos.y))
        parameter_sound(app);
    if (sfFloatRect_contains(&app->buton[4].hitbox,
        mouse_pos.x, mouse_pos.y))
        parameter_video(app);
    if (sfFloatRect_contains(&app->buton[6].hitbox,
        mouse_pos.x, mouse_pos.y)) {
        app->sound->volume += 1;
        printf("%d", app->sound->volume);
    }
    if (sfFloatRect_contains(&app->buton[7].hitbox,
        mouse_pos.x, mouse_pos.y)) {
        app->sound->volume -= 1;
        printf("%d", app->sound->volume);
    }
}

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
    if (sfFloatRect_contains(&app->buton[5].hitbox,
        mouse_pos.x, mouse_pos.y))
        menu(app);
    handle_volum_click(app, mouse_pos);
}
