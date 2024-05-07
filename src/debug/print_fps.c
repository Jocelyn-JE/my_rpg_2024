/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** print_fps
*/
#include "../../include/rpg.h"

void print_framerate(void)
{
    static int first = 1;
    static sfClock *clock;
    static int fps = 0;
    sfTime elapsed = sfTime_Zero;

    if (first == 1) {
        clock = sfClock_create();
        first = 0;
    }
    elapsed = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed) >= 1) {
        printf("FPS: %3d\n", fps);
        fflush(stdout);
        fps = 0;
        sfClock_restart(clock);
    } else
        fps ++;
}
