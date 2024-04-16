/*
** EPITECH PROJECT, 2023
** Int to string
** File description:
** Converts an int to a string
*/
#include "rpg.h"

static int pwr(int nb, int p)
{
    if (p == 0) {
        return (1);
    } else if (p < 0) {
        return (0);
    } else {
        nb *= pwr(nb, p - 1);
        return (nb);
    }
}

static int my_nbrlen(int nb)
{
    int result = 0;

    if (nb == 0) {
        return (1);
    }
    for (; nb != 0; nb /= 10)
        result++;
    return (result);
}

char *my_itoa(int nb)
{
    int len_nbr = my_nbrlen(nb);
    char *str;
    int i = 0;

    if (nb < 0) {
        str = malloc(sizeof(char) * (len_nbr + 2));
        str[0] = '-';
        i++;
        len_nbr++;
        nb *= -1;
    } else {
        str = malloc(sizeof(char) * (len_nbr + 1));
    }
    for (; i < len_nbr; i++) {
        str[i] = (nb / pwr(10, len_nbr - i - 1)) + '0';
        nb -= (nb / pwr(10, len_nbr - i - 1)) * pwr(10, len_nbr - (i + 1));
    }
    str[i] = '\0';
    return (str);
}
