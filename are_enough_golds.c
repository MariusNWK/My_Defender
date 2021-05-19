/*
** EPITECH PROJECT, 2021
** are enough golds
** File description:
** return 1 if the player has enough golds to buy/upgrade a tower, 0 if not
*/

#include "include/my.h"

int are_enough_golds_to_buy(storage_t *st, status_t *status)
{
    if (status->hold == HOLDING_STONE && st->golds >= 100)
        return (1);
    if (status->hold == HOLDING_POISON && st->golds >= 200)
        return (1);
    if (status->hold == HOLDING_WIZARD && st->golds >= 500)
        return (1);
    if (status->hold == HOLDING_TESLA && st->golds >= 1000)
        return (1);
    if (status->hold == HOLDING_MAGNUS && st->golds >= 2000)
        return (1);
    st->display_notenoughmoney = sfTrue;
    sfClock_restart(st->clocks.notenoughmoneyclock);
    return (0);
}

int are_enough_golds_to_upgrade(storage_t *st, int i)
{
    unsigned int num = which_tower_it_is(get_at(st->cases, i));

    if (num == S1 && st->golds >= 500)
        return (1);
    if ((num == S2 || num == P1) && st->golds >= 1000)
        return (1);
    if (num == P2 && st->golds >= 2000)
        return (1);
    if (num == W1 && st->golds >= 2500)
        return (1);
    if ((num == W2 || num == T1) && st->golds >= 5000)
        return (1);
    if (num == T2 && st->golds >= 10000)
        return (1);
    if (num == S1 || num == S2 || num == P1 || num == P2 ||
        num == W1 || num == W2 || num == T1 || num == T2) {
        st->display_notenoughmoney = sfTrue;
        sfClock_restart(st->clocks.notenoughmoneyclock);
    }
    return (0);
}