/*
** EPITECH PROJECT, 2021
** display_shop
** File description:
** display the sprites of the shop
*/

#include "include/my.h"

int is_tower_pressed(sfRenderWindow *window, storage_t *st,
unsigned int pos, status_t *status)
{
    if (state_tower(window, st, pos, status) &&
        status->event == PRESSED && status->hold == NOHOLDING) {
        return (1);
    }
    return (0);
}

void define_tower_status(sfRenderWindow *window, storage_t *st,
unsigned int pos, status_t *status)
{
    if (is_tower_pressed(window, st, pos, status)) {
        switch (pos) {
            case STONE_GREY: status->hold = HOLDING_STONE;
                break;
            case POISON_GREY: status->hold = HOLDING_POISON;
                break;
            case WIZARD_GREY: status->hold = HOLDING_WIZARD;
                break;
            case TESLA_GREY: status->hold = HOLDING_TESLA;
                break;
            case MAGNUS_GREY: status->hold = HOLDING_MAGNUS;
                break;
            default:
                break;
        }
    }
    if (status->event == RELEASED) {
        status->hold = NOHOLDING;
    }
}

void display_money(sfRenderWindow *window, storage_t *st)
{
    char *money = uint_to_str(st->golds);
    int len = my_strlen(money);
    sfVector2f pos = {80 - len * 12, 1020};

    sfText_setPosition(st->texts.money.text, pos);
    sfText_setString(st->texts.money.text, money);
    sfRenderWindow_drawText(window, st->texts.money.text, NULL);
    free(money);
}

void display_lostgolds(sfRenderWindow *window, storage_t *st)
{
    char *lostgolds = uint_to_str(st->lost_golds);
    int len = my_strlen(lostgolds);
    char *add_minus = malloc(sizeof(char) * (len + 2));

    add_minus[0] = '-';
    for (int i = 0; i < len; i++) {
        add_minus[i + 1] = lostgolds[i];
    }
    add_minus[len + 1] = '\0';
    free(lostgolds);
    sfText_setString(st->texts.lostgolds.text, add_minus);
    sfRenderWindow_drawText(window, st->texts.lostgolds.text, NULL);
    free(add_minus);
}

void display_store(sfRenderWindow *window, status_t *status, storage_t *st)
{
    define_tower_status(window, st, STONE_GREY, status);
    define_tower_status(window, st, POISON_GREY, status);
    define_tower_status(window, st, WIZARD_GREY, status);
    define_tower_status(window, st, TESLA_GREY, status);
    define_tower_status(window, st, MAGNUS_GREY, status);
    display_sprite(window, st->play, GOLD_BAG);
    display_money(window, st);
    if (seconds_clock(st->clocks.lostgoldsclock) < 1 && st->lost_golds > 0)
        display_lostgolds(window, st);
    if (seconds_clock(st->clocks.notenoughmoneyclock) < 1 &&
        st->display_notenoughmoney == sfTrue)
        sfRenderWindow_drawText(window, st->texts.notenoughmoney.text, NULL);
}