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

static void animation_splash(app_t *app, sfClock *clock)
{
    sfTime finished = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asSeconds(finished);
    static sfColor color = {255, 255, 255, 0};

    if (seconds < 0.01)
        return;
    if (color.a == 255)
        return switch_to_menu(app);
    if (color.a < 255) {
        color.a += 1.5;
        sfSprite_setColor(app->logo->sprite, color);
        sfClock_restart(clock);
    }
}

static void poll_events_splashscreen(app_t *app, sfEvent *event)
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
            return switch_to_menu(app);
    }
    animation_splash(app, app->game_clock);
    sfRenderWindow_setView(app->window, app->view);
}

void draw_splashscreen(app_t *app)
{
    sfRenderWindow_clear(app->window, sfWhite);
    sfRenderWindow_drawSprite(app->window, app->logo->sprite, NULL);
}

void switch_to_splashscreen(app_t *app)
{
    app->draw_function = draw_splashscreen;
    app->event_handler = poll_events_splashscreen;
}
