/*
** EPITECH PROJECT, 2023
** strcmp
** File description:
** returns an integer indicating the result of the comparison, as follows:
** => 0, if the s1 and s2 are equal;
** => a negative value if s1 is less than s2;
** => a positive value if s1 is greater than s2.
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
        i += 1;
    }
    return 0;
}
