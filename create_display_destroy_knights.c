/*
** EPITECH PROJECT, 2021
** create display destroy knights
** File description:
** create a knight depending on clock, display, destroy if dead
*/

#include "include/my.h"

int define_density(storage_t *st)
{
    int density = 0;

    if (st->knights_killed % 50 == 0 && st->knights_killed != 0 &&
        st->fiftykills == sfFalse) {
        st->golds += 1000;
        st->fiftykills = sfTrue;
    }
    else if (st->knights_killed % 50 != 0) st->fiftykills = sfFalse;
    if (st->knights_killed % 500 == 0 && st->knights_killed != 0 &&
        st->fivehundredskills == sfFalse) {
        st->golds += 10000;
        st->fivehundredskills = sfTrue;
    }
    else if (st->knights_killed % 500 != 0) st->fivehundredskills = sfFalse;
    if (st->knights_killed <= 50)
        density = 10;
    else if (st->knights_killed > 30 && st->knights_killed <= 200)
        density = 7;
    else
        density = 5;
    return (density);
}

int define_create(storage_t *st)
{
    int create = 0;
    int density = define_density(st);

    switch (rand() % density + 1) {
        case 1: create = 1;
            break;
        case 2: create = 2;
            break;
        case 3: create = 3;
            break;
        case 4: create = 4;
            break;
        default: sfClock_restart(st->clocks.createclock);
            return (0);
    }
    return (create);
}

int does_create_knight(storage_t *st)
{
    sfTime time = sfClock_getElapsedTime(st->clocks.timeclock);
    unsigned int seconds = time.microseconds / 1000000;
    srand(seconds);
    int create = 0;
    int density = 0;

    if (seconds_clock(st->clocks.createclock) > 1) {
        if (seconds_clock(st->clocks.timeclock) < 2)
            return (1);
        return (define_create(st));
    }
    return (0);
}

void create_display_destroy_knights(sfRenderWindow *window,
status_t *status, storage_t *st)
{
    int len = 0;
    int create = 0;

    if ((create = does_create_knight(st)) && status->play == ALIVE &&
        st->echap == sfFalse) {
        create_a_knight(st, create);
        create_hp_bar(st);
        sfClock_restart(st->clocks.createclock);
    }
    len = len_list(st->knights);
    for (int i = 0; i < len; i++) {
        if (status->play == ALIVE && st->echap == sfFalse)
            move_knight(status, st, i);
    }
    destroy_knight_if_0_hp(st);
}