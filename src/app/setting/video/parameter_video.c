/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** parameter_video
*/

#include "rpg.h"

static void draw_video_settings(app_t *app)
{
    sfRenderWindow_clear(app->window, sfBlack);
    sfRenderWindow_drawSprite(app->window, app->menu->backsprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[24].text, NULL);
    sfRenderWindow_drawSprite(app->window, app->button[6].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[7].text, NULL);
    sfRenderWindow_drawSprite(app->window, app->button[7].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[8].text, NULL);
    sfRenderWindow_drawSprite(app->window, app->button[8].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[9].text, NULL);
    sfRenderWindow_drawSprite(app->window, app->button[16].sprite, NULL);
    sfRenderWindow_drawText(app->window, app->text[25].text, NULL);
}

static void cycle_fps_setting(sfRenderWindow *window, text_t *text)
{
    int fps_presets[] = {30, 60, 75, 90, 100, 120, 144, 165};
    static int current_fps = 0;
    char fps_str[50];

    current_fps = current_fps == 8 ? 0 : current_fps + 1;
    if (current_fps == 0) {
        update_text(text, (sfVector2f){1920 / 2, 1080 / 3 * 1.5},
            "Max Framerate: Vsync", 7);
        sfRenderWindow_setVerticalSyncEnabled(window, true);
    }
    if (current_fps != 0) {
        sfRenderWindow_setVerticalSyncEnabled(window, false);
        sprintf(fps_str, "Max Framerate: %d fps",
            fps_presets[current_fps - 1]);
        update_text(text, (sfVector2f){1920 / 2, 1080 / 3 * 1.5}, fps_str, 7);
        sfRenderWindow_setFramerateLimit(window, fps_presets[current_fps - 1]);
    }
}

static void cycle_resolution_modes(sfRenderWindow *window, text_t *text)
{
    sfVector2u screen_modes[] = {{1920, 1080}, {1280, 720}};
    char *mode_str[] = {"1920/1080", "1280/720"};
    static int current_mode = 0;
    char button_str[50];

    current_mode = current_mode == 1 ? 0 : current_mode + 1;
    sfRenderWindow_setSize(window, screen_modes[current_mode]);
    sprintf(button_str, "Resolution: %s", mode_str[current_mode]);
    update_text(text, (sfVector2f){1920 / 2, 1080 / 3 * 1.25}, button_str, 25);
}

static void cycle_window_modes(sfRenderWindow **window, text_t *text)
{
    int screen_modes[] = {sfDefaultStyle, sfFullscreen};
    char *mode_str[] = {"OFF", "ON"};
    static int current_mode = 0;
    char button_str[50];

    current_mode = current_mode == 1 ? 0 : current_mode + 1;
    sfRenderWindow_destroy(*window);
    *window = create_window((sfVector2f){1920, 1080}, 32,
        screen_modes[current_mode]);
    sprintf(button_str, "Fullscreen: %s", mode_str[current_mode]);
    update_text(text, (sfVector2f){1920 / 2, 1080 / 3 * 1.75}, button_str, 8);
}

static void handle_video_click(app_t *app, sfMouseButtonEvent *mouse_event)
{
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(app->window,
        (sfVector2i){mouse_event->x, mouse_event->y}, NULL);

    if (is_on_sprite(app->button[6].sprite, mouse_pos))
        cycle_fps_setting(app->window, app->text);
    if (is_on_sprite(app->button[7].sprite, mouse_pos))
        cycle_window_modes(&app->window, app->text);
    if (is_on_sprite(app->button[8].sprite, mouse_pos))
        switch_to_settings(app);
    if (is_on_sprite(app->button[16].sprite, mouse_pos))
        cycle_resolution_modes(app->window, app->text);
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
