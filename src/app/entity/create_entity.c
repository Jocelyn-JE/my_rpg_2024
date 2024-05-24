/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** create_entity
*/
#include "../../../include/rpg.h"

entity_t *create_entity(sfVector2f pos, uint32_t type, e_state_t orientation, stat_t stats)
{
    entity_t *new_entity = malloc(sizeof(entity_t));

    new_entity->pos = pos;
    new_entity->type = type;
    new_entity->stats = stats;
    new_entity->state = orientation;
    return new_entity;
}
