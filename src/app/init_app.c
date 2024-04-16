/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** init_app
*/
#include "rpg.h"
#include <time.h>

static void add_cube(sfVertexArray *vertices, sfVector2f position, int size, char level[])
{
    int block_id = level[(int)position.x + (int)position.y * 1000];
    if (block_id == 0)
        return;
    // Top
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(0 + position.x, 0 + position.y, size), sfWhite, (sfVector2f){0 + (block_id * 16), 0}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(0 + position.x, 1 + position.y, size), sfWhite, (sfVector2f){16 + (block_id * 16), 0}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(1 + position.x, 1 + position.y, size), sfWhite, (sfVector2f){16 + (block_id * 16), 16}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(0 + position.x, 0 + position.y, size), sfWhite, (sfVector2f){0 + (block_id * 16), 0}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(1 + position.x, 0 + position.y, size), sfWhite, (sfVector2f){0 + (block_id * 16), 16}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(1 + position.x, 1 + position.y, size), sfWhite, (sfVector2f){16 + (block_id * 16), 16}});

    // Left
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(1 + position.x, 0 + position.y, size), sfWhite, (sfVector2f){0 + (block_id * 16), 0 + 16}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(2 + position.x, 1 + position.y, size), sfWhite, (sfVector2f){0 + (block_id * 16), 16 + 16}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(1 + position.x, 1 + position.y, size), sfWhite, (sfVector2f){16 + (block_id * 16), 0 + 16}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(1 + position.x, 1 + position.y, size), sfWhite, (sfVector2f){16 + (block_id * 16), 0 + 16}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(2 + position.x, 2 + position.y, size), sfWhite, (sfVector2f){16 + (block_id * 16), 16 + 16}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(2 + position.x, 1 + position.y, size), sfWhite, (sfVector2f){0 + (block_id * 16), 16 + 16}});

    // Right
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(1 + position.x, 1 + position.y, size), sfWhite, (sfVector2f){0 + (block_id * 16), 0 + 32}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(2 + position.x, 2 + position.y, size), sfWhite, (sfVector2f){0 + (block_id * 16), 16 + 32}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(0 + position.x, 1 + position.y, size), sfWhite, (sfVector2f){16 + (block_id * 16), 0 + 32}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(0 + position.x, 1 + position.y, size), sfWhite, (sfVector2f){16 + (block_id * 16), 0 + 32}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(1 + position.x, 2 + position.y, size), sfWhite, (sfVector2f){16 + (block_id * 16), 16 + 32}});
    sfVertexArray_append(vertices,
        (sfVertex){cartesian_to_isometric(2 + position.x, 2 + position.y, size), sfWhite, (sfVector2f){0 + (block_id * 16), 16 + 32}});
}

static void load_map(map_t *map)
{
    sfTexture *stone = sfTexture_createFromFile("assets/textures/atlas.png", NULL);
    int size = 100;
    sfVector2i map_size = {1000, 1000};
    char level[1000 * 1000];

    for (int i = 0; i < map_size.x * map_size.y; i++)
        level[i] = get_random_nb(0, 7);
    map->vertices = sfVertexArray_create();
    map->renderstate = sfRenderStates_default();
    map->transform = sfTransformable_create();
    map->renderstate.texture = stone;
    sfVertexArray_setPrimitiveType(map->vertices, sfTriangles);
    for (int y = 0; y < map_size.y; y++) {
        for (int x = 0; x < map_size.x; x++) {
            add_cube(map->vertices, (sfVector2f){x, y}, size, level);
        }
    }
    sfTransformable_setOrigin(map->transform,
        (sfVector2f){0, sfVertexArray_getBounds(map->vertices).height / 2});
    sfTransformable_setPosition(map->transform,
        (sfVector2f){1920 / 2, 1080 / 2});
    map->renderstate.transform = sfTransformable_getTransform(map->transform);
}

app_t *create_app(void)
{
    app_t *app = malloc(sizeof(app_t));

    srand(time(NULL));
    app->window = create_window(1920, 1080, 32);
    app->map = malloc(sizeof(map_t));
    load_map(app->map);
    return app;
}
