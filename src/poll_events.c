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

inventory_params_t setup_inventory_params(int x, int y, app_t *app)
{
    inventory_params_t params;

    params.world_pos = sfRenderWindow_mapPixelToCoords(
        app->window, (sfVector2i){x, y}, app->view);
    params.center = sfView_getCenter(app->view);
    params.size = sfView_getSize(app->view);
    params.scale = adjust_sprite_scale(app->inventory, 1.0f, app->zoom);
    params.offset_X = 645 * params.scale;
    params.offset_Y = 548 * params.scale;
    params.slot_width = 72 * params.scale;
    params.slot_height = 72 * params.scale;
    params.spacing = 1.35 * params.scale;
    return params;
}

int thing_indexing(sfVector2f start_cor, int column, int row,
    inventory_params_t params)
{
    float slotLeft = start_cor.x + column *
        (params.slot_width + params.spacing);
    float slotTop = start_cor.y + row *
        (params.slot_height + params.spacing);
    float slotRight = slotLeft + params.slot_width;
    float slotBottom = slotTop + params.slot_height;

    if (params.world_pos.x >= slotLeft && params.world_pos.x <= slotRight &&
        params.world_pos.y >= slotTop && params.world_pos.y <= slotBottom) {
        return row * 9 + column;
    }
    return -1;
}

int calculate_slot_index(inventory_params_t params)
{
    float start_x = params.center.x - params.size.x / 2 + params.offset_X;
    float start_y = params.center.y - params.size.y / 2 + params.offset_Y;
    sfVector2f start_cor = {start_x, start_y};
    int column = (int)((params.world_pos.x - start_x) /
        (params.slot_width + params.spacing));
    int row = (int)((params.world_pos.y - start_y) /
        (params.slot_height + params.spacing));

    if (row >= 0 && row < 4 && column >= 0 && column < 9) {
        return thing_indexing(start_cor, column, row, params);
    }
    return -1;
}

int get_slot_index(int x, int y, app_t *app)
{
    inventory_params_t params = setup_inventory_params(x, y, app);

    return calculate_slot_index(params);
}

void case_picking(app_t *app, int slot_index)
{
    if (slot_index != -1 && app->inventory->slots[slot_index] != NULL) {
        app->inventory->dragging_slot = slot_index;
        app->inventory->dragged_item = app->inventory->slots[slot_index];
        app->inventory->slots[slot_index] = NULL;
    }
}

void case_dropping(app_t *app, int slot_index)
{
    item_t *temp = NULL;

    if (slot_index == -1)
        return;
    if (app->inventory->slots[slot_index] == NULL) {
        app->inventory->slots[slot_index] = app->inventory->dragged_item;
        app->inventory->dragged_item = NULL;
        app->inventory->dragging_slot = -1;
    } else {
        temp = app->inventory->slots[slot_index];
        app->inventory->slots[slot_index] = app->inventory->dragged_item;
        app->inventory->dragged_item = temp;
        app->inventory->dragging_slot = slot_index;
    }
}

void handle_mouse_button_pressed(sfRenderWindow *window,
    sfEvent *event, app_t *app)
{
    int slot_index =
        get_slot_index(event->mouseButton.x, event->mouseButton.y, app);

    if (event->type == sfEvtMouseButtonPressed &&
        event->mouseButton.button == sfMouseLeft &&
        app->game_state == INVENTORY) {
        if (app->inventory->dragged_item == NULL) {
            case_picking(app, slot_index);
        } else {
            case_dropping(app, slot_index);
        }
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
            sfVector2f worldPos = sfRenderWindow_mapPixelToCoords(
                app->window, pixelPos, app->view);
            sfSprite_setPosition(app->inventory->dragged_item->sprite,
                                 worldPos);
        }
    }
    handle_mouse_button_pressed(app->window, event, app);
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
