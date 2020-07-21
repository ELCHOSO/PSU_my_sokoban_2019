/*
** EPITECH PROJECT, 2019
** sokoban
** File description:
** move player fonctions
*/

#include "header.h"

p_position_t get_player_position(int line, int column, char ** map)
{
    p_position_t player;
    int x = 0;
    int y = 0;

    for (; y != line - 1; y++) {
        for (; x != column - 1; x++) {
            if (map[y][x] == 'P') {
                player.x = x;
                player.y = y;
                return (player);
            }
        }
        x = 0;
    }
}

void move_up(int line, int column, char **m, char **cpy)
{
    p_position_t player = get_player_position(line, column, m);
    int x = player.x;
    int y = player.y;

    if (y > 0) {
        if (m[y - 1][x] == 'X' && (m[y - 2][x] == ' ' || m[y - 2][x] == 'O')) {
            m[y][x] = ' ';
            m[y - 1][x] = 'P';
            m[y - 2][x] = 'X';
        }
        if (m[y - 1][x] == ' ' || m[y - 1][x] == 'O') {
            m[y][x] = ' ';
            m[y - 1][x] = 'P';
        }
        if (cpy[y][x] == 'O' && m[y][x] != 'P')
            m[y][x] = 'O';
    }
}

void move_down(int line, int column, char **m, char **cpy)
{
    p_position_t player = get_player_position(line, column, m);
    int x = player.x;
    int y = player.y;

    if (y < line) {
        if (m[y + 1][x] == 'X' && (m[y + 2][x] == ' ' || m[y + 2][x] == 'O')) {
            m[y][x] = ' ';
            m[y + 1][x] = 'P';
            m[y + 2][x] = 'X';
        }
        if (m[y + 1][x] == ' ' || m[y + 1][x] == 'O') {
            m[y][x] = ' ';
            m[y + 1][x] = 'P';
        }
        if (cpy[y][x] == 'O' && m[y][x] != 'P')
            m[y][x] = 'O';
    }
}

void move_left(int line, int column, char **m, char **cpy)
{
    p_position_t player = get_player_position(line, column, m);
    int x = player.x;
    int y = player.y;

    if (x > 0) {
        if (m[y][x - 1] == 'X' && (m[y][x - 2] == ' ' || m[y][x - 2] == 'O')) {
            m[y][x] = ' ';
            m[y][x - 1] = 'P';
            m[y][x - 2] = 'X';
        }
        if (m[y][x - 1] == ' ' || m[y][x - 1] == 'O') {
            m[y][x] = ' ';
            m[y][x - 1] = 'P';
        }
        if (cpy[y][x] == 'O' && m[y][x] != 'P')
            m[y][x] = 'O';
    }
}

void move_right(int line, int column, char **m, char **cpy)
{
    p_position_t player = get_player_position(line, column, m);
    int x = player.x;
    int y = player.y;

    if (x < column) {
        if (m[y][x + 1] == 'X' && (m[y][x + 2] == ' ' || m[y][x + 2] == 'O')) {
            m[y][x] = ' ';
            m[y][x + 1] = 'P';
            m[y][x + 2] = 'X';
        }
        if (m[y][x + 1] == ' ' || m[y][x + 1] == 'O') {
            m[y][x] = ' ';
            m[y][x + 1] = 'P';
        }
        if (cpy[y][x] == 'O' && m[y][x] != 'P')
            m[y][x] = 'O';
    }
}
