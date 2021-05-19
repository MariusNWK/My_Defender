/*
** EPITECH PROJECT, 2021
** create_text
** File description:
** create a text : font, position, size, string
*/

#include "include/my.h"

void apply_text_settings(struct game_text *title)
{
    sfText_setFont(title->text, title->font);
    sfText_setString(title->text, title->str);
    sfText_setPosition(title->text, title->pos);
    sfText_setCharacterSize(title->text, title->size);
}

struct game_text create_text(char const *path, sfVector2f pos,
unsigned int size, char const *str)
{
    struct game_text title;

    title.text = sfText_create();
    title.font = sfFont_createFromFile(path);
    title.pos = pos;
    title.size = size;
    title.str = str;
    apply_text_settings(&title);
    return (title);
}