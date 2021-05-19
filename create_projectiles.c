/*
** EPITECH PROJECT, 2021
** create projectiles
** File description:
** create sprites of the projectiles to define pos at cases
*/

#include "include/my.h"

void create_projectiles(storage_t *st)
{
    int cases_nbr = 46;
    struct game_object a_case;
    struct game_object proj;
    sfVector2f pos;

    st->proj = NULL;
    for (int i = 0; i < cases_nbr; i++) {
        a_case = get_at(st->cases, i * 2);
        pos = vectorf(a_case.pos.x + 35, a_case.pos.y + 35);
        proj = create_object("./images/stone.png",
        pos, rect(0, 0, 30, 30), vectorf(1, 1));
        proj.launched = sfFalse;
        proj.traj = vectorf(0, 0);
        proj.speedf = 2.5;
        st->proj = add_at(st->proj, proj, i);
    }
}