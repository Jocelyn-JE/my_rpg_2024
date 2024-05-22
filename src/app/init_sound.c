/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** init_app
*/

#include "rpg.h"

sfSoundBuffer **init_buffers(void)
{
    sfSoundBuffer **buffer = malloc(sizeof(sfSoundBuffer *) * 2);
    const char *sound_files[] = {
        "assets/sound/click.ogg",
        NULL
    };

    for (int i = 0; sound_files[i] != NULL; i++)
        buffer[i] = sfSoundBuffer_createFromFile(sound_files[i]);
    buffer[1] = NULL;
    return buffer;
}

static sfMusic *init_music(void)
{
    sfMusic *music;

    music = sfMusic_createFromFile("assets/music/music_menu.ogg");
    return music;
}

sfSound **init_sounds(sfSoundBuffer **buffers)
{
    sfSound **sounds = malloc(sizeof(sfSound *) * 2);

    for (int i = 0; buffers[i] != NULL; i++) {
        sounds[i] = sfSound_create();
        sfSound_setBuffer(sounds[i], buffers[i]);
    }
    sounds[1] = NULL;
    return sounds;
}

sound_t *init_sound(void)
{
    sound_t *sound = malloc(sizeof(sound_t));

    sound->sound_buffers = init_buffers();
    sound->sounds = init_sounds(sound->sound_buffers);
    sound->music = init_music();
    sound->volume_general = 50;
    sound->volume_music = 50;
    sound->volume_effect = 50;
    return sound;
}
