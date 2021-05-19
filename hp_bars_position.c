/*
** EPITECH PROJECT, 2021
** hp bars position
** File description:
** define the position of the hp bar of the knights
*/

#include "include/my.h"

void move_hp_bar(struct game_object *green, struct game_object *red,
storage_t *st, struct game_object knight)
{
    switch (knight.move) {
        case RIGHT: green->pos.x += knight.speed * st->deltaseconds;
            red->pos.x += knight.speed * st->deltaseconds;
            break;
        case UP: green->pos.y -= knight.speed * st->deltaseconds;
            red->pos.y -= knight.speed * st->deltaseconds;
            break;
        case LEFT: green->pos.x -= knight.speed * st->deltaseconds;
            red->pos.x -= knight.speed * st->deltaseconds;
            break;
        case DOWN: green->pos.y += knight.speed * st->deltaseconds;
            red->pos.y += knight.speed * st->deltaseconds;
            break;
        default: break;
    }
}

void hp_bars_position(storage_t *st, int i, struct game_object knight)
{
    struct game_object green = get_at(st->bars, i * 2);
    struct game_object red = get_at(st->bars, i * 2 + 1);

    move_hp_bar(&green, &red, st, knight);
    if (green.pos.x >= 1670) {
        green.pos.x = 1670;
        red.pos.x = 1670;
    }
    sfSprite_setPosition(green.sprite, green.pos);
    sfSprite_setPosition(red.sprite, red.pos);
    set_at(st->bars, green, i * 2);
    set_at(st->bars, red, i * 2 + 1);
}