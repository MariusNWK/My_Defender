/*
** EPITECH PROJECT, 2021
** display cases
** File description:
** display the sprites cases and modify sprites depending on status
*/

#include "include/my.h"

void display_cases_2(sfRenderWindow *window, status_t *status, storage_t *st)
{
    int len = len_list(st->cases);

    for (int i = 0; i < 25 * 2; i += 2) {
        if (state_case(window, st, i, status) &&
            status->event == RELEASED) {
            manage_sprite(status, st, i);
        }
    }
}

void display_cases_4(sfRenderWindow *window, status_t *status, storage_t *st)
{
    int len = len_list(st->cases);

    for (int i = 25 * 2; i < 41 * 2; i += 2) {
        if (state_case(window, st, i, status) &&
            status->event == RELEASED) {
            manage_sprite(status, st, i);
        }
    }
}

void display_cases_6(sfRenderWindow *window, status_t *status, storage_t *st)
{
    int len = len_list(st->cases);

    for (int i = 41 * 2; i < len; i += 2) {
        if (state_case(window, st, i, status) &&
            status->event == RELEASED) {
            manage_sprite(status, st, i);
        }
    }
}