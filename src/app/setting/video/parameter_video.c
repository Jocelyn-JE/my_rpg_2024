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
    sfRenderWindow_drawSprite(app->window, app->buton[6].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[7].text, NULL);
    sfRenderWindow_drawSprite(app->window, app->buton[7].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[8].text, NULL);
    sfRenderWindow_drawSprite(app->window, app->buton[8].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[9].text, NULL);
}

static void handle_video_click(app_t *app, sfMouseButtonEvent *mouse_event)
{
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(app->window,
        (sfVector2i){mouse_event->x, mouse_event->y}, NULL);

    if (sfFloatRect_contains(&app->buton[6].hitbox,
        mouse_pos.x, mouse_pos.y))
        printf("caca\n");
    if (sfFloatRect_contains(&app->buton[7].hitbox,
        mouse_pos.x, mouse_pos.y))
        printf("pipi\n");
    if (sfFloatRect_contains(&app->buton[8].hitbox,
        mouse_pos.x, mouse_pos.y))
        setting(app);
}

static void handle_events_video(app_t *app, sfEvent *event)
{
    sfMouseButtonEvent mouse_event = event->mouseButton;

    if (event->type == sfEvtMouseButtonPressed) {
        if (mouse_event.button == sfMouseLeft) {
            handle_video_click(app, &mouse_event);
        }
    }
}

void poll_events_video(app_t *app, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(app->window, event) &&
        sfRenderWindow_hasFocus(app->window)) {
        handle_events_video(app, event);
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(app->window);
    }
}

void parameter_video(app_t *app)
{
    text_video(app);
    set_buton_video(app);
    while (sfRenderWindow_isOpen(app->window)) {
        poll_events_video(app, &app->event->event);
        sfRenderWindow_clear(app->window, sfBlack);
        draw_setting_buton(app);
        sfRenderWindow_display(app->window);
    }
}
