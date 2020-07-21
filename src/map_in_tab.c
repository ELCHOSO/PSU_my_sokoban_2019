/*
** EPITECH PROJECT, 2019
** sokoban
** File description:
** mets la map dans un char **
*/

#include "header.h"

int get_column(char *str)
{
    int i = 0;
    int tmp = 0;
    int res = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n' && res < tmp)
            res = tmp - 1;
        if (str[i] == '\n')
            tmp = 0;
        tmp++;
        i++;
    }
    return (res + 1);
}

int get_line(char *str)
{
    int i = 0;
    int line = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            line++;
        i++;
    }
    return (line);
}

char *get_map(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat st;
    char *buffer;
    int rd;

    if (stat(filepath, &st) != 0)
        return (NULL);
    buffer = malloc(sizeof(char) * st.st_size + 1);
    rd = read(fd, buffer, st.st_size);
    if (rd != st.st_size)
        return NULL;
    buffer[st.st_size] = '\0';
    return (buffer);
}

char **create_empty_tab(char *str)
{
    int column = get_column(str);
    int line = get_line(str);
    char **map = malloc(sizeof(char *) * (line + 1));
    int x = 0;

    for (int i = 0; i != line; i++)
        map[i] = malloc(sizeof(char) * (column + 1));
    for (int y = 0; y != line; y++) {
        for (; x != column; x++) {
            map[y][x] = ' ';
        }
        map[y][x] = 0;
        x = 0;
    }
    map[line] = NULL;
    return (map);
}

char **put_map_in_tab(char *str, char **tab)
{
    int x = 0;
    int i = 0;
    int y = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n') {
            i++;
            x = 0;
            y++;
        }
        if (str[i] == 0)
            break;
        tab[y][x] = str[i];
        i++;
        x++;
    }
    return (tab);
}
