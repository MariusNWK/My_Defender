/*
** EPITECH PROJECT, 2021
** create_menu_sprites
** File description:
** create all the sprites of the menu
*/

#include "include/my.h"

void create_menu_sprites_five(storage_t *st)
{
    st->menu = add_at(st->menu, create_object("./images/144 empty.png",
    vectorf(1250, 450), rect(0, 0, 315, 150), vectorf(0.6, 0.6)), HFF_EMPTY);
    st->menu = add_at(st->menu, create_object("./images/144 filled.png",
    vectorf(1250, 450), rect(0, 0, 315, 150), vectorf(0.6, 0.6)), HFF_FILLED);
    st->menu = add_at(st->menu, create_object("./images/144 filled.png",
    vectorf(1260, 455), rect(0, 0, 315, 150), vectorf(0.54, 0.54)), HFF_PR);
    st->menu = add_at(st->menu, create_object("./images/144 green.png",
    vectorf(1250, 450), rect(0, 0, 315, 150), vectorf(0.6, 0.6)), HFF_GREEN);
    st->menu = add_at(st->menu, create_object("./images/SOUND.png",
    vectorf(360, 700), rect(0, 0, 525, 150), vectorf(0.6, 0.6)), SOUND);
    st->menu = add_at(st->menu, create_object("./images/cone.png",
    vectorf(850, 615), rect(0, 0, 400, 267), vectorf(1.1, 1)), CONE);
    st->menu = add_at(st->menu, create_object("./images/tongue.png",
    vectorf(1250, 616), rect(0, 0, 40, 267), vectorf(1, 1)), TONGUE);
}

void create_menu_sprites_four(storage_t *st)
{
    st->menu = add_at(st->menu, create_object("./images/FPS.png",
    vectorf(440, 450), rect(0, 0, 315, 150), vectorf(0.5, 0.5)), FPS);
    st->menu = add_at(st->menu, create_object("./images/30 empty.png",
    vectorf(750, 450), rect(0, 0, 210, 150), vectorf(0.6, 0.6)), TTY_EMPTY);
    st->menu = add_at(st->menu, create_object("./images/30 filled.png",
    vectorf(750, 450), rect(0, 0, 210, 150), vectorf(0.6, 0.6)), TTY_FILLED);
    st->menu = add_at(st->menu, create_object("./images/30 filled.png",
    vectorf(756, 455), rect(0, 0, 210, 150), vectorf(0.54, 0.54)), TTY_PR);
    st->menu = add_at(st->menu, create_object("./images/30 green.png",
    vectorf(750, 450), rect(0, 0, 210, 150), vectorf(0.6, 0.6)), TTY_GREEN);
    st->menu = add_at(st->menu, create_object("./images/60 empty.png",
    vectorf(1000, 450), rect(0, 0, 210, 150), vectorf(0.6, 0.6)), STY_EMPTY);
    st->menu = add_at(st->menu, create_object("./images/60 filled.png",
    vectorf(1000, 450), rect(0, 0, 210, 150), vectorf(0.6, 0.6)), STY_FILLED);
    st->menu = add_at(st->menu, create_object("./images/60 filled.png",
    vectorf(1006, 455), rect(0, 0, 210, 150), vectorf(0.54, 0.54)), STY_PR);
    st->menu = add_at(st->menu, create_object("./images/60 green.png",
    vectorf(1000, 450), rect(0, 0, 210, 150), vectorf(0.6, 0.6)), STY_GREEN);
    create_menu_sprites_five(st);
}

void create_menu_sprites_three(storage_t *st)
{
    st->menu = add_at(st->menu, create_object("./images/MODE.png",
    vectorf(400, 200), rect(0, 0, 420, 150), vectorf(0.6, 0.6)), MODE);
    st->menu = add_at(st->menu, create_object("./images/WINDOWED empty.png",
    vectorf(750, 200), rect(0, 0, 840, 150), vectorf(0.6, 0.6)), WNDW_EMPTY);
    st->menu = add_at(st->menu, create_object("./images/WINDOWED filled.png",
    vectorf(750, 200), rect(0, 0, 840, 150), vectorf(0.6, 0.6)), WNDW_FILLED);
    st->menu = add_at(st->menu, create_object("./images/WINDOWED filled.png",
    vectorf(775, 205), rect(0, 0, 840, 150), vectorf(0.54, 0.54)), WNDW_PR);
    st->menu = add_at(st->menu, create_object("./images/WINDOWED green.png",
    vectorf(750, 200), rect(0, 0, 840, 150), vectorf(0.6, 0.6)), WNDW_GREEN);
    st->menu = add_at(st->menu, create_object("./images/FULLSCREEN empty.png",
    vectorf(1300, 200), rect(0, 0, 840, 150), vectorf(0.6, 0.6)), FS_EMPTY);
    st->menu = add_at(st->menu, create_object("./images/FULLSCREEN filled.png",
    vectorf(1300, 200), rect(0, 0, 840, 150), vectorf(0.6, 0.6)), FS_FILLED);
    st->menu = add_at(st->menu, create_object("./images/FULLSCREEN filled.png",
    vectorf(1325, 205), rect(0, 0, 840, 150), vectorf(0.54, 0.54)), FS_PR);
    st->menu = add_at(st->menu, create_object("./images/FULLSCREEN green.png",
    vectorf(1300, 200), rect(0, 0, 840, 150), vectorf(0.6, 0.6)), FS_GREEN);
    create_menu_sprites_four(st);
}

void create_menu_sprites_two(storage_t *st)
{
    st->menu = add_at(st->menu, create_object("./images/knight.jpg",
    vectorf(0, 0), rect(0, 0, 1920, 1080), vectorf(1, 1)), BACKGROUND_ONE);
    st->menu = add_at(st->menu, create_object("./images/castle.jfif",
    vectorf(0, 0), rect(0, 0, 1920, 1080), vectorf(1, 1)), BACKGROUND_TWO);
    st->menu = add_at(st->menu, create_object("./images/brown.jpg",
    vectorf(0, 0), rect(0, 0, 1920, 1080), vectorf(1, 1)), BACKGROUND_THREE);
    st->menu = add_at(st->menu, create_object("./images/ARROW empty.png",
    vectorf(80, 900), rect(0, 0, 700, 471), vectorf(0.3, 0.3)), ARROW_EMPTY);
    st->menu = add_at(st->menu, create_object("./images/ARROW filled.png",
    vectorf(80, 900), rect(0, 0, 700, 471), vectorf(0.3, 0.3)), ARROW_FILLED);
    st->menu = add_at(st->menu, create_object("./images/ARROW filled.png",
    vectorf(90, 905), rect(0, 0, 700, 471), vectorf(0.27, 0.27)), ARROW_PR);
    st->menu == add_at(st->menu, create_object("./images/OPTIONS empty.png",
    vectorf(764, 598), rect(0, 0, 735, 150), vectorf(0.6, 0.6)), OPT_EMPTY);
    st->menu == add_at(st->menu, create_object("./images/OPTIONS filled.png",
    vectorf(764, 598), rect(0, 0, 735, 150), vectorf(0.6, 0.6)), OPT_FILLED);
    st->menu == add_at(st->menu, create_object("./images/OPTIONS filled.png",
    vectorf(784, 603), rect(0, 0, 735, 150), vectorf(0.54, 0.54)), OPT_PR);
    create_menu_sprites_three(st);
}

void create_menu_sprites(storage_t *st)
{
    st->menu = NULL;
    st->menu = add_at(st->menu, create_object("./images/HOW TO PLAY empty.png",
    vectorf(630, 428), rect(0, 0, 900, 150), vectorf(0.8, 0.8)), HTPLAY_EMPTY);
    st->menu = add_at(st->menu, create_object("./images/HOW TO PLAY filled.png",
    vectorf(630, 428), rect(0, 0, 900, 150), vectorf(0.8, 0.8)), HTPLAY_FILLED);
    st->menu = add_at(st->menu, create_object("./images/HOW TO PLAY filled.png",
    vectorf(660, 433), rect(0, 0, 900, 150), vectorf(0.72, 0.72)), HTPLAY_PR);
    st->menu = add_at(st->menu, create_object("./images/PLAY empty.png",
    vectorf(864, 745), rect(0, 0, 420, 150), vectorf(0.6, 0.6)), PLAY_EMPTY);
    st->menu = add_at(st->menu, create_object("./images/PLAY filled.png",
    vectorf(864, 745), rect(0, 0, 420, 150), vectorf(0.6, 0.6)), PLAY_FILLED);
    st->menu = add_at(st->menu, create_object("./images/PLAY filled.png",
    vectorf(874, 750), rect(0, 0, 420, 150), vectorf(0.54, 0.54)), PLAY_PR);
    st->menu = add_at(st->menu, create_object("./images/QUIT empty.png",
    vectorf(864, 892), rect(0, 0, 420, 150), vectorf(0.6, 0.6)), QUIT_EMPTY);
    st->menu = add_at(st->menu, create_object("./images/QUIT filled.png",
    vectorf(864, 892), rect(0, 0, 420, 150), vectorf(0.6, 0.6)), QUIT_FILLED);
    st->menu = add_at(st->menu, create_object("./images/QUIT filled.png",
    vectorf(874, 897), rect(0, 0, 420, 150), vectorf(0.54, 0.54)), QUIT_PR);
    create_menu_sprites_two(st);
}