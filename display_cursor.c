/*
** EPITECH PROJECT, 2021
** display_cursor
** File description:
** display the cursor depending on the the holding status
*/

#include "include/my.h"

void set_mouse_pos_and_display(sfRenderWindow *window,
storage_t *st, unsigned int pos, sfVector2f pos_cursor)
{
    struct game_object cursor = get_at(st->cursors, pos);

    cursor.pos.x = pos_cursor.x;
    cursor.pos.y = pos_cursor.y;
    sfSprite_setPosition(cursor.sprite, cursor.pos);
    set_at(st->cursors, cursor, pos);
    display_sprite(window, st->cursors, pos);
}

void define_sprite_to_display(sfRenderWindow *window,
status_t *status, storage_t *st, sfVector2f pos_cursor)
{
    switch (status->hold) {
        case HOLDING_STONE:
        set_mouse_pos_and_display(window, st, LSTONE, pos_cursor);
            break;
        case HOLDING_POISON:
        set_mouse_pos_and_display(window, st, LPOISON, pos_cursor);
            break;
        case HOLDING_WIZARD:
        set_mouse_pos_and_display(window, st, LWIZARD, pos_cursor);
            break;
        case HOLDING_TESLA:
        set_mouse_pos_and_display(window, st, LTESLA, pos_cursor);
            break;
        case HOLDING_MAGNUS:
        set_mouse_pos_and_display(window, st, LMAGNUS, pos_cursor);
            break;
        default:
        set_mouse_pos_and_display(window, st, HAND, pos_cursor);
            break;
    }
}

void display_cursor(sfRenderWindow *window, storage_t *st, status_t *status)
{
    sfVector2f pos_cursor;

    st->mouse = vectorf(sfMouse_getPositionRenderWindow(window).x,
    sfMouse_getPositionRenderWindow(window).y);
    pos_cursor = vectorf(st->mouse.x - 6, st->mouse.y - 3);
    define_sprite_to_display(window, status, st, pos_cursor);
}