/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** drag_view
*/
#include "rpg.h"

static void update_drag_state(sfEvent *event, sfRenderWindow *window,
    bool *moving, sfVector2f *oldpos)
{
    if (event->type == sfEvtMouseButtonPressed) {
        if (event->mouseButton.button == sfMouseLeft) {
            *moving = true;
            *oldpos = sfRenderWindow_mapPixelToCoords(window,
                (sfVector2i){event->mouseButton.x, event->mouseButton.y},
                NULL);
        }
    }
    if (event->type == sfEvtMouseButtonReleased) {
        if (event->mouseButton.button == sfMouseLeft)
            *moving = false;
    }
}

void drag_view(sfEvent *event, sfRenderWindow *window, sfView *view)
{
    static bool moving = false;
    static sfVector2f oldpos;
    static sfVector2f newpos;
    static sfVector2f delta_pos;

    update_drag_state(event, window, &moving, &oldpos);
    if (event->type == sfEvtMouseMoved) {
        if (!moving)
            return;
        newpos = sfRenderWindow_mapPixelToCoords(window,
            (sfVector2i){event->mouseMove.x, event->mouseMove.y}, NULL);
        delta_pos = (sfVector2f){oldpos.x - newpos.x, oldpos.y - newpos.y};
        sfView_setCenter(view, (sfVector2f){sfView_getCenter(view).x +
            delta_pos.x, sfView_getCenter(view).y + delta_pos.y});
        sfRenderWindow_setView(window, view);
        oldpos = sfRenderWindow_mapPixelToCoords(window,
            (sfVector2i){event->mouseMove.x, event->mouseMove.y}, NULL);
    }
}
