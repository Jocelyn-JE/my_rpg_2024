/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** set_text
*/

#include "rpg.h"

void set_text(app_t *app, sfVector2f pos, char *filename, int i)
{
    sfFloatRect rect;
    sfVector2f centered_pos;

    app->text[i].font = app->fonts[0];
    app->text[i].text = sfText_create();
    sfText_setString(app->text[i].text, filename);
    sfText_setFont(app->text[i].text, app->text[i].font);
    sfText_setCharacterSize(app->text[i].text, 24);
    rect = sfText_getGlobalBounds(app->text[i].text);
    centered_pos = (sfVector2f){pos.x - rect.width / 2, pos.y - rect.height};
    sfText_setPosition(app->text[i].text, centered_pos);
}

void text_menu(app_t *app)
{
    set_text(app, (sfVector2f){1920 / 2, 1080 / 2}, "Play Game", 0);
    set_text(app, (sfVector2f){1920 / 2, 1080 / 2 + 150}, "Options", 1);
    set_text(app, (sfVector2f){1920 / 2, 1080 / 2 + 300}, "Quit Game", 2);
}

void text_setting(app_t *app)
{
    set_text(app, (sfVector2f){1920 / 2, 1080 / 3}, "Options", 3);
    set_text(app, (sfVector2f){1920 / 3, 1080 / 2}, "Music & Sounds", 4);
    set_text(app, (sfVector2f){1920 / 3 * 2, 1080 / 2}, "Video Settings", 5);
    set_text(app, (sfVector2f){1920 / 2, 1080 / 3 * 2}, "Done", 6);
}

void text_video(app_t *app)
{
    set_text(app, (sfVector2f){480, 507}, "???", 7);
    set_text(app, (sfVector2f){1190, 507}, "???", 8);
    set_text(app, (sfVector2f){900, 707}, "Done", 9);
}
