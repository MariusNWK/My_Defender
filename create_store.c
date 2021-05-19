/*
** EPITECH PROJECT, 2021
** create shop
** File description:
** create all sprites of the shop
*/

#include "include/my.h"

void create_store_two(storage_t *st)
{
    st->play = add_at(st->play, create_object("./images/MAGNUS white.png",
    vectorf(0, 720), rect(0, 0, 160, 180), vectorf(1, 1)), MAGNUS_WHITE);
    st->play = add_at(st->play, create_object("./images/gold bag.png",
    vectorf(0, 900), rect(0, 0, 160, 180), vectorf(1, 1)), GOLD_BAG);
}

void create_store(storage_t *st)
{
    st->play = add_at(st->play, create_object("./images/STONE grey.png",
    vectorf(0, 0), rect(0, 0, 160, 180), vectorf(1, 1)), STONE_GREY);
    st->play = add_at(st->play, create_object("./images/STONE white.png",
    vectorf(0, 0), rect(0, 0, 160, 180), vectorf(1, 1)), STONE_WHITE);
    st->play = add_at(st->play, create_object("./images/POISON grey.png",
    vectorf(0, 180), rect(0, 0, 160, 180), vectorf(1, 1)), POISON_GREY);
    st->play = add_at(st->play, create_object("./images/POISON white.png",
    vectorf(0, 180), rect(0, 0, 160, 180), vectorf(1, 1)), POISON_WHITE);
    st->play = add_at(st->play, create_object("./images/WIZARD grey.png",
    vectorf(0, 360), rect(0, 0, 160, 180), vectorf(1, 1)), WIZARD_GREY);
    st->play = add_at(st->play, create_object("./images/WIZARD white.png",
    vectorf(0, 360), rect(0, 0, 160, 180), vectorf(1, 1)), WIZARD_WHITE);
    st->play = add_at(st->play, create_object("./images/TESLA grey.png",
    vectorf(0, 540), rect(0, 0, 160, 180), vectorf(1, 1)), TESLA_GREY);
    st->play = add_at(st->play, create_object("./images/TESLA white.png",
    vectorf(0, 540), rect(0, 0, 160, 180), vectorf(1, 1)), TESLA_WHITE);
    st->play = add_at(st->play, create_object("./images/MAGNUS grey.png",
    vectorf(0, 720), rect(0, 0, 160, 180), vectorf(1, 1)), MAGNUS_GREY);
    st->play = add_at(st->play, create_object("./images/MAGNUS white.png",
    vectorf(0, 720), rect(0, 0, 160, 180), vectorf(1, 1)), MAGNUS_WHITE);
    create_store_two(st);
}