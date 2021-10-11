#include <stdio.h>
#include "sum.h"
int mark(struct board Board[12][12], enum COLOR OURS)
{
	int ours = 0, i, j;
	for(i = 2; i < 10; i++)
	{
		for(j = 2; j < 10; j++)
		{
			if(Board[i][j].figure == PAWN && Board[i][j].color == OURS)
				ours += 1;
			else if((Board[i][j].figure == KNIGHT || Board[i][j].figure == BISHOP) && Board[i][j].color == OURS)
				ours += 3;
			else if(Board[i][j].figure == ROOK && Board[i][j].color == OURS)
				ours += 5;
			else if(Board[i][j].figure == QUEEN && Board[i][j].color == OURS)
				ours += 9;
			else if(Board[i][j].figure == KING && Board[i][j].color == OURS)
				ours += 10000;
		}
	}
	return ours;
}
