/*
** EPITECH PROJECT, 2021
** int_to_str
** File description:
** convert an int into his string form
*/

#include "../../include/my.h"

unsigned int count_figures_nbr(unsigned int nbr)
{
    unsigned int figures_nbr = 0;

    if (nbr == 0) {
        return (1);
    }
    while (nbr > 0) {
        nbr /= 10;
        figures_nbr++;
    }
    return (figures_nbr);
}

unsigned int define_divider(unsigned int len)
{
    unsigned int div = 1;

    for (int i = 1; i < len; i++) {
        div *= 10;
    }
    return (div);
}

char *error_uint_to_str(void)
{
    char *str = malloc(sizeof(char) * 2);

    str[0] = 0;
    str[1] = '\0';
    return (str);
}

char *uint_to_str(unsigned int nbr)
{
    unsigned int len = count_figures_nbr(nbr);
    unsigned int div = define_divider(len);
    char *str = malloc(sizeof(char) * (len + 1));

    if (!str) {
        return (error_uint_to_str());
    }
    for (int i = 0; i < len; i++) {
        str[i] = nbr / div + 48;
        nbr %= div;
        div /= 10;
    }
    str[len] = '\0';
    return (str);
}