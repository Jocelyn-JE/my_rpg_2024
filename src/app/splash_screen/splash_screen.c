/*
** EPITECH PROJECT, 2024
** project
** File description:
** splash_screen
*/

#include "rpg.h"

logo_t *create_logo(void)
{
    logo_t *logo = malloc(sizeof(logo_t));
    sfFloatRect rect;

    logo->sprite = sfSprite_create();
    logo->texture = sfTexture_createFromFile("assets/widgets/logo.png", NULL);
    sfSprite_setTexture(logo->sprite, logo->texture, sfTrue);
    rect = sfSprite_getGlobalBounds(logo->sprite);
    sfSprite_setOrigin(logo->sprite, (sfVector2f){rect.width / 2,
        rect.height / 2});
    sfSprite_setScale(logo->sprite, (sfVector2f){1, 1});
    sfSprite_setPosition(logo->sprite, (sfVector2f){1920 / 2, 1080 / 2});
    return logo;
}

static void go_to_next_scene(app_t *app)
{
    app->event_handler = manage_game_events;
    app->game_handler = draw_game;
    get_letterbox_view(app->game_view, sfRenderWindow_getSize(app->window));
}

static void animation_splash(app_t *app, sfClock *clock)
{
    sfTime finished = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asSeconds(finished);
    static sfColor color = {255, 255, 255, 0};

    if (seconds < 0.01)
        return;
    if (color.a == 255)
        go_to_next_scene(app);
    if (color.a < 255) {
        color.a += 1.5;
        sfSprite_setColor(app->logo->sprite, color);
        sfClock_restart(clock);
    }
}

void poll_events_splashscreen(app_t *app, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(app->window, event) &&
        sfRenderWindow_hasFocus(app->window)) {
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(app->window);
        if (event->type == sfEvtResized)
            get_letterbox_view(app->view,
                (sfVector2u){event->size.width, event->size.height});
        if (event->type == sfEvtKeyPressed ||
            event->type == sfEvtMouseButtonPressed)
            go_to_next_scene(app);
    }
    animation_splash(app, app->game_clock);
    sfRenderWindow_setView(app->window, app->view);
}

void draw_splashscreen(app_t *app)
{
    sfRenderWindow_drawSprite(app->window, app->logo->sprite, NULL);
}
