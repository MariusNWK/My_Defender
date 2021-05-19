/*
** EPITECH PROJECT, 2021
** create_echap
** File description:
** create the sprites RESUME MENU QUIT (to display when Escape is pressed)
*/

#include "include/my.h"

void create_echap(storage_t *st)
{
    st->play = add_at(st->play, create_object("./images/RESUME empty.png",
    vectorf(800, 408), rect(0, 0, 630, 150), vectorf(0.6, 0.6)), RESUME_EMPTY);
    st->play = add_at(st->play, create_object("./images/RESUME filled.png",
    vectorf(800, 408), rect(0, 0, 630, 150), vectorf(0.6, 0.6)), RESUME_FILLED);
    st->play = add_at(st->play, create_object("./images/RESUME filled.png",
    vectorf(816, 412), rect(0, 0, 630, 150), vectorf(0.54, 0.54)), RESUME_PR);
    st->play = add_at(st->play, create_object("./images/MENU empty.png",
    vectorf(854, 537), rect(0, 0, 420, 150), vectorf(0.65, 0.65)), MENU_EMPTY);
    st->play = add_at(st->play, create_object("./images/MENU filled.png",
    vectorf(854, 537), rect(0, 0, 420, 150), vectorf(0.65, 0.65)), MENU_FILLED);
    st->play = add_at(st->play, create_object("./images/MENU filled.png",
    vectorf(867, 542), rect(0, 0, 420, 150), vectorf(0.585, 0.585)), MENU_PR);
    st->play = add_at(st->play, create_object("./images/QUIT empty.png",
    vectorf(864, 672), rect(0, 0, 420, 150), vectorf(0.6, 0.6)), QUIT2_EMPTY);
    st->play = add_at(st->play, create_object("./images/QUIT filled.png",
    vectorf(864, 672), rect(0, 0, 420, 150), vectorf(0.6, 0.6)), QUIT2_FILLED);
    st->play = add_at(st->play, create_object("./images/QUIT filled.png",
    vectorf(876, 676), rect(0, 0, 420, 150), vectorf(0.54, 0.54)), QUIT2_PR);
    st->play = add_at(st->play, create_object("./images/smoke.png",
    vectorf(0, 0), rect(0, 0, 1288, 602), vectorf(1.5, 1.8)), SMOKE);
}