/*
** EPITECH PROJECT, 2021
** reset
** File description:
** reset the game in case of MENU or TRY AGAIN
*/

#include "include/my.h"

void reset(storage_t *st)
{
    st->hp = 100;
    st->golds = 100000;
    destroy_list_sprites_and_textures(st->cases);
    create_cases(st);
    destroy_list_sprites_and_textures(st->proj);
    create_projectiles(st);
    destroy_list_sprites_and_textures_and_clock(st->knights);
    destroy_list_sprites_and_textures(st->bars);
    st->knights = NULL;
    st->bars = NULL;
    sfClock_restart(st->clocks.timeclock);
    st->knights_killed = 0;
}