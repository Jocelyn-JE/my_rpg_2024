/*
** EPITECH PROJECT, 2023
** mini_printf.c
** File description:
** Partially recreates the printf function
*/
#include "rpg.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdbool.h>

static void show_char(va_list args)
{
    char x = 0;

    x = va_arg(args, int);
    my_putchar(x);
    return;
}

static void show_string(va_list args)
{
    my_putstr(va_arg(args, char *));
    return;
}

static void show_nbr(va_list args)
{
    my_put_nbr(va_arg(args, int));
    return;
}

static int count_flags(const char *str)
{
    int result = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if ((str[i] == '%')
            && (str[i + 1] == 'd'
                || str[i + 1] == 'i'
                || str[i + 1] == 's'
                || str[i + 1] == 'c'
                || str[i + 1] == '%')) {
            result++;
            i++;
        }
    }
    return (result);
}

static void my_putdata(int i, const char *str, va_list args)
{
    switch (str[i]) {
    case '%':
        my_putchar('%');
        break;
    case 'c':
        show_char(args);
        break;
    case 's':
        show_string(args);
        break;
    case 'd':
        show_nbr(args);
        break;
    case 'i':
        show_nbr(args);
        break;
    default:
        break;
    }
    return;
}

static void my_putformat(const char *str, va_list args)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == '%') {
            i++;
            my_putdata(i, str, args);
        } else {
            my_putchar(str[i]);
        }
    }
    return;
}

int mini_printf(const char *format, ...)
{
    int num_args = count_flags(format);
    va_list args;

    va_start(args, format);
    if (num_args == 0) {
        my_putstr(format);
        return (0);
    } else {
        my_putformat(format, args);
    }
    va_end(args);
    return (0);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (!(*(str + i) == '\0'))
        i += 1;
    return (i);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (!(*(str + i) == '\0')) {
        my_putchar(*(str + i));
        i += 1;
    }
    return (0);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}
