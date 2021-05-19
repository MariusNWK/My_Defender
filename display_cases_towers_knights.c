/*
** EPITECH PROJECT, 2021
** display cases towers knights
** File description:
** display the cases, the towers and the knights
*/

#include "include/my.h"

void define_width_green(storage_t *st)
{
    int len = len_list(st->knights);
    struct game_object green;
    struct game_object knight;

    for (int i = 0; i < len; i++) {
        knight = get_at(st->knights, i);
        green = get_at(st->bars, i * 2 + 1);
        if (knight.rect.left >= 468)
            green.rect.width = (knight.hp * 1000 /
            (200 + st->knights_killed * 2)) * 0.1 * 0.4 + 1;
        else
            green.rect.width = (knight.hp * 1000 /
            (100 + st->knights_killed)) * 0.1 * 0.4 + 1;
        sfSprite_setTextureRect(green.sprite, green.rect);
        set_at(st->bars, green, i * 2 + 1);
    }
}

void display_hp_bars(sfRenderWindow *window, storage_t *st)
{
    int len = len_list(st->bars);

    define_width_green(st);
    for (int i = 0; i < len; i++) {
        display_sprite(window, st->bars, i);
    }
}

void display_cases_towers_knights(sfRenderWindow *window,
status_t *status, storage_t *st)
{
    create_display_destroy_knights(window, status, st);
    display_knights_1(window, st);
    display_cases_2(window, status, st);
    display_knights_3(window, st);
    display_cases_4(window, status, st);
    display_knights_5(window, st);
    display_cases_6(window, status, st);
    display_hp_bars(window, st);
}