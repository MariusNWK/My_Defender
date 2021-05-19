/*
** EPITECH PROJECT, 2021
** display knights
** File description:
** display the knights
*/

#include "include/my.h"

void display_knights_1(sfRenderWindow *window, storage_t *st)
{
    struct game_object knight;
    int len = len_list(st->knights);

    for (int i = len - 1; i >= 0; i--) {
        knight = get_at(st->knights, i);
        if (knight.pos.x < 400 || knight.pos.y <= 280)
            display_sprite(window, st->knights, i);
    }
}

void display_knights_3(sfRenderWindow *window, storage_t *st)
{
    struct game_object knight;
    int len = len_list(st->knights);

    for (int i = len - 1; i >= 0; i--) {
        knight = get_at(st->knights, i);
        if ((knight.pos.x > 1000 && knight.pos.x < 1300 &&
            knight.pos.y > 280 && knight.pos.y <= 480) ||
            (knight.pos.x > 400 && knight.pos.x < 1300 &&
            knight.pos.y >= 400 && knight.pos.y <= 500) ||
            (knight.pos.x > 400 && knight.pos.x < 650 &&
            knight.pos.y >= 480 && knight.pos.y <= 980))
            display_sprite(window, st->knights, i);
    }
}

void display_knights_5(sfRenderWindow *window, storage_t *st)
{
    struct game_object knight;
    int len = len_list(st->knights);

    for (int i = len - 1; i >= 0; i--) {
        knight = get_at(st->knights, i);
        if ((knight.pos.x >= 650 && knight.pos.y >= 500) ||
            knight.pos.x > 1300)
            display_sprite(window, st->knights, i);
    }
}