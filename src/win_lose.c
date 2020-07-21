/*
** EPITECH PROJECT, 2019
** sokoban
** File description:
** win or lose
*/

#include "header.h"

int o_count(char **map, int line, int column)
{
    int res = 0;
    int x = 0;

    for (int y = 0; y != line - 1; y++) {
        for (; x != column - 1; x++) {
            if (map[y][x] == 'O')
                res++;
        }
        x = 0;
    }
    return (res);
}

int x_count(char **map, int line, int column)
{
    int res = 0;
    int x = 0;

    for (int y = 0; y != line - 1; y++) {
        for (; x != column - 1; x++) {
            if (map[y][x] == 'X')
                res++;
        }
        x = 0;
    }
    return (res);
}

int win(map_t maps, int line, int column)
{
    int o_nbr = o_count(maps.cpy, line, column);
    int good = 0;
    int x = 0;

    for (int y = 0; y != line - 1; y++) {
        for (; x != column - 1; x++) {
            if (maps.map[y][x] == 'X' && maps.cpy[y][x] == 'O')
                good++;
            if (o_nbr == good)
                return (0);
        }
        x = 0;
    }
    return (1);
}

int lose(map_t maps, lineco_t lc)
{
    int x_nbr = x_count(maps.map, lc.line, lc.column);
    int dead_x = 0;
    int x = 0;

    for (int y = 0; y != lc.line - 1; y++) {
        for (; x != lc.column - 1; x++) {
            if (is_x_dead(maps.map, lc, y, x) == 1)
                dead_x++;
            if (dead_x == x_nbr)
                return (1);
        }
        x = 0;
    }
    return (0);
}
