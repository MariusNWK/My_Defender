/*
** EPITECH PROJECT, 2021
** redef pos case
** File description:
** redefine the initial pose of the case where the tower is
*/

#include "include/my.h"

sfVector2f redef_pos(sfVector2f pos, float offset_x, float offset_y)
{
    pos.x += offset_x;
    pos.y += offset_y;
    return (pos);
}

sfVector2f redef_pos_case(sfVector2f pos, int tower)
{
    switch (tower) {
        case S1: return (redef_pos(pos, -5, 15));
        case S2: return (redef_pos(pos, 0, 41));
        case S3: return (redef_pos(pos, 0, 53));
        case P1: return (redef_pos(pos, -5, 10));
        case P2: return (redef_pos(pos, 0, 30));
        case P3: return (redef_pos(pos, 2, 44));
        case W1: return (redef_pos(pos, -8, 30));
        case W2: return (redef_pos(pos, -8, 35));
        case W3: return (redef_pos(pos, -3, 80));
        case T1: return (redef_pos(pos, -13, 30));
        case T2: return (redef_pos(pos, -8, 52));
        case T3: return (redef_pos(pos, -13, 67));
        case M1: return (redef_pos(pos, -12, 35));
        default: return (pos);
    }
    return (pos);
}