/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** Function that displays the number given as a parameter.
** It's able to display all the possible
** values of an int, and must be prototype.
*/
#include "rpg.h"

static int power(int a, int b)
{
    int i = 0;
    int result = 1;

    for (; i < b; i++) {
        result *= a;
    }
    return (result);
}

static int digit_to_ascii(int dig)
{
    dig += 48;
    return (dig);
}

static int show_int(long num)
{
    long num2 = num;
    int num_o_d = 0;

    while (num != 0) {
        num = num / 10;
        num_o_d += 1;
    }
    for (; num_o_d != 0; num_o_d -= 1) {
        my_putchar(digit_to_ascii(num2 / power(10, (num_o_d - 1))));
        num2 -= (num2 / power(10, num_o_d - 1)) * power(10, num_o_d - 1);
    }
    return (num_o_d);
}

int my_put_nbr(int nb)
{
    long cp_nb = nb;

    if (cp_nb < 0) {
        my_putchar(45);
        cp_nb *= -1;
    }
    if (cp_nb == 0) {
        my_putchar(48);
    } else {
        show_int(cp_nb);
    }
    return (0);
}
