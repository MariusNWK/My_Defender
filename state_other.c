/*
** EPITECH PROJECT, 2021
** other_states
** File description:
** file containing all the different states of a sprite excepted state_button
*/

#include "include/my.h"

int state_tower(sfRenderWindow *window, storage_t *st,
unsigned int pos, status_t *status)
{
    sfVector2f mouse = vectorf(sfMouse_getPositionRenderWindow(window).x,
    sfMouse_getPositionRenderWindow(window).y);

    if (does_mouse_touch_sprite(get_at(st->play, pos + 1), mouse) &&
        status->play != GAMEOVER && st->echap == sfFalse) {
        display_sprite(window, st->play, pos + 1);
        return (1);
    }
    display_sprite(window, st->play, pos);
    return (0);
}

int state_case(sfRenderWindow *window, storage_t *st,
unsigned int pos, status_t *status)
{
    sfVector2f mouse = vectorf(sfMouse_getPositionRenderWindow(window).x,
    sfMouse_getPositionRenderWindow(window).y);

    if (does_mouse_touch_sprite(get_at(st->cases, pos), mouse) &&
        status->touchcase == FALSE && status->play == ALIVE &&
        st->echap == sfFalse) {
        display_sprite(window, st->cases, pos + 1);
        status->touchcase = TRUE;
        return (1);
    }
    status->touchcase = FALSE;
    display_sprite(window, st->cases, pos);
    return (0);
}