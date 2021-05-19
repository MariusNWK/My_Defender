/*
** EPITECH PROJECT, 2021
** which tower it is
** File description:
** find which tower corresponds to the rect of the game_object
*/

#include "include/my.h"

sfIntRect save_tower_rect(unsigned int num)
{
    sfIntRect tower_rect = {0, 0, 0, 0};

    check_towers1_rect(&tower_rect, num);
    check_towers2_rect(&tower_rect, num);
    check_towers3_rect(&tower_rect, num);
    return (tower_rect);
}

int is_rect_equal_to(unsigned int num, sfIntRect rect)
{
    sfIntRect tower_rect = save_tower_rect(num);

    if (is_same_rect(rect, tower_rect)) {
        return (1);
    }
    return (0);
}

int which_tower_it_is(struct game_object tower)
{
    unsigned int towers_status_nbr = 13;

    for (int i = 0; i < towers_status_nbr; i++) {
        if (is_rect_equal_to(i, tower.rect))
            return (i);
    }
    return (-1);
}