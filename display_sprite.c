/*
** EPITECH PROJECT, 2021
** display sprite
** File description:
** function to display the sprite given in argument
*/

#include "include/my.h"

void display_sprite(sfRenderWindow *window, list_t *list, unsigned int pos)
{
    sfRenderWindow_drawSprite(window, get_at(list, pos).sprite, NULL);
}