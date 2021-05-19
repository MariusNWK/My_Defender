/*
** EPITECH PROJECT, 2021
** create audio
** File description:
** create the sounds and the musics
*/

#include "include/my.h"

sfSound *set_buffer_sound(sfSoundBuffer *buffer)
{
    sfSound *sound = sfSound_create();

    sfSound_setBuffer(sound, buffer);
    return (sound);
}

sfSoundBuffer *create_buffer(char const *path)
{
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(path);

    return (buffer);
}

void create_audio(storage_t *st)
{
    st->audio.music = sfMusic_createFromFile("./musics/for honor.ogg");
    st->audio.click_buffer = create_buffer("./sounds/click.ogg");
    st->audio.click = set_buffer_sound(st->audio.click_buffer);
    st->audio.building_buffer = create_buffer("./sounds/building.ogg");
    st->audio.building = set_buffer_sound(st->audio.building_buffer);
    st->audio.die_buffer = create_buffer("./sounds/die.ogg");
    st->audio.die = set_buffer_sound(st->audio.die_buffer);
    sfSound_setVolume(st->audio.die, 50);
}