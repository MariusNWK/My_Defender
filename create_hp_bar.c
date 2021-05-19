/*
** EPITECH PROJECT, 2021
** create_hp_bar
** File description:
** create sprites of red hp bar and green hp bar
*/

#include "include/my.h"

void create_hp_bar(storage_t *st)
{
    int len = len_list(st->bars);

    st->bars = add_at(st->bars, create_object("./images/red bar.png",
    vectorf(28, 860), rect(0, 0, 40, 5), vectorf(1, 1)), len);
    st->bars = add_at(st->bars, create_object("./images/green bar.png",
    vectorf(28, 860), rect(0, 0, 40, 5), vectorf(1, 1)), len + 1);
}