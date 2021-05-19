/*
** EPITECH PROJECT, 2021
** display_game
** File description:
** display Defender and his gameplay
*/

#include "include/my.h"

void display_echap(sfRenderWindow *window, status_t *status, storage_t *st)
{
    if (status->event == ECHAP && st->echap == sfFalse && status->play == ALIVE)
        st->echap = sfTrue;
    else if (status->event == ECHAP && st->echap == sfTrue)
        st->echap = sfFalse;
    if (st->echap) {
        display_sprite(window, st->play, SMOKE);
        if (is_sprite_pressed(window, st->play, RESUME_EMPTY, status))
            st->echap = sfFalse;
        if (is_sprite_pressed(window, st->play, MENU_EMPTY, status)) {
            st->echap = sfFalse;
            reset(st);
            status->game = MENU;
        }
        if (is_sprite_pressed(window, st->play, QUIT2_EMPTY, status))
            status->game = QUIT;
    }
}

void display_castle(sfRenderWindow *window, status_t *status, storage_t *st)
{
    struct game_object obj;

    obj = get_at(st->play, HP);
    obj.rect.width = st->hp * 2;
    apply_settings(&obj);
    display_sprite(window, st->play, BAR);
    display_sprite(window, st->play, HP);
    if (status->play == ALIVE)
        display_sprite(window, st->play, CASTLE);
    else {
        display_sprite(window, st->play, FIRE);
        display_sprite(window, st->play, CASTLE_DESTR);
    }
    st->play = animate_sprite(st->play, FIRE,
    st->clocks.fireclock, set_lim(200, 200, 800, 800));
}

void display_gameover(sfRenderWindow *window, status_t *status, storage_t *st)
{
    if (st->hp <= 0) {
        status->play = GAMEOVER;
        st->hp = 0;
    }
    if (status->play == GAMEOVER) {
        sfRenderWindow_drawText(window, st->texts.gameover.text, NULL);
        if (is_sprite_pressed(window, st->play, TRYAG_EMPTY, status)) {
            reset(st);
            status->play = ALIVE;
        }
        if (is_sprite_pressed(window, st->play, MENU2_EMPTY, status)) {
            reset(st);
            status->play = ALIVE;
            status->game = MENU;
        }
        if (is_sprite_pressed(window, st->play, QUIT3_EMPTY, status))
            status->game = QUIT;
    }
}

void display_game(sfRenderWindow *window, status_t *status, storage_t *st)
{
    display_sprite(window, st->play, GRASS);
    display_castle(window, status, st);
    display_knights_killed_nbr(window, st);
    display_cases_towers_knights(window, status, st);
    display_projectiles(window, status, st);
    display_store(window, status, st);
    display_echap(window, status, st);
    display_gameover(window, status, st);
}