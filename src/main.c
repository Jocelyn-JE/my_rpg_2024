/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** main
*/

#include "../include/rpg.h"

int main(void)
{
    app_t *app = create_app();
    sfEvent events;

    switch_to_splashscreen(app);
    while (sfRenderWindow_isOpen(app->window)) {
        app->event_handler(app, &events);
        app->draw_function(app);
        sfRenderWindow_display(app->window);
    }
    destroy_app(app);
    return 0;
}
