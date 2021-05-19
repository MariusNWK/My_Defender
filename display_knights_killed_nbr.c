/*
** EPITECH PROJECT, 2021
** display knights killed nbr
** File description:
** display the number of knights killed
*/

#include "include/my.h"

void display_knights_killed_nbr(sfRenderWindow *window, storage_t *st)
{
    char *nbr = uint_to_str(st->knights_killed);

    sfText_setString(st->texts.knights_killed.text, nbr);
    sfRenderWindow_drawText(window, st->texts.knights_killed.text, NULL);
    free(nbr);
}