/*
** EPITECH PROJECT, 2023
** myrpg: inventory_setup.c
** File description:
** inventory management file
*/

#include "../../../include/rpg.h"

const char *item_file_paths[] = {
    "assets/final_items/apple.png",
    "assets/final_items/arrow.png",
    "assets/final_items/diamond_axe.png",
    "assets/final_items/diamond_pickaxe.png",
    "assets/final_items/diamond_sword.png",
    "assets/final_items/diamond_helmet.png",
    "assets/final_items/diamond_chestplate.png",
    "assets/final_items/diamond_leggings.png",
    "assets/final_items/diamond_boots.png",
};

bool add_item_to_inventory(inventory_t *inventory, item_t *item,
    int fixed_place)
{
    if (item == NULL)
        return false;
    if (fixed_place != -1) {
        inventory->slots[fixed_place] = item;
        return true;
    }
    for (int i = 0; i < 36; i++) {
        if (inventory->slots[i] == NULL) {
            inventory->slots[i] = item;
            return true;
        }
    }
    return false;
}

item_t *create_item(p_items_t item_type, int limit, int quantity)
{
    item_t *new_item = malloc(sizeof(item_t));
    sfFont *font = sfFont_createFromFile
        ("assets/fonts/minecraft-font/MinecraftBold-nMK1.otf");
    sfTexture *texture =
        sfTexture_createFromFile(item_file_paths[item_type], NULL);

    if (!new_item || quantity < 0 || quantity > limit)
        return NULL;
    new_item->quantity = quantity;
    new_item->limit = limit;
    new_item->sprite = sfSprite_create();
    sfSprite_setTexture(new_item->sprite, texture, sfTrue);
    new_item->current_item = item_type;
    if (limit <= 1)
        return new_item;
    new_item->quantity_text = sfText_create();
    sfText_setFont(new_item->quantity_text, font);
    sfText_setColor(new_item->quantity_text, sfWhite);
    return new_item;
}

static void init_inventory(app_t *app)
{
    sfTexture* selection_texture =
        sfTexture_createFromFile("assets/hotbar_selection.png", NULL);

    app->inventory = malloc(sizeof(inventory_t));
    app->inventory->selected_slot = 0;
    app->inventory->selection = sfSprite_create();
    app->inventory->dragging_slot = -1;
    app->inventory->dragged_item = NULL;
    sfSprite_setTexture(app->inventory->selection, selection_texture, sfTrue);
    for (int i = 0; i < 36; i++) {
        app->inventory->slots[i] = NULL;
    }
}

void setup_inventory_sprites(app_t *app)
{
    sfTexture *inventoryBackgroundTexture =
        sfTexture_createFromFile("assets/inventory.png", NULL);

    app->inventory->background = sfSprite_create();
    sfSprite_setTexture(app->inventory->background,
        inventoryBackgroundTexture, sfTrue);
}

void setup_hotbar_sprites(app_t *app)
{
    sfTexture *hotbarBackgroundTexture =
        sfTexture_createFromFile("assets/hotbar.png", NULL);

    app->inventory->hotbar = sfSprite_create();
    sfSprite_setTexture(app->inventory->hotbar,
        hotbarBackgroundTexture, sfTrue);
}

void setup_inventory(app_t *app)
{
    init_inventory(app);
    setup_inventory_sprites(app);
    setup_hotbar_sprites(app);
    add_item_to_inventory(app->inventory, create_item(p_apple, 64, 64), -1);
    add_item_to_inventory(app->inventory, create_item(p_arrow, 32, 32), -1);
    add_item_to_inventory(app->inventory,
        create_item(p_diamond_axe, 1, 1), -1);
    add_item_to_inventory(app->inventory,
        create_item(p_diamond_sword, 1, 1), -1);
    add_item_to_inventory(app->inventory,
        create_item(p_diamond_helmet, 1, 1), -1);
    add_item_to_inventory(app->inventory,
        create_item(p_diamond_chestplate, 1, 1), -1);
    add_item_to_inventory(app->inventory,
        create_item(p_diamond_boots, 1, 1), -1);
    add_item_to_inventory(app->inventory,
        create_item(p_diamond_boots, 1, 1), 27);
    add_item_to_inventory(app->inventory,
        create_item(p_diamond_boots, 1, 1), 35);
}
