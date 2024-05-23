/*
** EPITECH PROJECT, 2023
** myrpg: inventory_setup.c
** File description:
** inventory management file
*/

#include "../../../include/rpg.h"
#include <SFML/Graphics/Types.h>

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
    "assets/final_items/iron_axe.png",
    "assets/final_items/iron_pickaxe.png",
    "assets/final_items/iron_sword.png",
    "assets/final_items/iron_helmet.png",
    "assets/final_items/iron_chestplate.png",
    "assets/final_items/iron_leggings.png",
    "assets/final_items/iron_boots.png",
    "assets/final_items/gold_axe.png",
    "assets/final_items/gold_pickaxe.png",
    "assets/final_items/gold_sword.png",
    "assets/final_items/gold_helmet.png",
    "assets/final_items/gold_chestplate.png",
    "assets/final_items/gold_leggings.png",
    "assets/final_items/gold_boots.png",
    "assets/final_items/netherite_axe.png",
    "assets/final_items/netherite_pickaxe.png",
    "assets/final_items/netherite_sword.png",
    "assets/final_items/netherite_helmet.png",
    "assets/final_items/netherite_chestplate.png",
    "assets/final_items/netherite_leggings.png",
    "assets/final_items/netherite_boots.png",
};

static bool case_same_item(inventory_t *inventory, item_t *item, int i)
{
    int diff = inventory->slots[i]->limit - inventory->slots[i]->quantity;

    if (diff >= item->quantity) {
        inventory->slots[i]->quantity += item->quantity;
        return true;
    }
    inventory->slots[i]->quantity += diff;
    item->quantity -= diff;
    return false;
}

static bool manage_stacking(inventory_t *inventory, item_t *item)
{
    bool return_value = false;

    for (int i = 0; i < 36; i++) {
        if (inventory->slots[i] == NULL)
            continue;
        if (inventory->slots[i]->current_item == item->current_item
            && inventory->slots[i]->quantity < inventory->slots[i]->limit) {
            return_value = case_same_item(inventory, item, i);
        }
        if (return_value)
            return true;
    }
    return false;
}

static bool manage_armor(inventory_t *inventory, item_t *item)
{
    for (int i = 0; i < 4; i++) {
        if (inventory->armor[i] == NULL) {
            inventory->armor[i] = item;
            return true;
        }
    }
    return false;
}

static bool add_item_at_position(inventory_t *inventory, item_t *item,
    int position)
{
    if (inventory->slots[position] == NULL) {
        inventory->slots[position] = item;
        return true;
    }
    free_item(item);
    return false;
}

bool add_item_to_inventory(inventory_t *inventory, item_t *item,
    int fixed_place)
{
    int return_value = 0;

    if (item == NULL)
        return false;
    if (fixed_place != -1)
        return add_item_at_position(inventory, item, fixed_place);
    if (is_helmet(item->current_item) || is_chestplate(item->current_item)
        || is_leggings(item->current_item) || is_boots(item->current_item))
        return_value = manage_armor(inventory, item);
    if (return_value)
        return true;
    return_value = manage_stacking(inventory, item);
    if (return_value)
        return true;
    for (int i = 0; i < 36; i++) {
        if (inventory->slots[i] == NULL)
            return add_item_at_position(inventory, item, i);
    }
    free_item(item);
    return false;
}

item_t *create_item(p_items_t item_type, int limit, int quantity, sfFont *font)
{
    item_t *new_item = malloc(sizeof(item_t));
    sfTexture *texture =
        sfTexture_createFromFile(item_file_paths[item_type], NULL);

    if (!new_item || limit > 64 || quantity < 0 || quantity > limit)
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
    app->inventory->current_item_slot = -1;
    app->inventory->current_armor_slot = -1;
    app->inventory->selection = sfSprite_create();
    app->inventory->dragging_slot = -1;
    app->inventory->dragged_item = NULL;
    sfSprite_setTexture(app->inventory->selection, selection_texture, sfTrue);
    for (int i = 0; i < 36; i++)
        app->inventory->slots[i] = NULL;
    for (int i = 0; i < 4; i++)
        app->inventory->armor[i] = NULL;
}

void setup_inventory_sprites(app_t *app)
{
    sfTexture *inventory_background_texture =
        sfTexture_createFromFile("assets/inventory.png", NULL);
    sfTexture *trash_can_texture =
        sfTexture_createFromFile("assets/tab_inventory.png", NULL);

    app->inventory->background = sfSprite_create();
    sfSprite_setTexture(app->inventory->background,
        inventory_background_texture, sfTrue);
    app->inventory->trash = sfSprite_create();
    sfSprite_setTexture(app->inventory->trash, trash_can_texture, sfTrue);
}

void setup_hotbar_sprites(app_t *app)
{
    sfTexture *hotbar_background_texture =
        sfTexture_createFromFile("assets/hotbar.png", NULL);

    app->inventory->hotbar = sfSprite_create();
    sfSprite_setTexture(app->inventory->hotbar,
        hotbar_background_texture, sfTrue);
}

void setup_inventory(app_t *app)
{
    init_inventory(app);
    setup_inventory_sprites(app);
    setup_hotbar_sprites(app);
    add_item_to_inventory(app->inventory, create_item(p_apple, 64, 32,
        app->fonts[0]), -1);
    add_item_to_inventory(app->inventory, create_item(p_arrow, 32, 27,
        app->fonts[0]), -1);
    add_item_to_inventory(app->inventory, create_item(p_diamond_axe, 1, 1,
        app->fonts[0]), -1);
    add_item_to_inventory(app->inventory, create_item(p_apple, 64, 18,
        app->fonts[0]), -1);
    add_item_to_inventory(app->inventory, create_item(p_diamond_sword, 1, 1,
        app->fonts[0]), -1);
    add_item_to_inventory(app->inventory, create_item(p_diamond_helmet, 1, 1,
        app->fonts[0]), -1);
    add_item_to_inventory(app->inventory, create_item(p_apple, 64, 20,
        app->fonts[0]), 27);
        add_item_to_inventory(app->inventory, create_item(p_apple, 64, 3,
        app->fonts[0]), 28);
    add_item_to_inventory(app->inventory, create_item(p_apple, 64, 12,
        app->fonts[0]), 29);
    add_item_to_inventory(app->inventory, create_item(p_apple, 64, 20,
        app->fonts[0]), 30);
    add_item_to_inventory(app->inventory, create_item(p_apple, 64, 20,
        app->fonts[0]), 31);
    add_item_to_inventory(app->inventory, create_item(p_apple, 64, 37,
        app->fonts[0]), 32);
    add_item_to_inventory(app->inventory, create_item(p_apple, 64, 11,
        app->fonts[0]), 33);
    add_item_to_inventory(app->inventory, create_item(p_apple, 64, 45,
        app->fonts[0]), 34);
    add_item_to_inventory(app->inventory, create_item(p_apple, 64, 46,
        app->fonts[0]), 35);
    add_item_to_inventory(app->inventory, create_item(p_gold_leggings, 1, 1,
        app->fonts[0]), -1);
    add_item_to_inventory(app->inventory, create_item(p_netherite_chestplate, 1, 1,
        app->fonts[0]), -1);
    add_item_to_inventory(app->inventory, create_item(p_iron_boots, 1, 1,
        app->fonts[0]), -1);
}
