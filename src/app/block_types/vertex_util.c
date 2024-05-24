/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** vertex_util
*/
#include "blocks.h"

bool is_null_vertex(sfVertex vertex)
{
    return (vertex.color.a == 0 && vertex.color.r == 0 && vertex.color.g == 0
        && vertex.color.b == 0 && vertex.position.x == 0 && vertex.position.y
        == 0 && vertex.texCoords.x == 0 && vertex.texCoords.y == 0);
}

sfVertex null_vertex(void)
{
    return (sfVertex){(sfVector2f){0, 0}, (sfColor){0, 0, 0, 0},
        (sfVector2f){0, 0}};
}

int vertex_array_len(sfVertex *arr)
{
    int nb = 0;

    for (; !is_null_vertex(arr[nb]); nb++);
    return nb;
}

void cat_vertex_array(sfVertex *arr1, sfVertex *arr2)
{
    int arr1_len = vertex_array_len(arr1);
    int i = 0;

    for (; !is_null_vertex(arr2[i]); i++)
        arr1[i + arr1_len] = arr2[i];
    arr1[i + arr1_len] = null_vertex();
    free(arr2);
}
