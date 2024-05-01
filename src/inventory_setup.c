/*
** EPITECH PROJECT, 2023
** myrpg: inventory_setup.c
** File description:
** inventory management file
*/

#include "../include/rpg.h"

void init_inventory(app_t *app)
{
    app->inventory = malloc(sizeof(inventory_t));
    for (int i = 0; i < 32; i++) {
        app->inventory->slots[i] = NULL;
    }
}

void setup_inventory_sprites(app_t *app)
{
    sfTexture *inventoryBackgroundTexture =
        sfTexture_createFromFile("assets/textures/inventory_bg.png", NULL);
    app->inventory->background = sfSprite_create();

    sfSprite_setTexture(app->inventory->background, inventoryBackgroundTexture,
                        sfTrue);
}

void setup_inventory(app_t *app)
{
    init_inventory(app);
    setup_inventory_sprites(app);
}
