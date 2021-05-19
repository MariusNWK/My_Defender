/*
** EPITECH PROJECT, 2021
** animate knights
** File description:
** animate the knights depending of status->move
*/

#include "include/my.h"

struct game_object define_top_rect(storage_t *st, int i)
{
    struct game_object knight = get_at(st->knights, i);

    switch (knight.move) {
        case RIGHT: knight.rect.top = 216;
            break;
        case UP: knight.rect.top = 324;
            break;
        case LEFT: knight.rect.top = 108;
            break;
        case DOWN: knight.rect.top = 0;
            break;
        default: break;
    }
    return (knight);
}

struct game_object define_left_rect(status_t *status, struct game_object knight)
{
    switch (knight.leftrect) {
        case FROM_LEFT: knight.rect.left += 78;
            break;
        case FROM_RIGHT: knight.rect.left -= 78;
            break;
        default: break;
    }
    return (knight);
}

struct game_object identitfy_cur_rect(struct game_object knight,
storage_t *st, status_t *status, float speed)
{
    int left = knight.rect.left;

    if (left == 0 || left == 234 || left == 468 || left == 702) {
        knight.rect.left += 78;
        knight.leftrect = FROM_LEFT;
    }
    else if (left == 78 || left == 312 || left == 546 || left == 780) {
        knight = define_left_rect(status, knight);
        if (speed == 1)
            st->hp -= 5;
    }
    else {
        knight.rect.left -= 78;
        knight.leftrect = FROM_RIGHT;
    }
    return (knight);
}

void animate_knight(status_t *status, storage_t *st, int i, float speed)
{
    struct game_object knight = define_top_rect(st, i);
    float seconds = seconds_clock(knight.clock);

    while (seconds > speed && status->play == ALIVE) {
        knight = identitfy_cur_rect(knight, st, status, speed);
        seconds -= speed;
        sfClock_restart(knight.clock);
    }
    sfSprite_setTextureRect(knight.sprite, knight.rect);
    set_at(st->knights, knight, i);
}