/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** main
*/
#include "rpg.h"

int main(int argc, char **argv)
{
    app_t *app = create_app();

    splash_screen(app);
    destroy_app(app);
    return 0;
}
