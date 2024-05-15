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
    sfVector2i prev = {player->pos.x - speed, player->pos.y - speed};
    sfVector2i next = {player->pos.x + speed, player->pos.y + speed};
    block_t **blocks = game->block_types;

    if (sfKeyboard_isKeyPressed(sfKeyQ) && get_block((sfVector3f){prev.x,
            player->pos.y, 1}, blocks, game->map)->solid && !get_block(
            (sfVector3f){prev.x, player->pos.y, 2}, blocks, game->map)->solid)
        move_left(player, speed);
    if (sfKeyboard_isKeyPressed(sfKeyD) && get_block((sfVector3f){next.x,
            player->pos.y, 1}, blocks, game->map)->solid && !get_block(
            (sfVector3f){next.x, player->pos.y, 2}, blocks, game->map)->solid)
        move_right(player, speed);
    if (sfKeyboard_isKeyPressed(sfKeyZ) && get_block((sfVector3f){
            player->pos.x, prev.y, 1}, blocks, game->map)->solid && !get_block(
            (sfVector3f){player->pos.x, prev.y, 2}, blocks, game->map)->solid)
        move_up(player, speed);
    if (sfKeyboard_isKeyPressed(sfKeyS) && get_block((sfVector3f){
            player->pos.x, next.y, 1}, blocks, game->map)->solid && !get_block(
            (sfVector3f){player->pos.x, next.y, 2}, blocks, game->map)->solid)
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
