#include <stdio.h>
#include "turns.h"
#include "enum.h"
void Pawn(struct board Board[12][12], enum COLOR color, struct cell *position, int Move[12][12])
{
	int m, STEP, SPECIAL_LINE;
	enum COLOR ENEMY;
	if(color == WHITE)
	{
		STEP = 1;
		ENEMY = BLACK;
		m = 1;
		SPECIAL_LINE = 3;
	}
	else
	{
		STEP = -1;
		ENEMY = WHITE;
		m = -1;
		SPECIAL_LINE = 8;
	}
	if(Board[position -> r + STEP][position -> c].figure == EMPTY)
	{ 
		if(Board[position -> r + STEP][position -> c + STEP].figure != EMPTY && Board[position -> r + STEP][position -> c - STEP].figure != EMPTY &&
				Board[position -> r + STEP][position -> c + STEP].color == ENEMY && Board[position -> r + STEP][position -> c - STEP].color == ENEMY)
		{
			if(position -> r == SPECIAL_LINE)
			{
				if(Board[position -> r + 2 * STEP][position -> c].figure == EMPTY)
				{
					Move[position -> r + m][position -> c] = 1;
					Move[position -> r + 2 * m][position -> c] = 1;
					Move[position -> r + m][position -> c + m] = 1;
					Move[position -> r + m][position -> c - m] = 1;
				}
				else
				{
					Move[position -> r + m][position -> c] = 1;
					Move[position -> r + m][position -> c + m] = 1;
					Move[position -> r + m][position -> c - m] = 1;
				}
			}
			else
			{
					Move[position -> r + m][position -> c] = 1;
					Move[position -> r + m][position -> c + m] = 1;
					Move[position -> r + m][position -> c - m] = 1;
			}
		}
		else if(Board[position -> r + STEP][position -> c + STEP].figure != EMPTY && Board[position -> r + STEP][position -> c + STEP].color == ENEMY)
		{
			if(position -> r == SPECIAL_LINE)
			{
				if(Board[position -> r + 2 * STEP][position -> c].figure == EMPTY)
				{
					Move[position -> r + m][position -> c] = 1;
					Move[position -> r + 2 * m][position -> c] = 1;
					Move[position -> r + m][position -> c + m] = 1;
				}
				else
				{
					Move[position -> r + m][position -> c] = 1;
					Move[position -> r + m][position -> c + m] = 1;
				}
			}
			else
			{
					Move[position -> r + m][position -> c] = 1;
					Move[position -> r + m][position -> c + m] = 1;
			}

		} 
		else if(Board[position -> r + STEP][position -> c - STEP].figure != EMPTY && Board[position -> r + STEP][position -> c - STEP].color == ENEMY)
		{
			if(position -> r == SPECIAL_LINE)
			{
				if(Board[position -> r + 2 * STEP][position -> c].figure == EMPTY)
				{
					Move[position -> r + m][position -> c] = 1;
					Move[position -> r + 2 * m][position -> c] = 1;
					Move[position -> r + m][position -> c - m] = 1;
				}
				else
				{
					Move[position -> r + m][position -> c] = 1;
					Move[position -> r + m][position -> c - m] = 1;
				}
			}
			else
			{	
					Move[position -> r + m][position -> c] = 1;
					Move[position -> r + m][position -> c - m] = 1;
			}

		}
		else
		{
			if(position -> r == SPECIAL_LINE)
			{
				if(Board[position -> r + 2 * STEP][position -> c].figure == EMPTY)
				{
					Move[position -> r + m][position -> c] = 1;
					Move[position -> r + 2 * m][position -> c] = 1;
				}
				else
				{
					Move[position -> r + m][position -> c] = 1;
				}
			}
			else
			{
					Move[position -> r + m][position -> c] = 1;
			}

		} 
	}
	else
	{
		if(Board[position -> r + STEP][position -> c + STEP].figure != EMPTY && Board[position -> r + STEP][position -> c - STEP].figure != EMPTY &&
				Board[position -> r + STEP][position -> c + STEP].color == ENEMY && Board[position -> r + STEP][position -> c - STEP].color == ENEMY)
		{
					Move[position -> r + m][position -> c - m] = 1;
					Move[position -> r + m][position -> c + m] = 1;
		}
		else if(Board[position -> r + STEP][position -> c + STEP].figure != EMPTY && Board[position -> r + STEP][position -> c + STEP].color == ENEMY)
		{
					Move[position -> r + m][position -> c + m] = 1;
		} 
		else if(Board[position -> r + STEP][position -> c - STEP].figure != EMPTY && Board[position -> r + STEP][position -> c - STEP].color == ENEMY)
		{
					Move[position -> r + m][position -> c - m] = 1;
		}
	}
	Move[position -> r][position -> c] = 0;
}
void Rook(struct board Board[12][12], enum COLOR color, struct cell *position, int Move[12][12]) 
{
	enum COLOR ENEMY;
	if(color == WHITE)
		ENEMY = BLACK;
	else
		ENEMY = WHITE;
	int j = 1;
	while(Board[position -> r][position -> c + j].figure == EMPTY) 
	{
		Move[position -> r][position -> c + j] = 1;
		j++;
	}
	if(Board[position -> r][position -> c + j].color == ENEMY)
		Move[position -> r][position -> c + j] = 1;
	j = 1;

	while(Board[position -> r][position -> c - j].figure == EMPTY)
	{
		Move[position -> r][position -> c - j] = 1;
		j++;
	}
	if(Board[position -> r][position -> c - j].color == ENEMY)
		Move[position -> r][position -> c - j] = 1;
	j = 1;

	while(Board[position -> r + j][position -> c].figure == EMPTY) // вверх
	{
		Move[position -> r + j][position -> c] = 1;
		j++;
	}
	if(Board[position -> r + j][position -> c].color == ENEMY)
		Move[position -> r + j][position -> c] = 1;
	j = 1;

	while(Board[position -> r - j][position -> c].figure == EMPTY) //вниз
	{
		Move[position -> r - j][position -> c] = 1;
		j++;
	}
	if(Board[position -> r - j][position -> c].color == ENEMY)
		Move[position -> r - j][position -> c] = 1;
	Move[position -> r][position -> c] = 0;
}
void Bishop(struct board Board[12][12], enum COLOR color, struct cell *position, int Move[12][12]) 
{
	enum COLOR ENEMY;
	if(color == WHITE)
		ENEMY = BLACK;
	else
		ENEMY = WHITE;
	int j = 1;
	while(Board[position -> r + j][position -> c + j].figure == EMPTY) // 45 градусов
	{
		Move[position -> r + j][position -> c + j] = 1;
		j++;
	}
	if(Board[position -> r + j][position -> c + j].color == ENEMY)
		Move[position -> r + j][position -> c + j] = 1;
	j = 1;

	while(Board[position -> r + j][position -> c - j].figure == EMPTY) // - 45 градусов
	{
		Move[position -> r + j][position -> c - j] = 1;
		j++;
	}
	if(Board[position -> r + j][position -> c - j].color == ENEMY)
		Move[position -> r + j][position -> c - j] = 1;
	j = 1;

	while(Board[position -> r - j][position -> c + j].figure == EMPTY) // 135 градусов
	{
		Move[position -> r - j][position -> c + j] = 1;
		j++;
	}
	if(Board[position -> r - j][position -> c + j].color == ENEMY)
		Move[position -> r - j][position -> c + j] = 1;
	j = 1;

	while(Board[position -> r - j][position -> c - j].figure == EMPTY) // -135 градусов
	{
		Move[position -> r - j][position -> c - j] = 1;
		j++;
	}
	if(Board[position -> r - j][position -> c - j].color == ENEMY)
		Move[position -> r - j][position -> c - j] = 1;
	j = 1;
	Move[position -> r][position -> c] = 0;
}
void Queen(struct board Board[12][12], enum COLOR color, struct cell *position, int Move[12][12]) 
{
	Rook(Board, color, position, Move); 
	Bishop(Board, color, position, Move); 
}
void King(struct board Board[12][12], enum COLOR color, struct cell *from, int mov[12][12])
{
	struct cell shift[8] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}, to;
	int i;
	for(i = 0; i < 8; i++)
	{
		to = *from;
		to.r += shift[i].r;
		to.c += shift[i].c;
		if(Board[to.r][to.c].figure == EMPTY || Board[to.r][to.c].color != color)
			mov[to.r][to.c] = 1;
	}
	mov[from -> r][from -> c] = 0;
}
void Knight(struct board Board[12][12], enum COLOR color, struct cell *from, int mov[12][12])
{
	struct cell shift[8] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}}, to;
	int i;
	for(i = 0; i < 8; i++)
	{
		to = *from;
		to.r += shift[i].r;
		to.c += shift[i].c;
		if(Board[to.r][to.c].figure == EMPTY || Board[to.r][to.c].color != color)
			mov[to.r][to.c] = 1;
	}
	mov[from -> r][from -> c] = 0;
}
