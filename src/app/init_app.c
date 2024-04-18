/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** init_app
*/
#include "rpg.h"
#include <time.h>
#include "blocks.h"

static void add_cube(sfVertexArray *vertices, sfVector3f f_position, char ***level, sfVector3u level_size)
{
    sfVector3i position = {f_position.x, f_position.y, f_position.z};
    int block_id = level[position.x][position.y][position.z];
    int size = 100;

    if (block_id == 0 || (!(position.z + 1 > level_size.z - 1 ||
        position.x + 1 > level_size.x - 1 ||
        position.y + 1 > level_size.y - 1) &&
        level[position.x + 1][position.y + 1][position.z + 1] != 1))
        return;
    // Top
    if (position.z + 1 > level_size.z - 1 || level[position.x][position.y][position.z + 1] == 1) {
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(0 + f_position.x - f_position.z, 0 + f_position.y - f_position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 0}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(0 + f_position.x - f_position.z, 1 + f_position.y - f_position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 0}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(1 + f_position.x - f_position.z, 1 + f_position.y - f_position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 16}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(0 + f_position.x - f_position.z, 0 + f_position.y - f_position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 0}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(1 + f_position.x - f_position.z, 0 + f_position.y - f_position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 16}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(1 + f_position.x - f_position.z, 1 + f_position.y - f_position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 16}});
    }
    // Left
    if (position.x + 1 > level_size.x - 1 || level[position.x + 1][position.y][position.z] == 1) {
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(1 + f_position.x - f_position.z, 0 + f_position.y - f_position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 0 + 16}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(2 + f_position.x - f_position.z, 1 + f_position.y - f_position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 16 + 16}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(1 + f_position.x - f_position.z, 1 + f_position.y - f_position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 0 + 16}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(1 + f_position.x - f_position.z, 1 + f_position.y - f_position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 0 + 16}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(2 + f_position.x - f_position.z, 2 + f_position.y - f_position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 16 + 16}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(2 + f_position.x - f_position.z, 1 + f_position.y - f_position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 16 + 16}});
    }
    // Right
    if (position.y + 1 > level_size.y - 1 || level[position.x][position.y + 1][position.z] == 1) {
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(1 + f_position.x - f_position.z, 1 + f_position.y - f_position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 0 + 32}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(2 + f_position.x - f_position.z, 2 + f_position.y - f_position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 16 + 32}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(0 + f_position.x - f_position.z, 1 + f_position.y - f_position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 0 + 32}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(0 + f_position.x - f_position.z, 1 + f_position.y - f_position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 0 + 32}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(1 + f_position.x - f_position.z, 2 + f_position.y - f_position.z, size), sfWhite, (sfVector2f){16 + (block_id * 16), 16 + 32}});
        sfVertexArray_append(vertices,
            (sfVertex){cartesian_to_isometric(2 + f_position.x - f_position.z, 2 + f_position.y - f_position.z, size), sfWhite, (sfVector2f){0 + (block_id * 16), 16 + 32}});
    }
}

static char ***create_3d_chunk(sfVector3u *chunk_size)
{
    char ***array = malloc(sizeof(char **) * chunk_size->x);

    for (int x = 0; x != chunk_size->x; x++) {
        array[x] = malloc(sizeof(char *) * chunk_size->y);
        for (int y = 0; y != chunk_size->y; y++)
            array[x][y] = malloc(sizeof(char) * chunk_size->z);
    }
    return array;
}

static void load_chunk(chunk_t *map)
{
    sfTexture *stone = sfTexture_createFromFile("assets/textures/atlas.png", NULL);
    sfVector3u chunk_size = {16, 16, 16};
    char ***level = create_3d_chunk(&chunk_size);

    for (int x = 0; x < chunk_size.x; x++) {
        for (int y = 0; y < chunk_size.y; y++) {
            for (int z = 0; z < chunk_size.z; z++) {
                if (z != 0)
                    level[x][y][z] = get_random_nb(b_stone, b_library);
                else 
                    level[x][y][z] = b_grass;
            }
        }
    }
    map->vertices = sfVertexArray_create();
    map->renderstate = sfRenderStates_default();
    map->transform = sfTransformable_create();
    map->renderstate.texture = stone;
    sfVertexArray_setPrimitiveType(map->vertices, sfTriangles);
    for (int y = 0; y < chunk_size.y; y++) {
        for (int x = 0; x < chunk_size.x; x++) {
            for (int z = 0; z < chunk_size.z; z++)
                add_cube(map->vertices, (sfVector3f){x, y, z}, level, chunk_size);
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
    app->map = malloc(sizeof(chunk_t *) * 2);
    app->map[0] = malloc(sizeof(chunk_t));
    load_chunk(app->map[0]);
    return app;
}
