/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** header
*/

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>

typedef struct p_position
{
    int x;
    int y;
}p_position_t;

typedef struct map
{
    char **map;
    char **cpy;
}map_t;

typedef struct lineco
{
    int line;
    int column;
}lineco_t;

typedef struct chars
{
    int x;
    int o;
    int p;
}chars_t;

int get_column(char *);
int get_line(char *);
char *get_map(char const *);
char **create_empty_tab(char *str);
char **put_map_in_tab(char *, char **);
void move_up(int, int, char **, char **);
void move_down(int, int, char **, char **);
void move_left(int, int, char **, char **);
void move_right(int, int, char **, char **);
char **cpy_original_map(int, int, char **);
int up_blocked(char **map, lineco_t, int y, int x);
int down_blocked(char **map, lineco_t, int y, int x);
int left_blocked(char **map, lineco_t, int y, int x);
int right_blocked(char **map, lineco_t, int y, int x);
int is_x_dead(char **map, lineco_t, int y, int x);
int o_count(char **map, int line, int column);
int x_count(char **map, int line, int column);
int win(map_t maps, int line, int column);
int lose(map_t maps, lineco_t lc);
char **reset_map(map_t maps, int, int);
int not_openable(char const *);
int map_valid(char *);
int check_map(char **map, lineco_t lc);