/*
** EPITECH PROJECT, 2020
** list
** File description:
** myrunner
*/
#include "../../include/my.h"
#include <stdlib.h>

static cell_t *create_cell(struct game_object data)
{
    cell_t *cell = malloc(sizeof(cell_t));
    if (!cell)
        return (NULL);
    cell->data = data;
    cell->next = NULL;
    return (cell);
}

int is_empty_list(list_t *list)
{
    return (list == NULL);
}

unsigned int len_list(list_t *list)
{
    long len = 0;
    while (list) {
        len++;
        list = list->next;
    }
    return (len);
}

list_t *add_at(list_t *list, struct game_object data, int pos)
{
    list_t *prec = list;
    list_t *cur = list;
    int i = 0;
    cell_t *cell = create_cell(data);

    if (!cell)
        return (NULL);
    if (is_empty_list(list))
        return (cell);
    if (pos == 0) {
        cell->next = list;
        return (cell);
    }
    while (i < pos) {
        i++;
        prec = cur;
        cur = cur->next;
    }
    prec->next = cell;
    cell->next = cur;
    return (list);
}