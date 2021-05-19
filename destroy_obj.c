/*
** EPITECH PROJECT, 2021
** destroy obj
** File description:
** destroy the struct game objects
*/

#include "include/my.h"

void destroy_obj_sprite_and_texture(struct game_object obj)
{
    sfTexture_destroy(obj.texture);
    sfSprite_destroy(obj.sprite);
}

void destroy_obj_sprite_and_texture_and_clock(struct game_object obj)
{
    sfTexture_destroy(obj.texture);
    sfSprite_destroy(obj.sprite);
    sfClock_destroy(obj.clock);
    sfClock_destroy(obj.slow_clock);
}