/*
** EPITECH PROJECT, 2021
** create_lists
** File description:
** create every list of sprites
*/

#include "include/my.h"

void create_play_sprites(storage_t *st)
{
    st->play = NULL;
    st->play = add_at(st->play, create_object("./images/grass.jpg",
    vectorf(0, 0), rect(0, 0, 1920, 1080), vectorf(1, 1)), GRASS);
    create_cases(st);
    create_projectiles(st);
    create_echap(st);
    create_castle(st);
    create_gameover(st);
    create_store(st);
}

clocks_t create_clocks(void)
{
    clocks_t clocks;

    clocks.deltaclock = sfClock_create();
    clocks.fireclock = sfClock_create();
    clocks.lostgoldsclock = sfClock_create();
    clocks.notenoughmoneyclock = sfClock_create();
    clocks.createclock = sfClock_create();
    clocks.timeclock = sfClock_create();
    return (clocks);
}

texts_t create_texts(void)
{
    texts_t texts;
    texts.title = create_text("./fonts/aAbsoluteEmpire.ttf", vectorf(50, 50),
    180, "PROTECT THE KING");
    sfText_setColor(texts.title.text, sfBlack);
    texts.howto = create_text("./fonts/Sketchy.ttf", vectorf(370, 100),
    35, htplay_str());
    texts.gameover = create_text("./fonts/HU The Game.ttf",
    vectorf(180, 20), 300, "GAME OVER");
    sfText_setColor(texts.gameover.text, sfBlack);
    texts.money = create_text("./fonts/UKNumberPlate.ttf",
    vectorf(45, 1020), 50, "100");
    sfText_setColor(texts.money.text, sfYellow);
    texts.lostgolds = create_text("./fonts/HU The Game.ttf",
    vectorf(165, 1020), 50, "-100");
    sfText_setColor(texts.lostgolds.text, sfRed);
    texts.notenoughmoney = create_text("./fonts/UKNumberPlate.ttf",
    vectorf(700, 1020), 50, "Not enough gold coins");
    sfText_setColor(texts.notenoughmoney.text, sfRed);
    texts.knights_killed = create_text("./fonts/UKNumberPlate.ttf",
    vectorf(1800, 30), 50, "0");
    return (texts);
}

void create_cursor_sprites(storage_t *st)
{
    st->cursors = NULL;
    st->cursors = add_at(st->cursors, create_object("./images/cursor.png",
    vectorf(990, 540), rect(0, 0, 1089, 1024), vectorf(0.035, 0.035)), HAND);
    st->cursors = add_at(st->cursors, create_object("./images/STONE tower.png",
    vectorf(990, 540), rect(0, 60, 140, 180), vectorf(0.2, 0.2)), LSTONE);
    st->cursors = add_at(st->cursors, create_object("./images/POISON tower.png",
    vectorf(990, 540), rect(20, 70, 160, 190), vectorf(0.2, 0.2)), LPOISON);
    st->cursors = add_at(st->cursors, create_object("./images/WIZARD tower.png",
    vectorf(990, 540), rect(60, 100, 110, 200), vectorf(0.2, 0.2)), LWIZARD);
    st->cursors = add_at(st->cursors, create_object("./images/TESLA tower.png",
    vectorf(990, 540), rect(70, 90, 90, 210), vectorf(0.2, 0.2)), LTESLA);
    st->cursors = add_at(st->cursors, create_object("./images/MAGNUS tower.png",
    vectorf(990, 540), rect(10, 10, 120, 260), vectorf(0.2, 0.2)), LMAGNUS);
}

storage_t creator(void)
{
    storage_t storage;

    create_menu_sprites(&storage);
    create_play_sprites(&storage);
    create_cursor_sprites(&storage);
    storage.knights = NULL;
    storage.clocks = create_clocks();
    storage.texts = create_texts();
    storage.echap = sfFalse;
    storage.display_notenoughmoney = sfFalse;
    storage.golds = 1000;
    storage.lost_golds = 0;
    storage.hp = 100;
    storage.bars = NULL;
    create_audio(&storage);
    storage.knights_killed = 0;
    storage.fiftykills = sfFalse;
    storage.fivehundredskills = sfFalse;
    return (storage);
}