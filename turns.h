#ifndef TURNS_H
#define TURNS_H
#include "enum.h"
struct Move
{
	int r, c;
};
void Pawn(struct board Board[12][12], enum COLOR color, struct cell *from, int mov[12][12]);
void Rook(struct board Board[12][12], enum COLOR color, struct cell *from, int mov[12][12]);
void Knight(struct board Board[12][12], enum COLOR color, struct cell *from, int mov[12][12]);
void Bishop(struct board Board[12][12], enum COLOR color, struct cell *from, int mov[12][12]);
void Queen(struct board Board[12][12], enum COLOR color, struct cell *from, int mov[12][12]);
void King(struct board Board[12][12], enum COLOR color, struct cell *from, int mov[12][12]);
#endif // TURNS_H
