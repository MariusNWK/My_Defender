/*
** EPITECH PROJECT, 2021
** does mouse touche sprite
** File description:
** return 1 if the mouse is on the sprite, else return 0
*/

#include "include/my.h"

int does_mouse_touch_sprite(struct game_object obj, sfVector2f mouse)
{
    if (mouse.x > obj.pos.x && mouse.x < obj.pos.x +
        obj.rect.width * obj.scale.x &&
        mouse.y > obj.pos.y && mouse.y < obj.pos.y +
        obj.rect.height * obj.scale.y)
        return (1);
    return (0);
}

int state_button(sfRenderWindow *window, list_t *list,
unsigned int pos, status_t *status)
{
    sfVector2f mouse = vectorf(sfMouse_getPositionRenderWindow(window).x,
    sfMouse_getPositionRenderWindow(window).y);

    if (does_mouse_touch_sprite(get_at(list, pos + 1), mouse) &&
        status->event == PRESSED) {
        display_sprite(window, list, pos + 2);
        return (1);
    }
    if (does_mouse_touch_sprite(get_at(list, pos + 1), mouse)) {
        display_sprite(window, list, pos + 1);
        return (1);
    }
    display_sprite(window, list, pos);
    return (0);
}