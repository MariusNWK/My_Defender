/*
** EPITECH PROJECT, 2021
** destroy list sprites and textures and clock
** File description:
** destroy textures/sprites/clock of a game object
*/

#include "include/my.h"

void destroy_list_sprites_and_textures_and_clock(list_t *list)
{
    int len = len_list(list);
    struct game_object obj;

    for (int i = 0; i < len; i++) {
        obj = get_at(list, i);
        sfSprite_destroy(obj.sprite);
        sfTexture_destroy(obj.texture);
        sfClock_destroy(obj.clock);
        sfClock_destroy(obj.slow_clock);
    }
    free_list(list);
}