/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** init_app
*/
#include "rpg.h"
#include <time.h>
#include "blocks.h"

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

static void load_chunk(chunk_t *chunk)
{
    sfTexture *stone = sfTexture_createFromFile("assets/textures/atlas.png", NULL);
    sfVector3u chunk_size = {16, 16, 16};
    char ***level = create_3d_chunk(&chunk_size);

    for (int x = 0; x < chunk_size.x; x++) {
        for (int y = 0; y < chunk_size.y; y++) {
            for (int z = 0; z < chunk_size.z; z++) {
                if (z > 10)
                    level[x][y][z] = b_air;
                else 
                    level[x][y][z] = b_grass;
            }
        }
    }
    chunk->vertices = sfVertexArray_create();
    chunk->renderstate = sfRenderStates_default();
    chunk->transform = sfTransformable_create();
    chunk->renderstate.texture = stone;
    sfVertexArray_setPrimitiveType(chunk->vertices, sfTriangles);
    for (int y = 0; y < chunk_size.y; y++) {
        for (int x = 0; x < chunk_size.x; x++) {
            for (int z = 0; z < chunk_size.z; z++)
                add_cube(chunk->vertices, (sfVector3f){x, y, z}, level, chunk_size);
        }
    }
    chunk->renderstate.transform = sfTransformable_getTransform(chunk->transform);
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
