/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** update_blocks
*/
#include "blocks.h"

static sfVector2f water_anim[] = {
    (sfVector2f){0, 112},
    (sfVector2f){16, 112},
    (sfVector2f){32, 112},
    (sfVector2f){48, 112},
    (sfVector2f){64, 112},
    (sfVector2f){80, 112},
    (sfVector2f){96, 112},
    (sfVector2f){112, 112},
    (sfVector2f){128, 112},
    (sfVector2f){144, 112},
    (sfVector2f){160, 112},
    (sfVector2f){0, 128},
    (sfVector2f){16, 128},
    (sfVector2f){32, 128},
    (sfVector2f){48, 128},
    (sfVector2f){64, 128},
    (sfVector2f){80, 128},
    (sfVector2f){96, 128},
    (sfVector2f){112, 128},
    (sfVector2f){128, 128},
    (sfVector2f){144, 128},
    (sfVector2f){160, 128},
    (sfVector2f){0, 144},
    (sfVector2f){16, 144},
    (sfVector2f){32, 144},
    (sfVector2f){48, 144},
    (sfVector2f){64, 144},
    (sfVector2f){80, 144},
    (sfVector2f){96, 144},
    (sfVector2f){112, 144},
    (sfVector2f){128, 144},
    (sfVector2f){144, 144}
};

static sfVector2f lava_anim[] = {
    (sfVector2f){160, 144},
    (sfVector2f){0, 160},
    (sfVector2f){16, 160},
    (sfVector2f){32, 160},
    (sfVector2f){48, 160},
    (sfVector2f){64, 160},
    (sfVector2f){80, 160},
    (sfVector2f){96, 160},
    (sfVector2f){112, 160},
    (sfVector2f){128, 160},
    (sfVector2f){144, 160},
    (sfVector2f){160, 160},
    (sfVector2f){0, 176},
    (sfVector2f){16, 176},
    (sfVector2f){32, 176},
    (sfVector2f){48, 176},
    (sfVector2f){64, 176},
    (sfVector2f){80, 176},
    (sfVector2f){96, 176},
    (sfVector2f){112, 176}
};

static bool check_time_water(sfTime dt)
{
    static sfTime prev_dt = {(sfInt64){0}};

    if (sfTime_asMilliseconds(dt) - sfTime_asMilliseconds(prev_dt) > 100) {
        prev_dt.microseconds = dt.microseconds;
        return false;
    }
    return true;
}

static bool check_time_lava(sfTime dt)
{
    static sfTime prev_dt = {(sfInt64){0}};

    if (sfTime_asMilliseconds(dt) - sfTime_asMilliseconds(prev_dt) > 100) {
        prev_dt.microseconds = dt.microseconds;
        return false;
    }
    return true;
}

static void update_water(block_t *water, sfTime dt)
{
    static int i = 0;

    if (check_time_water(dt))
        return;
    free(water->faces[0]);
    water->faces[0] = get_water_face((uv_coords_t){water_anim[i],
        (sfVector2f){water_anim[i].x + 16, water_anim[i].y + 16}},
        (sfVector2f){(1.f / 16.f) * 2, (1.f / 16.f) * 2});
    i++;
    if (i == 32)
        i = 0;
}

static void update_lava(block_t *lava, sfTime dt)
{
    static int i = 0;
    static int offset = 1;

    if (check_time_lava(dt))
        return;
    free(lava->faces[0]);
    lava->faces[0] = get_lava_face((uv_coords_t){lava_anim[i],
        (sfVector2f){lava_anim[i].x + 16, lava_anim[i].y + 16}},
        (sfVector2f){(1.f / 16.f) * 2, (1.f / 16.f) * 2});
    if (i == 0)
        offset = 1;
    if (i == 19)
        offset = -1;
    i += offset;
}

void update_blocks(block_t **blocks, sfTime dt)
{
    update_water(blocks[b_water], dt);
    update_lava(blocks[b_lava], dt);
}
