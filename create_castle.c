/*
** EPITECH PROJECT, 2021
** create_castle
** File description:
** create the sprites of the castle / hp bar
*/

#include "include/my.h"

void create_castle(storage_t *st)
{
    st->play = add_at(st->play, create_object("./images/castle.png",
    vectorf(1690, 355), rect(0, 0, 156, 206), vectorf(1, 1)), CASTLE);
    st->play = add_at(st->play, create_object("./images/castle destr.png",
    vectorf(1690, 355), rect(0, 0, 156, 206), vectorf(1, 1)), CASTLE_DESTR);
    st->play = add_at(st->play, create_object("./images/fire.png",
    vectorf(1660, 355), rect(0, 0, 200, 200), vectorf(1, 1)), FIRE);
    st->play = add_at(st->play, create_object("./images/bar.png",
    vectorf(1700, 345), rect(0, 0, 200, 5), vectorf(0.72, 1)), BAR);
    st->play = add_at(st->play, create_object("./images/hp.png",
    vectorf(1700, 345), rect(0, 0, 200, 5), vectorf(0.72, 1)), HP);
}