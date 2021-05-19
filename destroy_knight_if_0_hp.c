/*
** EPITECH PROJECT, 2021
** destroy knight if 0 hp
** File description:
** destroy a knight if he has 0 hp
*/

#include "include/my.h"

void destroy_knight_if_0_hp(storage_t *st)
{
    int len = len_list(st->knights);
    struct game_object knight;

    for (int i = 0; i < len; i++) {
        knight = get_at(st->knights, i);
        if (knight.hp <= 0) {
            destroy_obj_sprite_and_texture_and_clock(knight);
            st->knights = free_at(st->knights, i);
            destroy_obj_sprite_and_texture(get_at(st->bars, i * 2));
            st->bars = free_at(st->bars, i * 2);
            destroy_obj_sprite_and_texture(get_at(st->bars, i * 2));
            st->bars = free_at(st->bars, i * 2);
            i--;
            len--;
            st->golds += 10;
            st->knights_killed += 1;
            sfSound_play(st->audio.die);
        }
    }
}