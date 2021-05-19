/*
** EPITECH PROJECT, 2021
** destroyer
** File description:
** destroy all textures/sprites
*/

#include "include/my.h"

void destroy_list_sprites_and_textures(list_t *list)
{
    int len = len_list(list);
    struct game_object obj;

    for (int i = 0; i < len; i++) {
        obj = get_at(list, i);
        sfTexture_destroy(obj.texture);
        sfSprite_destroy(obj.sprite);
    }
    free_list(list);
}

void destroy_clocks(storage_t *storage)
{
    sfClock_destroy(storage->clocks.deltaclock);
    sfClock_destroy(storage->clocks.fireclock);
    sfClock_destroy(storage->clocks.lostgoldsclock);
    sfClock_destroy(storage->clocks.notenoughmoneyclock);
    sfClock_destroy(storage->clocks.createclock);
    sfClock_destroy(storage->clocks.timeclock);
}

void destroy_text(struct game_text title)
{
    sfFont_destroy(title.font);
    sfText_destroy(title.text);
}

void destroy_audio(storage_t *st)
{
    sfMusic_destroy(st->audio.music);
    sfSoundBuffer_destroy(st->audio.click_buffer);
    sfSound_destroy(st->audio.click);
    sfSoundBuffer_destroy(st->audio.building_buffer);
    sfSound_destroy(st->audio.building);
    sfSoundBuffer_destroy(st->audio.die_buffer);
    sfSound_destroy(st->audio.die);
}

void destroyer(storage_t *storage)
{
    destroy_list_sprites_and_textures(storage->menu);
    destroy_list_sprites_and_textures(storage->play);
    destroy_list_sprites_and_textures(storage->cases);
    destroy_list_sprites_and_textures(storage->cursors);
    destroy_list_sprites_and_textures(storage->bars);
    destroy_list_sprites_and_textures(storage->proj);
    destroy_list_sprites_and_textures_and_clock(storage->knights);
    destroy_text(storage->texts.title);
    destroy_text(storage->texts.howto);
    destroy_text(storage->texts.gameover);
    destroy_text(storage->texts.money);
    destroy_text(storage->texts.lostgolds);
    destroy_text(storage->texts.notenoughmoney);
    destroy_text(storage->texts.knights_killed);
    destroy_clocks(storage);
    destroy_audio(storage);
}