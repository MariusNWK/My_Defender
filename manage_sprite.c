/*
** EPITECH PROJECT, 2021
** manage sprite
** File description:
** upgrade tower / display tower / display cases
*/

#include "include/my.h"

void pay_tower_building(storage_t *st, status_t *status)
{
    unsigned int prec_golds = st->golds;

    switch (status->hold) {
        case HOLDING_STONE: st->golds -= 100;
            break;
        case HOLDING_POISON: st->golds -= 200;
            break;
        case HOLDING_WIZARD: st->golds -= 500;
            break;
        case HOLDING_TESLA: st->golds -= 1000;
            break;
        case HOLDING_MAGNUS: st->golds -= 2000;
            break;
        default: break;
    }
    st->lost_golds = prec_golds - st->golds;
    sfClock_restart(st->clocks.lostgoldsclock);
}

void change_sprite(storage_t *st, status_t *status, int i)
{
    sfVector2f pos_case = get_at(st->cases, i).pos;
    struct game_object tower1 = select_tower1(status, st, i, pos_case);
    struct game_object tower2 = select_tower2(status, st, i, pos_case);

    define_projectile(st, i / 2, tower1);
    destroy_obj_sprite_and_texture(get_at(st->cases, i));
    destroy_obj_sprite_and_texture(get_at(st->cases, i + 1));
    set_at(st->cases, tower1, i);
    set_at(st->cases, tower2, i + 1);
    pay_tower_building(st, status);
}

int is_a_case(storage_t *st, int i)
{
    struct game_object obj = get_at(st->cases, i);

    if (obj.rect.left == 0 && obj.rect.top == 0 &&
        obj.rect.width == 100 && obj.rect.height == 100 &&
        obj.scale.x == 1 && obj.scale.y == 1) {
        return (1);
    }
    return (0);
}

void manage_sprite(status_t *status, storage_t *st, int i)
{
    if (status->hold != NOHOLDING && is_a_case(st, i) &&
        are_enough_golds_to_buy(st, status)) {
        status->sound = BUILDING;
        change_sprite(st, status, i);
    }
    else if (is_a_case(st, i) == 0 && status->hold == NOHOLDING &&
        are_enough_golds_to_upgrade(st, i)) {
        status->sound = BUILDING;
        upgrade_tower(st, i);
    }
}