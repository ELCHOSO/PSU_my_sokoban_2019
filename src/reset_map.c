/*
** EPITECH PROJECT, 2019
** sokoban
** File description:
** reset map
*/

#include "header.h"

char **reset_map(map_t maps, int line, int column)
{
    int x = 0;

    for (int y = 0; y != line; y++) {
        for (; x != column; x++)
            maps.map[y][x] = maps.cpy[y][x];
        x = 0;
    }
}
