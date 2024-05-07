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

void text_sound(app_t *app)
{
    set_text(app, (sfVector2f){480, 507}, "augmenter", 7);
    set_text(app, (sfVector2f){1190, 507}, "Diminuer", 8);
    set_text(app, (sfVector2f){900, 707}, "Done", 9);
}

void text_video(app_t *app)
{
    set_text(app, (sfVector2f){480, 507}, "???", 10);
    set_text(app, (sfVector2f){1190, 507}, "???", 11);
    set_text(app, (sfVector2f){900, 707}, "Done", 12);
}
