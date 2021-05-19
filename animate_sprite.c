/*
** EPITECH PROJECT, 2021
** animate_sprite
** File description:
** animate sprite defining limits of rect in x and y
*/

#include "include/my.h"

list_t *animate_sprite(list_t *list, unsigned int pos,
sfClock *clock, limits_t lim)
{
    struct game_object obj = get_at(list, pos);
    float seconds = seconds_clock(clock);

    while (seconds >= 0.2) {
        obj.rect.left += lim.offset_x;
        sfClock_restart(clock);
        if (obj.rect.left >= lim.lim_x) {
            obj.rect.top += lim.offset_y;
            obj.rect.left = 0;
        }
        if (obj.rect.top >= lim.lim_y) {
            obj.rect.top = 0;
        }
        seconds -= 0.2;
    }
    apply_settings(&obj);
    set_at(list, obj, pos);
    return (list);
}