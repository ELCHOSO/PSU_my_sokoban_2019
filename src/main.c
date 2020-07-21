/*
** EPITECH PROJECT, 2019
** sokoban
** File description:
** main
*/

#include "header.h"

char **change_map(map_t maps, int line, int column)
{
    if (getch() == '\033') {
        getch();
        switch(getch()) {
        case 'A':
            move_up(line, column, maps.map, maps.cpy);
            break;
        case 'B':
            move_down(line, column, maps.map, maps.cpy);
            break;
        case 'C':
            move_right(line, column, maps.map, maps.cpy);
            break;
        case 'D':
            move_left(line, column, maps.map, maps.cpy);
            break;
        }
    }
    return (maps.map);
}

void print_map(char **map, int line, int column)
{
    move(0, 0);
    for (int y = 0; y != line; y++)
        printw("%.*s\n", column, map[y]);
}

void sokoban(map_t maps, lineco_t lc)
{
    print_map(maps.map, lc.line, lc.column);
    noecho();
    maps.map = change_map(maps, lc.line, lc.column);
}

char *map_error(int ac, char *file)
{
    char *map_str;

    if (ac != 2)
        return (NULL);
    map_str = get_map(file);
    if (map_str == NULL)
        return (NULL);

    return (map_str);
}

int main(int ac, char **av)
{
    map_t maps;
    char *map_str;
    lineco_t lc;

    map_str = map_error(ac, av[1]);
    if ((map_str == NULL))
        return (84);
    lc.line = get_line(map_str);
    lc.column = get_column(map_str);
    maps.map = put_map_in_tab(map_str, create_empty_tab(map_str));
    if (check_map(maps.map, lc) == 0)
        return (84);
    maps.cpy = cpy_original_map(lc.line, lc.column, maps.map);
    initscr();
    while (1) {
        sokoban(maps, lc);
        if (win(maps, lc.line, lc.column) == 0 || lose(maps, lc) == 1)
            break;
    }
    return (win(maps, lc.line, lc.column));
}