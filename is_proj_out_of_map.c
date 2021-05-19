/*
** EPITECH PROJECT, 2021
** is proj out of map
** File description:
** return 1 if the projectile is out of the map. Else return 0
*/

#include "include/my.h"

int is_proj_out_of_map(struct game_object proj)
{
    proj.pos.x += proj.rect.width / 2;
    proj.pos.y += proj.rect.height / 2;
    if (proj.pos.x < 0 ||
        proj.pos.x > 1920 ||
        proj.pos.y < 0 ||
        proj.pos.y > 1080) {
        return (1);
    }
    return (0);
}