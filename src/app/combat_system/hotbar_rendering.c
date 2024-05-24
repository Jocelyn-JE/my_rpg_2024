/*
** EPITECH PROJECT, 2023
** my_rpg: setup_combat.c
** File description:
** combat initialization file
*/

#include "../../../include/rpg.h"

static int set_texture(sfSprite *hotbar_sprite, sfTexture *texture)
{
    sfSprite_setTexture(hotbar_sprite, texture, sfTrue);
    return 0;
}

sfSprite *setup_hotbar_sprite(app_t *app)
{
    const sfTexture *texture = sfSprite_getTexture(app->inventory->hotbar);
    sfSprite *hotbar_sprite = sfSprite_create();
    int ret = set_texture(hotbar_sprite, (sfTexture *)texture);
    sfVector2f center = sfView_getCenter(app->view);
    sfVector2f size = sfView_getSize(app->view);
    sfFloatRect backgroundBounds = sfSprite_getGlobalBounds(hotbar_sprite);
    float hotbarX = center.x - backgroundBounds.width * 2.46;
    float hotbarY = center.y + (size.y / 2.35) - backgroundBounds.height;

    ret = ret;
    sfSprite_setPosition(hotbar_sprite, (sfVector2f){hotbarX, hotbarY});
    sfSprite_setScale(hotbar_sprite, (sfVector2f){5, 5});
    return hotbar_sprite;
}

void draw_selection_game(app_t *app,
    sfFloatRect hotbarBounds, float itemWidth)
{
    float selectionX = hotbarBounds.left +
        app->game_ressources->selected_item * (itemWidth + 3.23f);
    sfVector2f selection_position = {selectionX, hotbarBounds.top};

    sfSprite_setPosition(app->inventory->selection, selection_position);
    sfSprite_setScale(app->inventory->selection, (sfVector2f){4.7, 4.7});
    sfRenderWindow_drawSprite(app->window, app->inventory->selection, NULL);
}

static void draw_item_combat(app_t *app, sfVector2f pos, int i)
{
    char quantity[10];
    item_t *item = app->inventory->slots[i + 27];

    if (item->limit <= 1)
        return;
    sprintf(quantity, "%2d", item->quantity);
    sfText_setString(item->quantity_text, quantity);
    sfText_setCharacterSize(item->quantity_text, 22);
    sfText_setPosition(item->quantity_text,
        (sfVector2f){pos.x + 46, pos.y + 49});
    sfRenderWindow_drawText(app->window, item->quantity_text, NULL);
}

void draw_hotbar_items_game(app_t *app, sfSprite *hotbar_sprite)
{
    sfFloatRect hotbarBounds = sfSprite_getGlobalBounds(hotbar_sprite);
    float itemWidth = (hotbarBounds.width - (5.f * (9 - 1))) / 9;
    float itemX = 0.f;
    sfVector2f item_pos = {0, 0};

    sfRenderWindow_drawSprite(app->window, hotbar_sprite, NULL);
    for (int i = 0; i < 9; i++) {
        if (app->inventory->slots[i + 27] == NULL)
            continue;
        itemX = hotbarBounds.left + i * (itemWidth + 3.23f);
        item_pos.x = itemX + 17;
        item_pos.y = hotbarBounds.top + 18;
        sfSprite_setPosition(app->inventory->slots[i + 27]->sprite, item_pos);
        sfSprite_setScale(app->inventory->slots[i + 27]->sprite,
            (sfVector2f){4.7, 4.7});
        sfRenderWindow_drawSprite(app->window,
            app->inventory->slots[i + 27]->sprite, NULL);
        draw_item_combat(app, item_pos, i);
    }
    draw_selection_game(app, hotbarBounds, itemWidth);
}

void display_hotbar_unavailable(app_t *app, sfSprite *hotbarSprite)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfFloatRect hotbarBounds = sfSprite_getGlobalBounds(hotbarSprite);
    sfVector2f hotbarPos = sfSprite_getPosition(hotbarSprite);
    sfVector2f rectSize = {hotbarBounds.width, hotbarBounds.height};
    sfVector2f rectPos = hotbarPos;

    sfRectangleShape_setSize(rect, rectSize);
    sfRectangleShape_setPosition(rect, rectPos);
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(0, 0, 0, 150));
    sfRenderWindow_drawRectangleShape(app->window, rect, NULL);
    sfRenderWindow_display(app->window);
    sfRectangleShape_destroy(rect);
}
