/*
** EPITECH PROJECT, 2021
** create a knight
** File description:
** create a knight
*/

#include "include/my.h"

struct game_object set_move_rect_clock_hp_speed_poison(storage_t *st,
int len, int hp)
{
    struct game_object knight = get_at(st->knights, len);

    knight.move = RIGHT;
    knight.leftrect = FROM_LEFT;
    knight.clock = sfClock_create();
    knight.slow_clock = sfClock_create();
    knight.hp = hp;
    knight.speed = 100;
    knight.poison = 0;
    return (knight);
}

void create_a_knight(storage_t *st, int create)
{
    int len = len_list(st->knights);
    struct game_object knight;
    int left = 0;
    int hp = 100 + st->knights_killed;

    switch (create) {
        case 2: left = 234;
            break;
        case 3: left = 468;
            hp = 200 + st->knights_killed * 2;
            break;
        case 4: left = 702;
            hp = 200 + st->knights_killed * 2;
            break;
        default: break;
    }
    st->knights = add_at(st->knights, create_object("./images/knights.png",
    vectorf(28, 870), rect(left, 0, 57, 90), vectorf(0.8, 0.8)), len);
    knight = set_move_rect_clock_hp_speed_poison(st, len, hp);
    set_at(st->knights, knight, len);
}