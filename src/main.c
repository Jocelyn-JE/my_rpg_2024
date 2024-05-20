/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** main
*/

#include "../include/rpg.h"

static void setup_global_handlers(app_t *app)
{
    app->game_handler = draw_splashscreen;
    app->event_handler = poll_events_splashscreen;
}

int main(void)
{
    app_t *app = create_app();
    sfEvent events;

    setup_global_handlers(app);
    while (sfRenderWindow_isOpen(app->window)) {
        app->event_handler(app, &events);
        sfRenderWindow_clear(app->window, sfBlack);
        app->game_handler(app);
        sfRenderWindow_display(app->window);
    }
    destroy_app(app);
    return 0;
}
