/*
** EPITECH PROJECT, 2021
** upgrade_tower
** File description:
** upgrade the tower pressed by the player, or don't if can't upgrade
*/

#include "include/my.h"

void pay_tower_upgrade(storage_t *st, int num)
{
    unsigned int prec_golds = st->golds;

    if (num == S1)
        st->golds -= 500;
    if (num == S2 || num == P1)
        st->golds -= 1000;
    if (num == P2)
        st->golds -= 2000;
    if (num == W1)
        st->golds -= 2500;
    if (num == W2 || num == T1)
        st->golds -= 5000;
    if (num == T2)
        st->golds -= 10000;
    st->lost_golds = prec_golds - st->golds;
    sfClock_restart(st->clocks.lostgoldsclock);
}

void upgrade_towers1(struct game_object *t1, int num)
{
    switch (num) {
        case S1: t1->rect = rect(163, 11, 145, 220);
            t1->pos = vectorf(t1->pos.x - 5, t1->pos.y - 26);
            break;
        case P1: t1->rect = rect(224, 59, 151, 197);
            t1->scale = vectorf(t1->scale.x + 0.1, t1->scale.y + 0.1);
            t1->pos = vectorf(t1->pos.x - 5, t1->pos.y - 20);
            break;
        case W1: t1->rect = rect(237, 84, 137, 217);
            t1->pos = vectorf(t1->pos.x, t1->pos.y - 5);
            break;
        case T1: t1->rect = rect(190, 49, 133, 243);
            t1->pos = vectorf(t1->pos.x - 5, t1->pos.y - 22);
            break;
        case M1: break;
        default: break;
    }
}

void upgrade_towers2(struct game_object *t1, int num)
{
    switch (num) {
        case S2: t1->rect = rect(340, 4, 151, 235);
            t1->pos = vectorf(t1->pos.x, t1->pos.y - 12);
            break;
        case P2: t1->rect = rect(406, 36, 161, 222);
            t1->pos = vectorf(t1->pos.x - 2, t1->pos.y - 14);
            break;
        case W2: t1->rect = rect(428, 14, 148, 297);
            t1->pos = vectorf(t1->pos.x - 5, t1->pos.y - 45);
            break;
        case T2: t1->rect = rect(345, 27, 127, 270);
            t1->pos = vectorf(t1->pos.x + 5, t1->pos.y - 15);
            break;
        default: break;
    }
}

void upgrade_tower(storage_t *st, int i)
{
    struct game_object t1 = get_at(st->cases, i);
    struct game_object t2 = get_at(st->cases, i + 1);
    int num = which_tower_it_is(t1);

    if (num == -1)
        return;
    upgrade_towers1(&t1, num);
    upgrade_towers2(&t1, num);
    t2.rect = t1.rect;
    t2.pos = t1.pos;
    t2.scale = vectorf(t1.scale.x + 0.01, t1.scale.y + 0.01);
    apply_settings(&t1);
    apply_settings(&t2);
    set_at(st->cases, t1, i);
    set_at(st->cases, t2, i + 1);
    pay_tower_upgrade(st, num);
}