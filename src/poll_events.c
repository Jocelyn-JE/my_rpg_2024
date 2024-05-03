/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** poll_events
*/
#include "../include/rpg.h"
#include <SFML/Window/Event.h>

static void update_debug_options(sfKeyEvent *event, debug_t *options)
{
    if (event->code == sfKeyW && options->wireframe)
        options->wireframe = false;
    else if (event->code == sfKeyW)
        options->wireframe = true;
    if (event->code == sfKeyX && options->bounding_box)
        options->bounding_box = false;
    else if (event->code == sfKeyX)
        options->bounding_box = true;
    if (event->code == sfKeyF3 && options->fps)
        options->fps = false;
    else if (event->code == sfKeyX)
        options->fps = true;
}

static void zoom_view(sfEvent *event, app_t *app)
{
    float zoom = 0;

    if (!sfKeyboard_isKeyPressed(sfKeyLShift))
        return;
    if (event->type == sfEvtMouseWheelScrolled) {
        zoom = event->mouseWheelScroll.delta > 0.0f ? 0.9f : 1.1f;
        if ((app->zoom * zoom) > 5 || (app->zoom * zoom) < 0.2)
            return;
        app->zoom *= zoom;
        sfView_zoom(app->view, zoom);
    }
}

void manage_inventory_input(app_t *app, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyE) {
        if (app->game_state == INVENTORY)
            app->game_state = GAME;
        else
            app->game_state = INVENTORY;
    }
}

void handle_mouse_wheel(app_t *app, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        return;
    if (event.type != sfEvtMouseWheelScrolled || app->game_state != GAME)
        return;
    if (event.mouseWheelScroll.delta > 0) {
        app->inventory->selected_slot--;
        if (app->inventory->selected_slot < 0) {
            app->inventory->selected_slot = 8;
        }
    } else {
        app->inventory->selected_slot++;
        if (app->inventory->selected_slot > 8) {
            app->inventory->selected_slot = 0;
        }
    }
}

int get_slot_index_from_mouse_position(int x, int y, app_t *app)
{
    sfVector2i pixelPos = {x, y};
    sfVector2f worldPos = sfRenderWindow_mapPixelToCoords(app->window, pixelPos, app->view);
    sfVector2f center = sfView_getCenter(app->view);
    sfVector2f size = sfView_getSize(app->view);
    float scale = adjust_sprite_scale(app->inventory, 1.0f, app->zoom);
    float offsetX = 645 * scale;
    float offsetY = 548 * scale;
    float start_x = center.x - size.x / 2 + offsetX;
    float start_y = center.y - size.y / 2 + offsetY;
    int slotWidth = 72 * scale;
    int slotHeight = 72 * scale;
    int spacing = 1.35 * scale;
    int column = (int)((worldPos.x - start_x) / (slotWidth + spacing));
    int row = (int)((worldPos.y - start_y) / (slotHeight + spacing));

    if (row >= 0 && row < 4 && column >= 0 && column < 9) {
        float slotLeft = start_x + column * (slotWidth + spacing);
        float slotTop = start_y + row * (slotHeight + spacing);
        float slotRight = slotLeft + slotWidth;
        float slotBottom = slotTop + slotHeight;
        if (worldPos.x >= slotLeft && worldPos.x <= slotRight && worldPos.y >= slotTop && worldPos.y <= slotBottom) {
            return row * 9 + column;
        }
    }
    return -1;
}

void handle_mouse_button_pressed(sfRenderWindow *window, sfEvent *event, app_t *app) {
    if (event->type == sfEvtMouseButtonPressed && event->mouseButton.button == sfMouseLeft && app->game_state == INVENTORY) {
        int slotIndex = get_slot_index_from_mouse_position(event->mouseButton.x, event->mouseButton.y, app);
        if (slotIndex != -1 && app->inventory->slots[slotIndex] != NULL) {
            app->inventory->dragging_slot = slotIndex;
            app->inventory->dragged_item = app->inventory->slots[slotIndex];
        }
    }
}

void handle_mouse_button_released(sfRenderWindow *window, sfEvent *event, app_t *app) {
    if (event->type == sfEvtMouseButtonReleased && event->mouseButton.button == sfMouseLeft && app->inventory->dragged_item && app->game_state == INVENTORY) {
        int releaseSlotIndex = get_slot_index_from_mouse_position(event->mouseButton.x, event->mouseButton.y, app);
        if (releaseSlotIndex != -1 && releaseSlotIndex != app->inventory->dragging_slot) {
            if (app->inventory->slots[releaseSlotIndex] == NULL) {
                app->inventory->slots[releaseSlotIndex] = app->inventory->dragged_item;
                app->inventory->slots[app->inventory->dragging_slot] = NULL;
            } else {
                item_t *temp = app->inventory->slots[releaseSlotIndex];
                app->inventory->slots[releaseSlotIndex] = app->inventory->dragged_item;
                app->inventory->slots[app->inventory->dragging_slot] = temp;
            }
        }
        app->inventory->dragged_item = NULL;
        app->inventory->dragging_slot = -1;
    }
}


static void handle_events(app_t *app, sfEvent *event)
{
    if (event->type == sfEvtResized)
        get_letterbox_view(app->view,
            (sfVector2f){event->size.width, event->size.height});
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(app->window);
    manage_inventory_input(app, event);
    if (event->type == sfEvtMouseMoved && app->game_state == INVENTORY) {
        if (app->inventory->dragged_item != NULL) {
            sfVector2i pixelPos = {event->mouseMove.x, event->mouseMove.y};
            sfVector2f worldPos = sfRenderWindow_mapPixelToCoords(app->window, pixelPos, app->view);
            sfSprite_setPosition(app->inventory->dragged_item->sprite, worldPos);
        }
    }
    handle_mouse_button_pressed(app->window, event, app);
    handle_mouse_button_released(app->window, event, app);
    if (app->game_state == INVENTORY)
        return;
    if (event->type == sfEvtKeyPressed)
        update_debug_options(&event->key, app->debug_options);
    handle_mouse_wheel(app, *event);
    drag_view(event, app->window, app->view);
    zoom_view(event, app);
}

void poll_events(app_t *app, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(app->window, event) &&
        sfRenderWindow_hasFocus(app->window))
        handle_events(app, event);
}
