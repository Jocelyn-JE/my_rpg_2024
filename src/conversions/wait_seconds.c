/*
** EPITECH PROJECT, 2023
** rpg: handle_mouse_button_pressed.c
** File description:
** functions for mouse button pressed
*/

#include "../../include/rpg.h"

void wait_for_seconds(float secs)
{
    sfClock *clock = sfClock_create();

    if (!clock) {
        printf("Failed to create clock\n");
        return;
    }
    while (sfTime_asSeconds(sfClock_getElapsedTime(clock)) < secs);
    sfClock_destroy(clock);
}
