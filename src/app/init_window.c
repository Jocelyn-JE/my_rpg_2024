/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** init
*/
#include "rpg.h"

sfRenderWindow *create_window(sfVector2f res, unsigned int bpp)
{
    sfVideoMode video_mode = {res.x, res.y, bpp};
    sfRenderWindow *new_window = sfRenderWindow_create(video_mode,
        "my_rpg", sfResize | sfClose, NULL);
    sfImage *icon = sfImage_createFromFile("./assets/icons/icon_256x256.png");

    if (!new_window)
        my_putstr("Window failed to load\n");
    if (!icon)
        my_putstr("Icon failed to load\n");
    sfRenderWindow_setFramerateLimit(new_window, 60);
    sfRenderWindow_setIcon(new_window, 256, 256, sfImage_getPixelsPtr(icon));
    sfImage_destroy(icon);
    return (new_window);
}
