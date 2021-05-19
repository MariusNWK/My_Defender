/*
** EPITECH PROJECT, 2021
** reset proj
** File description:
** reset the projectile
*/

#include "include/my.h"

struct game_object reset_proj(struct game_object proj,
struct game_object a_case)
{
    proj.traj.x = 0;
    proj.traj.y = 0;
    proj.pos.x = a_case.pos.x + 35;
    proj.pos.y = a_case.pos.y + 35;
    sfSprite_setPosition(proj.sprite, proj.pos);
    proj.launched = sfFalse;
    return (proj);
}