/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** main
*/

#include "../include/rpg.h"

static void setup_global_handlers(app_t *app)
{
    app->game_handler = draw_game;
    app->event_handler = manage_game_events;
}

int main(int argc, char **argv)
{
    app_t *app = create_app();
    sfEvent events;

    setup_global_handlers(app);
    while (sfRenderWindow_isOpen(app->window)) {
        app->event_handler(app, &events);
        sfRenderWindow_clear(app->window, sfBlack);
        sfRenderWindow_setView(app->window, app->view);
        app->game_handler(app);
        sfRenderWindow_display(app->window);
    }
    destroy_app(app);
    return 0;
}
