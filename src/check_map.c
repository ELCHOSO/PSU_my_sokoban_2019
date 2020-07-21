/*
** EPITECH PROJECT, 2020
** sokoban
** File description:
** check map
*/

#include "header.h"

chars_t check_chars(chars_t ct, char c)
{
    if (c == 'P')
        ct.p++;
    if (c == 'O')
        ct.o++;
    if (c == 'X')
        ct.x++;
    return (ct);
}

int check_map(char **map, lineco_t lc)
{
    int x = 0;
    chars_t ct = {0, 0, 0};

    for (int y = 0; y != lc.line; y++) {
        for (; x != lc.column; x++) {
            if (map[y][x] != ' ' && map[y][x] != 'P'
            && map[y][x] != '#' && map[y][x] != 'O' && map[y][x] != 'X')
                return (0);
            ct = check_chars(ct, map[y][x]);
        }
        x = 0;
    }
    if (ct.p != 1)
        return (0);
    if (ct.o != ct.x)
        return (0);
    return (1);
}