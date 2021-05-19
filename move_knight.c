/*
** EPITECH PROJECT, 2021
** move_knight
** File description:
** handle the positions of the knights and their animations
*/

#include "include/my.h"

int is_pos_delimit(sfVector2i pos, limits_t lim)
{
    if (pos.x >= lim.lim_x && pos.x <= lim.lim_x + lim.offset_x &&
        pos.y >= lim.lim_y && pos.y <= lim.lim_y + lim.offset_y) {
        return (1);
    }
    return (0);
}

void direction_handling(sfVector2i pos, struct game_object *knight)
{
    if (is_pos_delimit(pos, set_lim(100, 100, 328, 870)) ||
        is_pos_delimit(pos, set_lim(100, 100, 1028, 870)) ||
        is_pos_delimit(pos, set_lim(100, 100, 1428, 570)))
        knight->move = UP;
    if (is_pos_delimit(pos, set_lim(100, 70, 328, 0)) ||
        is_pos_delimit(pos, set_lim(100, 100, 928, 270)) ||
        is_pos_delimit(pos, set_lim(100, 100, 528, 870)) ||
        is_pos_delimit(pos, set_lim(100, 100, 1028, 570)) ||
        is_pos_delimit(pos, set_lim(100, 100, 1428, 370)))
        knight->move = RIGHT;
    if (is_pos_delimit(pos, set_lim(100, 70, 928, 0)) ||
        is_pos_delimit(pos, set_lim(100, 100, 1228, 270)) ||
        is_pos_delimit(pos, set_lim(100, 100, 528, 470)))
        knight->move = DOWN;
    if (is_pos_delimit(pos, set_lim(100, 100, 1228, 470)))
        knight->move = LEFT;
    if (pos.x >= 1670) {
        knight->move = STOP;
        knight->pos.x = 1670;
    }
}

void position_handling(struct game_object knight,
storage_t *st, status_t *status, int i)
{
    sfVector2i pos;

    switch (knight.move) {
        case RIGHT: knight.pos.x += knight.speed * st->deltaseconds;
            break;
        case UP: knight.pos.y -= knight.speed * st->deltaseconds;
            break;
        case LEFT: knight.pos.x -= knight.speed * st->deltaseconds;
            break;
        case DOWN: knight.pos.y += knight.speed * st->deltaseconds;
            break;
        default: knight.leftrect = FROM_RIGHT;
            set_at(st->knights, knight, i);
            animate_knight(status, st, i, 1);
            return;
    }
    pos = vectori(knight.pos.x + 0.5, knight.pos.y + 0.5);
    direction_handling(pos, &knight);
    sfSprite_setPosition(knight.sprite, knight.pos);
    set_at(st->knights, knight, i);
    animate_knight(status, st, i, 0.2);
}

void move_knight(status_t *status, storage_t *st, int i)
{
    struct game_object knight = get_at(st->knights, i);

    position_handling(knight, st, status, i);
    hp_bars_position(st, i, knight);
}