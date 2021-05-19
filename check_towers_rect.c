/*
** EPITECH PROJECT, 2021
** check_towers_rect
** File description:
** find the tower value and define his rect
*/

#include "include/my.h"

void check_towers1_rect(sfIntRect *tower_rect, unsigned int num)
{
    switch (num) {
        case S1: *tower_rect = rect(0, 60, 140, 180);
            break;
        case P1: *tower_rect = rect(20, 70, 160, 190);
            break;
        case W1: *tower_rect = rect(45, 100, 135, 200);
            break;
        case T1: *tower_rect = rect(50, 90, 120, 210);
            break;
        case M1: *tower_rect = rect(0, 10, 155, 260);
            break;
        default: break;
    }
}

void check_towers2_rect(sfIntRect *tower_rect, unsigned int num)
{
    switch (num) {
        case S2: *tower_rect = rect(163, 11, 145, 220);
            break;
        case P2: *tower_rect = rect(224, 59, 151, 197);
            break;
        case W2: *tower_rect = rect(237, 84, 137, 217);
            break;
        case T2: *tower_rect = rect(190, 49, 133, 243);
            break;
        default: break;
    }
}

void check_towers3_rect(sfIntRect *tower_rect, unsigned int num)
{
    switch (num) {
        case S3: *tower_rect = rect(340, 4, 151, 235);
            break;
        case P3: *tower_rect = rect(406, 36, 161, 222);
            break;
        case W3: *tower_rect = rect(428, 14, 148, 297);
            break;
        case T3: *tower_rect = rect(345, 27, 127, 270);
            break;
        default: break;
    }
}