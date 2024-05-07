/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** set_text
*/

#include "rpg.h"

void set_text(app_t *app, sfVector2f position, char *filename, int i)
{
    app->text[i].font = sfFont_createFromFile("assets/fonts/minecraft-f"
        "ont/MinecraftBold-nMK1.otf");
    app->text[i].text = sfText_create();
    sfText_setString(app->text[i].text, filename);
    sfText_setFont(app->text[i].text, app->text[i].font);
    sfText_setCharacterSize(app->text[i].text, 24);
    sfText_setPosition(app->text[i].text, position);
}

void text_menu(app_t *app)
{
    set_text(app, (sfVector2f){880, 507}, "Play Game", 0);
    set_text(app, (sfVector2f){890, 657}, "Options", 1);
    set_text(app, (sfVector2f){880, 807}, "Quit Game", 2);
}

void text_setting(app_t *app)
{
    set_text(app, (sfVector2f){880, 307}, "Options", 3);
    set_text(app, (sfVector2f){480, 507}, "Music & Sounds", 4);
    set_text(app, (sfVector2f){1190, 507}, "Video Settings", 5);
    set_text(app, (sfVector2f){900, 707}, "Done", 6);
}

void text_video(app_t *app)
{
    set_text(app, (sfVector2f){480, 507}, "???", 7);
    set_text(app, (sfVector2f){1190, 507}, "???", 8);
    set_text(app, (sfVector2f){900, 707}, "Done", 9);
}

static void text_effect_sound(app_t *app)
{
    char volume_effect[9];

    snprintf(volume_effect, sizeof(volume_effect), "%d",
        app->sound->volume_effect);
    set_text(app, (sfVector2f){855, 457}, "Volume Effect", 18);
    set_text(app, (sfVector2f){480, 507}, "Reduce", 19);
    set_text(app, (sfVector2f){1190, 507}, "Increase", 20);
    set_text(app, (sfVector2f){945, 507}, volume_effect, 21);
    set_text(app, (sfVector2f){900, 707}, "Done", 22);
}

void text_sound(app_t *app)
{
    char volume_general[9];
    char volume_music[9];

    snprintf(volume_general, sizeof(volume_general), "%d",
        app->sound->volume_general);
    set_text(app, (sfVector2f){845, 157}, "Volume General", 10);
    set_text(app, (sfVector2f){480, 207}, "Reduce", 11);
    set_text(app, (sfVector2f){1190, 207}, "Increase", 12);
    set_text(app, (sfVector2f){945, 207}, volume_general, 13);
    snprintf(volume_music, sizeof(volume_music), "%d",
        app->sound->volume_music);
    set_text(app, (sfVector2f){865, 307}, "Volume Music", 14);
    set_text(app, (sfVector2f){480, 357}, "Reduce", 15);
    set_text(app, (sfVector2f){1190, 357}, "Increase", 16);
    set_text(app, (sfVector2f){945, 357}, volume_music, 17);
    text_effect_sound(app);
}
