/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** init_app
*/

#include "rpg.h"

sfSoundBuffer **init_buffers(void)
{
    sfSoundBuffer **buffer = malloc(sizeof(sfSoundBuffer *) * 5);
    const char *sound_files[] = {
        "assets/sound/click.ogg",
        "assets/sound/hit.ogg",
        "assets/sound/explode.ogg",
        "assets/sound/eat.ogg",
        NULL
    };

    for (int i = 0; sound_files[i] != NULL; i++)
        buffer[i] = sfSoundBuffer_createFromFile(sound_files[i]);
    buffer[4] = NULL;
    return buffer;
}

static sfMusic **init_music(void)
{
    sfMusic **music = malloc(sizeof(sfMusic *) * 3);

    music[0] = sfMusic_createFromFile("assets/music/music_menu.ogg");
    music[1] = sfMusic_createFromFile("assets/music/music_in_game.ogg");
    music[2] = NULL;
    return music;
}

sfSound **init_sounds(sfSoundBuffer **buffers)
{
    sfSound **sounds = malloc(sizeof(sfSound *) * 5);

    for (int i = 0; buffers[i] != NULL; i++) {
        sounds[i] = sfSound_create();
        sfSound_setBuffer(sounds[i], buffers[i]);
    }
    sounds[4] = NULL;
    return sounds;
}

sound_t *init_sound(void)
{
    sound_t *sound = malloc(4 * sizeof(sound_t));

    sound->sound_buffers = init_buffers();
    sound->sounds = init_sounds(sound->sound_buffers);
    sound->music = init_music();
    sound->volume_general = 50;
    sound->volume_music = 50;
    sound->volume_effect = 50;
    sfSound_setVolume(sound->sounds[0], 25);
    for (int i = 0; sound->music[i]; i++) {
        sfMusic_setVolume(sound->music[i], 25);
        sfMusic_setLoop(sound->music[i], true);
    }
    return sound;
}
