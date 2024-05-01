/*
** EPITECH PROJECT, 2023
** myrpg: inventory_setup.c
** File description:
** inventory management file
*/

#include "../include/rpg.h"

const char *item_file_paths[] = {
    "assets/items_icons/cables.png",
    "assets/items_icons/cleaver.png",
    "assets/items_icons/transistor.png",
};

bool add_item_to_inventory(inventory_t *inventory, item_t *item,
    int fixed_place)
{
    if (fixed_place != -1) {
        inventory->slots[fixed_place] = item;
        return true;
    }
    for (int i = 0; i < 32; i++) {
        if (inventory->slots[i] == NULL) {
            inventory->slots[i] = item;
            return true;
        }
    }
    return false;
}

item_t *create_item(p_items_t item_type)
{
    item_t *new_item = malloc(sizeof(item_t));
    sfTexture *texture =
        sfTexture_createFromFile(item_file_paths[item_type], NULL);

    if (!new_item)
        return NULL;
    new_item->quantity = 0;
    new_item->sprite = sfSprite_create();
    sfSprite_setTexture(new_item->sprite, texture, sfTrue);
    new_item->current_item = item_type;
    return new_item;
}

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
    sfSprite_setTexture(app->inventory->background,
    inventoryBackgroundTexture, sfTrue);
}

void setup_inventory(app_t *app)
{
    init_inventory(app);
    setup_inventory_sprites(app);
    add_item_to_inventory(app->inventory, create_item(p_cables), -1);
}
