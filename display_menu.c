/*
** EPITECH PROJECT, 2021
** display_menu
** File description:
** display the menu and manage interactions
*/

#include "include/my.h"

void display_background(sfRenderWindow *window,
status_t *status, storage_t *storage)
{
    if (status->menu == DEFAULT)
        display_sprite(window, storage->menu, BACKGROUND_ONE);
    else if (status->menu == OPT_TRUE)
        display_sprite(window, storage->menu, BACKGROUND_THREE);
    else
        display_sprite(window, storage->menu, BACKGROUND_TWO);
}

void display_buttons(sfRenderWindow *window, status_t *status,
storage_t *st)
{
    if (status->menu == DEFAULT) {
        if (is_sprite_pressed(window, st->menu, HTPLAY_EMPTY, status))
            status->menu = HTP_TRUE;
        if (is_sprite_pressed(window, st->menu, PLAY_EMPTY, status)) {
            status->game = PLAY;
            sfClock_restart(st->clocks.timeclock);
        }
        if (is_sprite_pressed(window, st->menu, QUIT_EMPTY, status))
            status->game = QUIT;
        if (is_sprite_pressed(window, st->menu, OPT_EMPTY, status))
            status->menu = OPT_TRUE;
    }
    else if (status->menu == OPT_TRUE) {
        if (is_sprite_pressed(window, st->menu, ARROW_EMPTY, status))
            status->menu = DEFAULT;
    }
    else {
        if (is_sprite_pressed(window, st->menu, ARROW_EMPTY, status))
            status->menu = DEFAULT;
    }
}

void display_text(sfRenderWindow *window, status_t *status,
storage_t *st)
{
    if (status->menu == DEFAULT)
        sfRenderWindow_drawText(window, st->texts.title.text, NULL);
    else if (status->menu == HTP_TRUE)
        sfRenderWindow_drawText(window, st->texts.howto.text, NULL);
}

void display_menu(sfRenderWindow *window, status_t *status, storage_t *storage)
{
    display_background(window, status, storage);
    display_buttons(window, status, storage);
    display_options(window, status, storage);
    display_text(window, status, storage);
}