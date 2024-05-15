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

static bool check_time(sfTime dt)
{
    static sfTime prev_dt = {(sfInt64){0}};

    if (sfTime_asMilliseconds(dt) - sfTime_asMilliseconds(prev_dt) > 10) {
        prev_dt.microseconds = dt.microseconds;
        return false;
    }
    return true;
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

static void move_player(player_t *player, float speed, game_t *game)
{
    sfVector2i prev = {(int)round(player->pos.x - speed), (int)round(player->pos.y - speed)};
    sfVector2i next = {(int)round(player->pos.x + speed), (int)round(player->pos.y + speed)};

    if (sfKeyboard_isKeyPressed(sfKeyQ) && prev.x > 0 && prev.x < 512.f &&
        get_block((sfVector2i){floor(player->pos.x - speed), floor(player->pos.y)}, game->block_types, game->map, 1)->solid &&
        !get_block((sfVector2i){floor(player->pos.x - speed), floor(player->pos.y)}, game->block_types, game->map, 2)->solid)
        move_left(player, speed);
    if (sfKeyboard_isKeyPressed(sfKeyD) && next.x > 0 && next.x < 512.f &&
        get_block((sfVector2i){floor(player->pos.x + speed), floor(player->pos.y)}, game->block_types, game->map, 1)->solid &&
        !get_block((sfVector2i){floor(player->pos.x + speed), floor(player->pos.y)}, game->block_types, game->map, 2)->solid)
        move_right(player, speed);
    if (sfKeyboard_isKeyPressed(sfKeyZ) && prev.y > 0 && prev.y < 512.f &&
        get_block((sfVector2i){floor(player->pos.x), floor(player->pos.y - speed)}, game->block_types, game->map, 1)->solid &&
        !get_block((sfVector2i){floor(player->pos.x), floor(player->pos.y - speed)}, game->block_types, game->map, 2)->solid)
        move_up(player, speed);
    if (sfKeyboard_isKeyPressed(sfKeyS) && next.y > 0 && next.y < 512.f &&
        get_block((sfVector2i){floor(player->pos.x), floor(player->pos.y + speed)}, game->block_types, game->map, 1)->solid &&
        !get_block((sfVector2i){floor(player->pos.x), floor(player->pos.y + speed)}, game->block_types, game->map, 2)->solid)
        move_down(player, speed);
}

void handle_movement(player_t *player, entity_t *player_entity, sfTime dt, 
    game_t *game)
{
    float speed = 0.04317f;

    if (check_time(dt))
        return;
    if (sfKeyboard_isKeyPressed(sfKeyLControl))
        speed = 0.07806f;
    move_player(player, speed, game);
    set_player_entity_pos(player, player_entity);
}
