/*
** EPITECH PROJECT, 2021
** seconds_clock
** File description:
** return in seconds the time elapsed of a clock
*/

#include "include/my.h"

float seconds_clock(sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;

    return (seconds);
}