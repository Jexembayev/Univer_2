#ifndef MAIN_F_H
#define MAIN_F_H
#include "enum.h"
void make_move(struct board Board[12][12], struct cell from, struct cell to);
void make_move_f(struct board Board[12][12], struct cell from, struct cell to, enum FIGURE figure, enum COLOR color);
void remake_move(struct board Board[12][12], struct cell from, struct cell to, enum FIGURE figure, enum COLOR color);
void init_mov(int mov[12][12]);
struct best_move black(struct board Board[12][12], int level, int max);
struct best_move white(struct board Board[12][12], int level, int max);
#endif // MAIN_F_H
