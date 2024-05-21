/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** parameter_video
*/

#include "rpg.h"

static void draw_video_settings(app_t *app)
{
    sfVector2f pos_back = {0, 0};
    sfVector2f scale_back = {2.25, 2.25};
    sfSprite* sprite = create_sprite("assets/widgets"
        "/set_back.png", pos_back, scale_back);

    sfRenderWindow_clear(app->window, sfBlack);
    sfRenderWindow_drawSprite(app->window, sprite, NULL);
    sfSprite_destroy(sprite);
    sfRenderWindow_drawText(app->window, app->text[24].text, NULL);
    sfRenderWindow_drawSprite(app->window, app->button[6].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[7].text, NULL);
    sfRenderWindow_drawSprite(app->window, app->button[7].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[8].text, NULL);
    sfRenderWindow_drawSprite(app->window, app->button[8].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[9].text, NULL);
}

static void cycle_fps_setting(sfRenderWindow *window, text_t *text)
{
    int fps_presets[] = {30, 60, 75, 90, 100, 120, 144, 165};
    static int current_fps = 0;
    char fps_str[50];

    current_fps = current_fps == 8 ? 0 : current_fps + 1;
    if (current_fps == 0) {
        update_text(text, (sfVector2f){1920 / 3, 1080 / 2},
            "Max Framerate: Vsync", 7);
        sfRenderWindow_setVerticalSyncEnabled(window, true);
    }
    if (current_fps != 0) {
        sfRenderWindow_setVerticalSyncEnabled(window, false);
        sprintf(fps_str, "Max Framerate: %d fps",
            fps_presets[current_fps - 1]);
        update_text(text, (sfVector2f){1920 / 3, 1080 / 2}, fps_str, 7);
        sfRenderWindow_setFramerateLimit(window, fps_presets[current_fps - 1]);
    }
}

static void handle_video_click(app_t *app, sfMouseButtonEvent *mouse_event)
{
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(app->window,
        (sfVector2i){mouse_event->x, mouse_event->y}, NULL);

    if (is_on_sprite(app->button[6].sprite, mouse_pos))
        cycle_fps_setting(app->window, app->text);
    if (is_on_sprite(app->button[7].sprite, mouse_pos))
        mini_printf("BBB\n");
    if (is_on_sprite(app->button[8].sprite, mouse_pos))
        switch_to_settings(app);
}

static void handle_events_video(app_t *app, sfEvent *event)
{
    sfMouseButtonEvent mouse_event = event->mouseButton;

    if (event->type == sfEvtMouseButtonPressed) {
        if (mouse_event.button == sfMouseLeft)
            handle_video_click(app, &mouse_event);
    }
}

static void poll_events_video_settings(app_t *app, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(app->window, event) &&
        sfRenderWindow_hasFocus(app->window)) {
        handle_events_video(app, event);
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(app->window);
        if (event->type == sfEvtResized)
            get_letterbox_view(app->view,
                (sfVector2u){event->size.width, event->size.height});
    }
    sfRenderWindow_setView(app->window, app->view);
}

void switch_to_video_settings(app_t *app)
{
    app->event_handler = poll_events_video_settings;
    app->draw_function = draw_video_settings;
    get_letterbox_view(app->view, sfRenderWindow_getSize(app->window));
}
