/*
** EPITECH PROJECT, 2021
** define traj
** File description:
** define the trajectory of a projectile
*/

#include "include/my.h"

sfVector2f predict_knight_move(sfVector2f traj, struct game_object knight)
{
    switch (knight.move) {
        case RIGHT: return (vectorf(traj.x + 30, traj.y));
        case UP: return (vectorf(traj.x, traj.y - 30));
        case LEFT: return (vectorf(traj.x - 30, traj.y));
        case DOWN: return (vectorf(traj.x, traj.y + 30));
        default: return (traj);
    }
    return (traj);
}

sfVector2f define_traj(struct game_object proj, struct game_object knight)
{
    proj.pos.x += proj.rect.width / 2;
    proj.pos.y += proj.rect.height / 2;
    sfVector2f traj = {knight.pos.x - proj.pos.x, knight.pos.y - proj.pos.y};

    traj = predict_knight_move(traj, knight);
    return (traj);
}