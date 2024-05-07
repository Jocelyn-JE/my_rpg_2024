/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** parameter_video
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
    sfRenderWindow_drawSprite(app->window, app->buton[9].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[10].text, NULL);
    sfRenderWindow_drawSprite(app->window, app->buton[10].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[11].text, NULL);
    sfRenderWindow_drawSprite(app->window, app->buton[11].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[12].text, NULL);
}

void parameter_video(app_t *app)
{
    text_video(app);
    set_buton_video(app);
    while (sfRenderWindow_isOpen(app->window)) {
        poll_events(app, &app->event->event);
        sfRenderWindow_clear(app->window, sfBlack);
        draw_setting_buton(app);
        sfRenderWindow_display(app->window);
    }
}
