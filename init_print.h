#ifndef INIT_PRINT_H
#define INIT_PRINT_H
#include "enum.h"
void init(struct board Board[12][12]);
void print_mov(int mov[12][12]);
void print_board(struct board Board[12][12]);
void print_board_step(struct board Board[12][12], int move[12][12], int t, int r);
#endif // INIT_PRINT_H
