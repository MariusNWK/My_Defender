/*
** EPITECH PROJECT, 2021
** is_knight_in_range
** File description:
** check if the knight is in the range of the tower
*/

#include "include/my.h"

int is_pos_in_square(sfVector2f kn_pos, sfVector2f case_pos, float range)
{
    if (kn_pos.x >= case_pos.x - range &&
        kn_pos.x <= case_pos.x + 100 + range &&
        kn_pos.y >= case_pos.y - range &&
        kn_pos.y <= case_pos.y + 100 + range) {
        return (1);
    }
    return (0);
}

int is_knight_in_range(struct game_object knight, struct game_object a_case)
{
    int tower = which_tower_it_is(a_case);

    switch (tower)
    {
        case S1: return (is_pos_in_square(knight.pos, a_case.pos, 100));
        case S2: return (is_pos_in_square(knight.pos, a_case.pos, 100));
        case S3: return (is_pos_in_square(knight.pos, a_case.pos, 100));
        case P1: return (is_pos_in_square(knight.pos, a_case.pos, 100));
        case P2: return (is_pos_in_square(knight.pos, a_case.pos, 100));
        case P3: return (is_pos_in_square(knight.pos, a_case.pos, 100));
        case W1: return (is_pos_in_square(knight.pos, a_case.pos, 100));
        case W2: return (is_pos_in_square(knight.pos, a_case.pos, 100));
        case W3: return (is_pos_in_square(knight.pos, a_case.pos, 100));
        case T1: return (is_pos_in_square(knight.pos, a_case.pos, 100));
        case T2: return (is_pos_in_square(knight.pos, a_case.pos, 150));
        case T3: return (is_pos_in_square(knight.pos, a_case.pos, 200));
        case M1: return (is_pos_in_square(knight.pos, a_case.pos, 100));
        default: return (0);
    }
    return (0);
}