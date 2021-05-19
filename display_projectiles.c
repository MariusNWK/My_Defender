/*
** EPITECH PROJECT, 2021
** display projectiles
** File description:
** display the projectiles
*/

#include "include/my.h"

void manage_slow(storage_t *st, struct game_object knight, int j)
{
    if (knight.speed != 100 && seconds_clock(knight.slow_clock) > 1) {
        knight.pos = redef_pos(knight.pos, -22.8, -32);
        knight.speed = 100;
        set_at(st->knights, knight, j);
    }
}

void display_if_launched(sfRenderWindow *window, struct game_object proj)
{
    if (proj.launched == sfTrue)
        sfRenderWindow_drawSprite(window, proj.sprite, NULL);
}

struct game_object attack_if_knight_in_range(storage_t *st, int j,
struct game_object proj, struct game_object a_case)
{
    struct game_object knight = get_at(st->knights, j);

    knight.pos = redef_pos(knight.pos, 22.8, 32);
    if (is_knight_in_range(knight, a_case) && proj.launched == sfFalse)
        proj.launched = sfTrue;
    if (proj.launched) {
        if (proj.traj.x == 0 && proj.traj.y == 0)
            proj.traj = define_traj(proj, knight);
    }
    if (does_proj_touch_knight(knight, proj)) {
        knight = apply_effects(knight, a_case);
        set_at(st->knights, knight, j);
        proj = reset_proj(proj, a_case);
    }
    else if (is_proj_out_of_map(proj))
        proj = reset_proj(proj, a_case);
    manage_slow(st, knight, j);
    return (proj);
}

void compare_knight_and_tower(sfRenderWindow *window,
status_t *status, storage_t *st, int i)
{
    struct game_object a_case = get_at(st->cases, i * 2);
    struct game_object proj = get_at(st->proj, i);
    int tower = which_tower_it_is(a_case);
    int knights_nbr = len_list(st->knights);

    proj.pos.x += proj.traj.x * st->deltaseconds * proj.speedf;
    proj.pos.y += proj.traj.y * st->deltaseconds * proj.speedf;
    sfSprite_setPosition(proj.sprite, proj.pos);
    a_case.pos = redef_pos_case(a_case.pos, tower);
    for (int j = 0; j < knights_nbr; j++) {
        proj = attack_if_knight_in_range(st, j, proj, a_case);
    }
    set_at(st->proj, proj, i);
}

void display_projectiles(sfRenderWindow *window,
status_t *status, storage_t *st)
{
    int projectiles_nbr = 46;

    for (int i = 0; i < projectiles_nbr; i++) {
        if (status->play == ALIVE && st->echap == sfFalse)
            compare_knight_and_tower(window, status, st, i);
        display_if_launched(window, get_at(st->proj, i));
    }
}