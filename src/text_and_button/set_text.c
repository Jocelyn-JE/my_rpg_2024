/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** set_text
*/

#include "rpg.h"

void update_text(text_t *text, sfVector2f pos, char *string, int i)
{
    sfFloatRect rect;
    sfVector2f centered_pos;

    sfText_setString(text[i].text, string);
    sfText_setCharacterSize(text[i].text, 24);
    rect = sfText_getGlobalBounds(text[i].text);
    centered_pos = (sfVector2f){pos.x - rect.width / 2, pos.y - rect.height};
    sfText_setPosition(text[i].text, centered_pos);
}

void set_text(app_t *app, sfVector2f pos, char *string, int i)
{
    sfFloatRect rect;
    sfVector2f centered_pos;

    app->text[i].font = app->fonts[1];
    app->text[i].text = sfText_create();
    sfText_setString(app->text[i].text, string);
    sfText_setFont(app->text[i].text, app->text[i].font);
    sfText_setCharacterSize(app->text[i].text, 24);
    rect = sfText_getGlobalBounds(app->text[i].text);
    centered_pos = (sfVector2f){pos.x - rect.width / 2, pos.y - rect.height};
    sfText_setPosition(app->text[i].text, centered_pos);
}

void text_menu(app_t *app)
{
    set_text(app, (sfVector2f){1920 / 2, 1080 / 2}, "Play Game", 0);
    set_text(app, (sfVector2f){1920 / 2, 1080 / 2 + 150}, "Options...", 1);
    set_text(app, (sfVector2f){1920 / 2, 1080 / 2 + 300}, "Quit Game", 2);
    set_text(app, (sfVector2f){1920 / 2, 1080 / 2}, "Options...", 26);
    set_text(app, (sfVector2f){1920 / 2, 1080 / 2 - 60}, "Back To Game", 27);
    set_text(app, (sfVector2f){1920 / 2, 1080 / 2 + 120},
        "Save and Quit to Title", 28);
    set_text(app, (sfVector2f){1920 / 2, 1080 / 2 - 120}, "Game Menu", 29);
    set_text(app, (sfVector2f){1920 / 2, 1080 / 2 + 60}, "How To Play", 30);
    set_text(app, (sfVector2f){1920 / 2, 1080 / 3 * 2.5}, "Done", 31);
    set_text(app, (sfVector2f){1920 / 2, 1080 / 3 * 2.5}, "Commande", 32);
}

static void set_color(app_t *app)
{
    sfColor greyColor = sfColor_fromRGB(117, 117, 117);

    sfText_setColor(app->text[33].text, greyColor);
    sfText_setColor(app->text[34].text, greyColor);
    sfText_setColor(app->text[35].text, greyColor);
    sfText_setColor(app->text[36].text, greyColor);
    sfText_setColor(app->text[37].text, greyColor);
    sfText_setColor(app->text[38].text, greyColor);
}

void text_setting(app_t *app)
{
    set_text(app, (sfVector2f){1920 / 2, 1080 / 3}, "Options...", 3);
    set_text(app, (sfVector2f){1920 / 3, 1080 / 2}, "Music & Sounds", 4);
    set_text(app, (sfVector2f){1920 / 3 * 2, 1080 / 2}, "Video Settings", 5);
    set_text(app, (sfVector2f){1920 / 2, 1080 / 3 * 2}, "Done", 6);
    set_text(app, (sfVector2f){1920 / 3 - 40, 1080 / 2 - 180},
        "Inventory", 33);
    set_text(app, (sfVector2f){1920 / 3 - 50, 1080 / 2 + 85}, "Pause", 34);
    set_text(app, (sfVector2f){1920 / 3 * 2 - 300, 1080 / 2 + 115},
        "Left", 35);
    set_text(app, (sfVector2f){1920 / 3 * 2 + 10, 1080 / 2 + 115}, "Down", 36);
    set_text(app, (sfVector2f){1920 / 3 * 2 + 300, 1080 / 2 + 115},
        "Right", 37);
    set_text(app, (sfVector2f){1920 / 3 * 2 + 30, 1080 / 3 - 140}, "Up", 38);
    set_color(app);
    sfText_setCharacterSize(app->text[33].text, 60);
    sfText_setCharacterSize(app->text[34].text, 60);
    sfText_setCharacterSize(app->text[35].text, 60);
    sfText_setCharacterSize(app->text[36].text, 60);
    sfText_setCharacterSize(app->text[37].text, 60);
    sfText_setCharacterSize(app->text[38].text, 60);
}

void text_video(app_t *app)
{
    set_text(app, (sfVector2f){1920 / 2, 1080 / 3 * 1.5}, "Max Fr"
        "amerate: Vsync", 7);
    set_text(app, (sfVector2f){1920 / 2, 1080 / 3 * 1.75}, "Fullsc"
        "reen: OFF", 8);
    set_text(app, (sfVector2f){1920 / 2, 1080 / 3 * 2}, "Done", 9);
    set_text(app, (sfVector2f){1920 / 2, 1080 / 3}, "Video Settings", 24);
    set_text(app, (sfVector2f){1920 / 2, 1080 / 3 * 1.25}, "Resolu"
        "tion: 1920/1080", 25);
}
