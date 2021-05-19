/*
** EPITECH PROJECT, 2021
** set fps
** File description:
** set the fps defined by status
*/

#include "include/my.h"

int set_fps(status_t *status)
{
    int fps = 0;

    switch (status->fps) {
        case THIRTY: fps = 30;
            break;
        case SIXTY: fps = 60;
            break;
        case HUNDREDFF: fps = 144;
            break;
        default: break;
    }
    return (fps);
}