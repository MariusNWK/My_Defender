/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** return size of string
*/

unsigned int my_strlen(char *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        len++;
    }
    return (len);
}
