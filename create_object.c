/*
** EPITECH PROJECT, 2021
** create_object
** File description:
** create sprite defining texture, position, scale, rect
*/

#include "include/my.h"

void apply_settings(struct game_object *obj)
{
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setPosition(obj->sprite, obj->pos);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfSprite_setScale(obj->sprite, obj->scale);
}

struct game_object create_object (const char *path_to_spritesheet,
sfVector2f pos, sfIntRect rect, sfVector2f scale)
{
    struct game_object obj;

    obj.texture = sfTexture_createFromFile(path_to_spritesheet, NULL);
    obj.pos = pos;
    obj.rect = rect;
    obj.scale = scale;
    obj.sprite = sfSprite_create();
    apply_settings(&obj);
    return (obj);
}