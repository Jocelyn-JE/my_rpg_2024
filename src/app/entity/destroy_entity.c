/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** free_entity
*/
#include "rpg.h"

void destroy_entity(entity_t *entity)
{
    free(entity);
}
