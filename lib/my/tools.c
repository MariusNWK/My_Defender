/*
** EPITECH PROJECT, 2021
** tools
** File description:
** function to define sfVector2f, sfIntRect & cie...
*/

#include "../../include/my.h"

sfVector2f vectorf(float x, float y)
{
    sfVector2f vector = {x, y};

    return (vector);
}

sfVector2i vectori(int x, int y)
{
    sfVector2i vector = {x, y};

    return (vector);
}

sfIntRect rect(int left, int top, int width, int height)
{
    sfIntRect rect = {left, top, width, height};

    return (rect);
}

limits_t set_lim(float offset_x, float offset_y, float lim_x, float lim_y)
{
    limits_t lim = {offset_x, offset_y, lim_x, lim_y};

    return (lim);
}

int is_same_rect(sfIntRect rect1, sfIntRect rect2)
{
    if (rect1.left == rect2.left && rect1.top == rect2.top &&
        rect1.width == rect2.width && rect1.height == rect2.height) {
        return (1);
    }
    return (0);
}