/*
** EPITECH PROJECT, 2021
** define projectile
** File description:
** define the texture of the projectile depending on the tower
*/

#include "include/my.h"

void define_projectile(storage_t *st, int i, struct game_object tower)
{
    struct game_object proj = get_at(st->proj, i);
    sfTexture *image;
    switch (which_tower_it_is(tower)) {
        case S1: image = sfTexture_createFromFile("./images/stone.png", NULL);
            break;
        case P1: image = sfTexture_createFromFile("./images/poison.png", NULL);
            break;
        case W1: image = sfTexture_createFromFile("./images/slow.png", NULL);
            break;
        case T1: image = sfTexture_createFromFile("./images/storm.png", NULL);
            proj.speedf = 4;
            break;
        case M1: image = sfTexture_createFromFile("./images/bomb.png", NULL);
            proj.speedf = 0.5;
            break;
        default: return;
    }
    sfTexture_destroy(proj.texture);
    proj.texture = image;
    sfSprite_setTexture(proj.sprite, proj.texture, sfFalse);
    set_at(st->proj, proj, i);
}