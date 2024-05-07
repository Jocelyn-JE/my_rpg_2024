/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** sound
*/

#include "rpg.h"

void set_sound(app_t *app)
{
    app->sound->music = sfMusic_createFromFile("assets/music"
        "/volume_alpha_8.ogg");
    sfMusic_play(app->sound->music);
}
