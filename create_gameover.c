/*
** EPITECH PROJECT, 2021
** create_gameover
** File description:
** create the sprites for try again, menu and quit when gameover
*/

#include "include/my.h"

void create_gameover(storage_t *st)
{
    st->play = add_at(st->play, create_object("./images/TRY AGAIN empty.png",
    vectorf(677, 450), rect(0, 0, 945, 150), vectorf(0.6, 0.6)), TRYAG_EMPTY);
    st->play = add_at(st->play, create_object("./images/TRY AGAIN filled.png",
    vectorf(677, 450), rect(0, 0, 945, 150), vectorf(0.6, 0.6)), TRYAG_FILLED);
    st->play = add_at(st->play, create_object("./images/TRY AGAIN filled.png",
    vectorf(705, 454), rect(0, 0, 945, 150), vectorf(0.54, 0.54)), TRYAG_PR);
    st->play = add_at(st->play, create_object("./images/MENU empty.png",
    vectorf(824, 590), rect(0, 0, 420, 150), vectorf(0.7, 0.7)), MENU2_EMPTY);
    st->play = add_at(st->play, create_object("./images/MENU filled.png",
    vectorf(824, 590), rect(0, 0, 420, 150), vectorf(0.7, 0.7)), MENU2_FILLED);
    st->play = add_at(st->play, create_object("./images/MENU filled.png",
    vectorf(839, 595), rect(0, 0, 420, 150), vectorf(0.63, 0.63)), MENU2_PR);
    st->play = add_at(st->play, create_object("./images/QUIT empty.png",
    vectorf(844, 740), rect(0, 0, 420, 150), vectorf(0.6, 0.6)), QUIT3_EMPTY);
    st->play = add_at(st->play, create_object("./images/QUIT filled.png",
    vectorf(844, 740), rect(0, 0, 420, 150), vectorf(0.6, 0.6)), QUIT3_FILLED);
    st->play = add_at(st->play, create_object("./images/QUIT filled.png",
    vectorf(856, 744), rect(0, 0, 420, 150), vectorf(0.54, 0.54)), QUIT3_PR);
}