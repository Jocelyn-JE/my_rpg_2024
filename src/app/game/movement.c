/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** movement
*/
#include "rpg.h"

static void set_player_entity_pos(player_t *player, entity_t *player_entity)
{
    player_entity->pos.x = player->pos.x;
    player_entity->pos.y = player->pos.y;
}

static void move_left(player_t *player, float speed)
{
    player->pos.x -= speed;
}

static void move_right(player_t *player, float speed)
{
    player->pos.x += speed;
}

static void move_up(player_t *player, float speed)
{
    player->pos.y -= speed;
}

static void move_down(player_t *player, float speed)
{
    player->pos.y += speed;
}

static bool check_time(sfTime dt)
{
    static sfTime prev_dt = {(sfInt64){0}};

    if (sfTime_asMilliseconds(dt) - sfTime_asMilliseconds(prev_dt) > 10) {
        prev_dt.microseconds = dt.microseconds;
        return false;
    }
    return true;
}

static void move_player(player_t *player, float speed)
{
    int prev_x = round((player->pos.x - speed));
    int next_x = round((player->pos.x + speed));
    int prev_y = round((player->pos.y - speed));
    int next_y = round((player->pos.y + speed));

    if (sfKeyboard_isKeyPressed(sfKeyQ) && (prev_x > 0 && next_y > 0) &&
        (next_x <= 512.f && next_y < 512.f))
        move_left(player, speed);
    if (sfKeyboard_isKeyPressed(sfKeyD) && (next_x > 0 && prev_y > 0) &&
        (next_x < 512.f && next_y <= 512.f))
        move_right(player, speed);
    if (sfKeyboard_isKeyPressed(sfKeyZ) && (prev_x > 0 && prev_y > 0) &&
        (next_x <= 512.f && next_y <= 512.f))
        move_up(player, speed);
    if (sfKeyboard_isKeyPressed(sfKeyS) && (next_x > 0 && next_y > 0) &&
        (next_x < 512.f && next_y < 512.f))
        move_down(player, speed);
}

void handle_movement(player_t *player, entity_t *player_entity, sfTime dt)
{
    float speed = 0.04317f;

    if (check_time(dt))
        return;
    if (sfKeyboard_isKeyPressed(sfKeyLControl))
        speed = 0.07806f;
    move_player(player, speed);
    set_player_entity_pos(player, player_entity);
}
