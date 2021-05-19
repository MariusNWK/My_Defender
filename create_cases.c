/*
** EPITECH PROJECT, 2021
** create_cases
** File description:
** create the sprites of the cases (cases when player can place buildings)
*/

#include "include/my.h"

case_t define_new_cases(int init, int final, float offset_x, float offset_y)
{
    case_t new = {init, final, offset_x, offset_y};

    return (new);
}

void add_case(storage_t *st, sfVector2f pos, int num)
{
    st->cases = add_at(st->cases, create_object("./images/case.png",
    pos, rect(0, 0, 100, 100), vectorf(1, 1)), num);
}

void delimit_new_coords(int i, case_t new, sfVector2f *coords)
{
    if (i >= new.initial && i <= new.final) {
        coords->x += new.offset_x;
        coords->y += new.offset_y;
    }
}

void define_coords_cases(int i, sfVector2f *coords)
{
    delimit_new_coords(i, define_new_cases(2, 8, 0, 100), coords);
    delimit_new_coords(i, define_new_cases(9, 9, 100, -700), coords);
    delimit_new_coords(i, define_new_cases(10, 12, 100, 0), coords);
    delimit_new_coords(i, define_new_cases(13, 14, 0, 100), coords);
    delimit_new_coords(i, define_new_cases(15, 17, 100, 0), coords);
    delimit_new_coords(i, define_new_cases(18, 18, -400, 0), coords);
    delimit_new_coords(i, define_new_cases(19, 20, -100, 0), coords);
    delimit_new_coords(i, define_new_cases(21, 25, 0, 100), coords);
    delimit_new_coords(i, define_new_cases(26, 26, 1000, -500), coords);
    delimit_new_coords(i, define_new_cases(27, 28, -100, 0), coords);
    delimit_new_coords(i, define_new_cases(29, 30, 0, 100), coords);
    delimit_new_coords(i, define_new_cases(31, 36, -100, 0), coords);
    delimit_new_coords(i, define_new_cases(37, 38, 0, 100), coords);
    delimit_new_coords(i, define_new_cases(39, 39, 100, 0), coords);
    delimit_new_coords(i, define_new_cases(40, 40, 100, -100), coords);
    delimit_new_coords(i, define_new_cases(41, 41, 0, 100), coords);
    delimit_new_coords(i, define_new_cases(42, 42, 600, -200), coords);
    delimit_new_coords(i, define_new_cases(43, 43, 0, 100), coords);
    delimit_new_coords(i, define_new_cases(44, 44, -200, 100), coords);
    delimit_new_coords(i, define_new_cases(45, 46, -100, 0), coords);
}

void create_cases(storage_t *st)
{
    unsigned int cases_nbr = 46;
    sfVector2f coords = {400, 180};

    st->cases = NULL;
    for (int i = 1; i <= cases_nbr; i++) {
        define_coords_cases(i, &coords);
        add_case(st, coords, (i - 1) * 2);
        coords.y -= 5;
        add_case(st, coords, (i - 1) * 2 + 1);
        coords.y += 5;
    }
}