/*
** EPITECH PROJECT, 2019
** sokoban
** File description:
** is X movable ?
*/

#include "header.h"

int up_blocked(char **map, lineco_t lc, int y, int x)
{
    if (map[y][x] == 'X') {
        if (y == 0)
            return (1);
        if (map[y - 1][x] == 'X' || map[y - 1][x] == '#')
            return (1);
    }
    return (0);
}

int down_blocked(char **map, lineco_t lc, int y, int x)
{
    if (map[y][x] == 'X') {
        if (map[y + 1][x] == 'X' || map[y + 1][x] == '#' || y == lc.line - 1)
            return (1);
    }
    return (0);
}

int left_blocked(char **map, lineco_t lc, int y, int x)
{
    if (map[y][x] == 'X') {
        if (map[y][x - 1] == 'X' || map[y][x - 1] == '#' || x == 0)
            return (1);
    }
    return (0);
}

int right_blocked(char **map, lineco_t lc, int y, int x)
{
    if (map[y][x] == 'X') {
        if (map[y][x + 1] == 'X' || map[y][x + 1] == '#' || x == lc.column - 1)
            return (1);
    }
    return (0);
}

int is_x_dead(char **map, lineco_t lc, int y, int x)
{
    if (up_blocked(map, lc, y, x) == 1 && left_blocked(map, lc, y , x) == 1)
        return (1);
    if (up_blocked(map, lc, y, x) == 1 && right_blocked(map, lc, y , x) == 1)
        return (1);
    if (down_blocked(map, lc, y, x) == 1 && left_blocked(map, lc, y , x) == 1)
        return (1);
    if (down_blocked(map, lc, y, x) == 1 && right_blocked(map, lc, y , x) == 1)
        return (1);
    return (0);
}