#include <stdio.h>
#include "move.h"
#include "turns.h"
#include "main_f.h"
#include "enum.h"
#include "init_print.h"
int move_white(struct board Board[12][12], int on)
{
	enum COLOR color = UNDEF;
	struct cell position;
	int n_from[2], n_to[2]; // are numbers;
	char from[3], to[3];
	int mov[12][12];
	printf("Ваш ход: ");
	scanf("%s", from);
	n_from[0] = from[0] - 'a' + 2;
	n_from[1] = from[1] - '1' + 2;
	position.r = n_from[1];
	position.c = n_from[0];
	color = Board[n_from[1]][n_from[0]].color;
	init_mov(mov);
	int i = n_from[1];
	int j = n_from[0];
	if(Board[i][j].figure == PAWN)
	{
		Pawn(Board, color, &position, mov);
	}
        if(Board[i][j].figure == ROOK)
        	Rook(Board, color, &position, mov);
    	if(Board[i][j].figure == KNIGHT)
        	Knight(Board, color, &position, mov);
        if(Board[i][j].figure == BISHOP)
        	Bishop(Board, color, &position, mov);
        if(Board[i][j].figure == QUEEN)
      	  	Queen(Board, color, &position, mov);
        if(Board[i][j].figure == KING)
        	King(Board, color, &position, mov);
	int t = i;
	int r = j;
	if(on == 1)
	{
		puts("Возможные ходы");
		print_board_step(Board, mov, t, r);
/*	for(i = 2; i < 10; i++)
	{
		for(j = 2; j < 10; j++)
		{
			if(i == n_from[1] && j == n_from[0])
			{
				printf("\e[41m");
				printf("[%d]", Board[i][j].figure);
				printf("\e[0m");
			}
			else if(mov[i][j] == 1)
			{
				printf("\e[46m");
				printf("[%d]", Board[i][j].figure);
				printf("\e[0m");
			}
			else
				printf("[%d]", Board[i][j].figure);
		}
		puts("");
	}*/
	}
	scanf("%s", to);
       	n_to[0] = to[0] - 'a' + 2;
	n_to[1] = to[1] - '1' + 2;
	if(mov[n_to[1]][n_to[0]] == 1)
      	{
		Board[n_to[1]][n_to[0]] = Board[n_from[1]][n_from[0]];
		Board[n_from[1]][n_from[0]].figure = EMPTY;
		Board[n_from[1]][n_from[0]].color = UNDEF;
		return 1;
	}
	else
	{
		puts("Вы не можете так ходить");
		return 0;
	}
	return 0;
}
