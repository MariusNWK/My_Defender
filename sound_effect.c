/*
** EPITECH PROJECT, 2021
** sound effect
** File description:
** play the sound effects
*/

#include "include/my.h"

void sound_effect(status_t *status, storage_t *st)
{
    switch (status->sound) {
        case CLICK: sfSound_play(st->audio.click);
            break;
        case BUILDING: sfSound_play(st->audio.building);
            break;
        default: break;
    }
    status->sound = NOSOUND;
}