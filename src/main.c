/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** main
*/

#include "../include/rpg.h"

const switch_scene_t switch_functions[] = {
    {switch_to_menu},
    {switch_to_settings},
    {switch_to_video_settings},
    {switch_to_sound_settings},
    {switch_to_game},
    {switch_to_splashscreen},
    {switch_to_pause_menu},
    {switch_to_inventory},
    {switch_to_help_menu}
};

void switch_to_scene(app_t *app, scenes_t scene)
{
    switch_functions[scene].function(app, app->previous_scene);
}

int main(void)
{
    app_t *app = create_app();
    sfEvent events;

    switch_to_splashscreen(app);
    sfRenderWindow_requestFocus(app->window);
    while (sfRenderWindow_isOpen(app->window)) {
        app->event_handler(app, &events);
        app->draw_function(app);
        sfRenderWindow_display(app->window);
    }
    destroy_app(app);
    return 0;
}
