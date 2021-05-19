/*
** EPITECH PROJECT, 2021
** apply effects
** File description:
** apply the penalty to a knight depending on the tower
*/

#include "include/my.h"

struct game_object set_penalties(int damages, int poison, int speed,
struct game_object knight)
{
    knight.poison += poison;
    knight.hp -= damages + knight.poison;
    if (speed != 0) {
        knight.speed = speed;
        sfClock_restart(knight.slow_clock);
    }
    knight.pos = redef_pos(knight.pos, -22.8, -32);
    return (knight);
}

struct game_object apply_effects(struct game_object knight,
struct game_object a_case)
{
    int tower = which_tower_it_is(a_case);

    switch (tower) {
        case S1: return (set_penalties(5, 0, 0, knight));
        case S2: return (set_penalties(10, 0, 0, knight));
        case S3: return (set_penalties(20, 0, 0, knight));
        case P1: return (set_penalties(0, 1, 0, knight));
        case P2: return (set_penalties(0, 2, 0, knight));
        case P3: return (set_penalties(0, 4, 0, knight));
        case W1: return (set_penalties(1, 0, 50, knight));
        case W2: return (set_penalties(2, 0, 50, knight));
        case W3: return (set_penalties(2, 0, 25, knight));
        case T1: return (set_penalties(5, 0, 0, knight));
        case T2: return (set_penalties(10, 0, 0, knight));
        case T3: return (set_penalties(20, 0, 0, knight));
        case M1: knight.hp = 0;
            return (knight);
        default: return (knight);
    }
    return (knight);
}