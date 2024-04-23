/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** init_app
*/
#include "rpg.h"

app_t *create_app(void)
{
    app_t *app = malloc(sizeof(app_t));

    app->event = malloc(sizeof(event_t));
    app->window = create_window(1920, 1080, 32);
    return app;
}
