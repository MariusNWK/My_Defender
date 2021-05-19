/*
** EPITECH PROJECT, 2021
** select_tower
** File description:
** define a struct game_object depending on the enum hold of the towers
*/

#include "include/my.h"

sfVector2f new_pos(sfVector2f pos_case, float offset_x, float offset_y)
{
    sfVector2f pos_sprite = {pos_case.x + offset_x, pos_case.y + offset_y};

    return (pos_sprite);
}

struct game_object select_tower1(status_t *status, storage_t *st,
int i, sfVector2f ref)
{
    struct game_object t1;

    switch(status->hold) {
        case HOLDING_STONE: t1 = create_object("./images/STONE tower.png",
        new_pos(ref, 5, -15), rect(0, 60, 140, 180), vectorf(0.65, 0.65));
        break;
        case HOLDING_POISON: t1 = create_object("./images/POISON tower.png",
        new_pos(ref, 5, -10), rect(20, 70, 160, 190), vectorf(0.55, 0.55));
        break;
        case HOLDING_WIZARD: t1 = create_object("./images/WIZARD tower.png",
        new_pos(ref, 8, -30), rect(45, 100, 135, 200), vectorf(0.6, 0.6));
        break;
        case HOLDING_TESLA: t1 = create_object("./images/TESLA tower.png",
        new_pos(ref, 13, -30), rect(50, 90, 120, 210), vectorf(0.6, 0.6));
        break;
        case HOLDING_MAGNUS: t1 = create_object("./images/MAGNUS tower.png",
        new_pos(ref, 12, -35), rect(0, 10, 155, 260), vectorf(0.5, 0.5));
        break;
        default: break;
    }
    return (t1);
}

struct game_object select_tower2(status_t *status, storage_t *st,
int i, sfVector2f ref)
{
    struct game_object t2;

    switch(status->hold) {
        case HOLDING_STONE: t2 = create_object("./images/STONE tower in.png",
        new_pos(ref, 5, -15), rect(0, 60, 140, 180), vectorf(0.66, 0.66));
        break;
        case HOLDING_POISON: t2 = create_object("./images/POISON tower in.png",
        new_pos(ref, 5, -10), rect(20, 70, 160, 190), vectorf(0.56, 0.56));
        break;
        case HOLDING_WIZARD: t2 = create_object("./images/WIZARD tower in.png",
        new_pos(ref, 8, -30), rect(45, 100, 135, 200), vectorf(0.61, 0.61));
        break;
        case HOLDING_TESLA: t2 = create_object("./images/TESLA tower in.png",
        new_pos(ref, 13, -30), rect(50, 90, 120, 210), vectorf(0.61, 0.61));
        break;
        case HOLDING_MAGNUS: t2 = create_object("./images/MAGNUS tower in.png",
        new_pos(ref, 12, -35), rect(0, 10, 155, 260), vectorf(0.51, 0.51));
        break;
        default: break;
    }
    return (t2);
}