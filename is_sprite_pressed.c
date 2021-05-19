/*
** EPITECH PROJECT, 2021
** is_sprite_pressed
** File description:
** return true if the sprite is pressed, else return false
*/

#include "include/my.h"

sfBool is_sprite_pressed(sfRenderWindow *window, list_t *list,
unsigned int pos, status_t *status)
{
    if (state_button(window, list, pos, status) &&
        status->event == RELEASED) {
        status->sound = CLICK;
        return (sfTrue);
    }
    return (sfFalse);
}