/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** rpg
*/

#include "../../../include/rpg.h"

void free_item(item_t *item)
{
    if (item == NULL)
        return;
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(item->sprite));
    sfSprite_destroy(item->sprite);
    if (item->quantity > 1)
        sfText_destroy(item->quantity_text);
    free(item);
}

void free_inventory(inventory_t *inventory)
{
    for (int i = 0; i < 36; i++)
        free_item(inventory->slots[i]);
    for (int i = 0; i < 4; i++)
        free_item(inventory->armor[i]);
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(inventory->selection));
    sfSprite_destroy(inventory->selection);
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(inventory->background));
    sfSprite_destroy(inventory->background);
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(inventory->trash));
    sfSprite_destroy(inventory->trash);
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(inventory->hotbar));
    sfSprite_destroy(inventory->hotbar);
    free(inventory);
}

item_t *copy_item(item_t *original)
{
    item_t *copy = malloc(sizeof(item_t));
    sfTexture *original_texture = NULL;
    sfTexture *cloned_texture = NULL;

    if (copy == NULL || original == NULL)
        return NULL;
    copy->current_item = original->current_item;
    copy->limit = original->limit;
    copy->quantity = original->quantity;
    original_texture = (sfTexture*)sfSprite_getTexture(original->sprite);
    cloned_texture = sfTexture_copy(original_texture);
    copy->sprite = sfSprite_create();
    sfSprite_setTexture(copy->sprite, cloned_texture, sfFalse);
    sfSprite_setPosition(copy->sprite, sfSprite_getPosition(original->sprite));
    sfSprite_setScale(copy->sprite, sfSprite_getScale(original->sprite));
    if (original->limit > 1 && original->quantity_text)
        copy->quantity_text = sfText_copy(original->quantity_text);
    return copy;
}
