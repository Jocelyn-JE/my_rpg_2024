/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-jocelyn.jean-elie
** File description:
** clamp
*/

double clamp(double d, double min, double max)
{
    const double t = d < min ? min : d;

    return t > max ? max : t;
}
