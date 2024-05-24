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

void draw_to_window(void *void_app)
{
    app_t *app = void_app;

    sfRenderWindow_setActive(app->window, true);
    app->draw_function(app);
    sfRenderWindow_display(app->window);
}

int main(void)
{
    app_t *app = create_app();
    sfEvent events;
    sfThread *render_thread = sfThread_create(draw_to_window, app);

    switch_to_splashscreen(app);
    sfRenderWindow_setActive(app->window, false);
    while (sfRenderWindow_isOpen(app->window)) {
        sfThread_wait(render_thread);
        app->event_handler(app, &events);
        sfThread_launch(render_thread);
    }
    sfThread_wait(render_thread);
    destroy_app(app);
    return 0;
}
