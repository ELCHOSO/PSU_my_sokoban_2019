/*
** EPITECH PROJECT, 2019
** sokoban
** File description:
** fonction qui copie la map original
*/

#include "header.h"

char **cpy_original_map(int line, int column, char **map)
{
    int x = 0;
    char **cpy = malloc(sizeof(char *) * line);

    for (int i = 0; i != line; i++)
        cpy[i] = malloc(sizeof(char) * column);
    for (int y = 0; y != line; y++) {
        for (; x != column; x++) {
            cpy[y][x] = map[y][x];
        }
        x = 0;
    }
    return (cpy);
}
