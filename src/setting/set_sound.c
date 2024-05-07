/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** sound
*/

#include "rpg.h"

void set_music(app_t *app)
{
    app->sound->music = sfMusic_createFromFile("assets/music"
        "/volume_alpha_8.ogg");
    sfMusic_setVolume(app->sound->music, app->sound->volume_general);
    sfMusic_play(app->sound->music);
}
