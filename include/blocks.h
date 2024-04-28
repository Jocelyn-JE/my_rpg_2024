/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** blocks
*/

#pragma once
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdbool.h>
#include <stdint.h>

enum blocks {
    b_null,
    b_air,
    b_stone,
    b_planks,
    b_log,
    b_grass,
    b_barrel,
    b_hive,
    b_library,
    b_cactus
};

typedef struct block_s {
    sfVertexArray *top;
    sfVertexArray *right;
    sfVertexArray *left;
    bool transparent;
} block_t;
