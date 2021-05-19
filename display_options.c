/*
** EPITECH PROJECT, 2021
** display options
** File description:
** display the options buttons and manage user inputs
*/

#include "include/my.h"

void define_sound(storage_t *st, int volume)
{
    sfMusic_setVolume(st->audio.music, volume);
    sfSound_setVolume(st->audio.building, volume);
    sfSound_setVolume(st->audio.click, volume);
    sfSound_setVolume(st->audio.die, 0.6 * volume);
}

void handle_style(sfRenderWindow *window, status_t *status, storage_t *st)
{
    if (status->style == FULLSCREEN &&
            is_sprite_pressed(window, st->menu, WNDW_EMPTY, status)) {
        status->style = MOVE_TO_W;
    }
    if (status->style == WINDOWED &&
        is_sprite_pressed(window, st->menu, FS_EMPTY, status)) {
        status->style = MOVE_TO_FS;
    }
    if (status->style == FULLSCREEN)
        display_sprite(window, st->menu, FS_GREEN);
    if (status->style == WINDOWED)
        display_sprite(window, st->menu, WNDW_GREEN);
}

void handle_fps(sfRenderWindow *window, status_t *status, storage_t *st)
{
    if (status->fps != THIRTY &&
        is_sprite_pressed(window, st->menu, TTY_EMPTY, status)) {
        sfRenderWindow_setFramerateLimit(window, 30);
        status->fps = THIRTY;
    }
    if (status->fps != SIXTY &&
        is_sprite_pressed(window, st->menu, STY_EMPTY, status)) {
        sfRenderWindow_setFramerateLimit(window, 60);
        status->fps = SIXTY;
    }
    if (status->fps != HUNDREDFF &&
        is_sprite_pressed(window, st->menu, HFF_EMPTY, status)) {
        sfRenderWindow_setFramerateLimit(window, 144);
        status->fps = HUNDREDFF;
    }
}

void handle_sound(sfRenderWindow *window, status_t *status, storage_t *st)
{
    struct game_object tongue;
    sfVector2f mouse = vectorf(sfMouse_getPositionRenderWindow(window).x,
    sfMouse_getPositionRenderWindow(window).y);

    tongue = get_at(st->menu, TONGUE);
    if (does_mouse_touch_sprite(tongue, mouse) &&
        status->event == PRESSED && status->holdsound == NO)
        status->holdsound = YES;
    if (status->event == RELEASED)
        status->holdsound = NO;
    if (status->holdsound == YES) {
        tongue.pos.x = mouse.x - 20;
        if (tongue.pos.x < 850)
            tongue.pos.x = 850;
        if (tongue.pos.x > 1250)
            tongue.pos.x = 1250;
        sfSprite_setPosition(tongue.sprite, tongue.pos);
        set_at(st->menu, tongue, TONGUE);
        define_sound(st, (tongue.pos.x - 850) / 4);
    }
    display_sprite(window, st->menu, TONGUE);
}

void display_options(sfRenderWindow *window, status_t *status, storage_t *st)
{
    if (status->menu == OPT_TRUE) {
        display_sprite(window, st->menu, MODE);
        handle_style(window, status, st);
        display_sprite(window, st->menu, FPS);
        handle_fps(window, status, st);
        switch (status->fps) {
            case THIRTY: display_sprite(window, st->menu, TTY_GREEN);
                break;
            case SIXTY: display_sprite(window, st->menu, STY_GREEN);
                break;
            case HUNDREDFF: display_sprite(window, st->menu, HFF_GREEN);
                break;
            default: break;
        }
        display_sprite(window, st->menu, SOUND);
        display_sprite(window, st->menu, CONE);
        handle_sound(window, status, st);
    }
}