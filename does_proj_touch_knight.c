/*
** EPITECH PROJECT, 2021
** does proj touch knight
** File description:
** return 1 if the proj touches the knight. 0 if not
*/

#include "include/my.h"

int does_proj_touch_knight(struct game_object knight, struct game_object proj)
{
    proj.pos.x += proj.rect.width / 2;
    proj.pos.y += proj.rect.height / 2;
    if (proj.pos.x >= knight.pos.x - 22.8 &&
        proj.pos.x <= knight.pos.x + 22.8 &&
        proj.pos.y >= knight.pos.y - 32 &&
        proj.pos.y <= knight.pos.y + 32) {
        return (1);
    }
    return (0);
}