#include "init_print.h"
#include "enum.h"
#include <stdio.h>
#include <stdlib.h>
#define RED  printf("\e[36m")
#define BLUE printf("\e[32m")
#define END  printf("\e[0m")
#define BLUE_B printf("\e[31m")
#define BLINK printf("\e[35m")
#define PRINT printf("[%c]", figure)
void init(struct board Board[12][12])
{
	int i, j;
	Board[2][2].figure = ROOK;
	Board[2][3].figure = KNIGHT;
	Board[2][4].figure = BISHOP;
	Board[2][5].figure = KING;
	Board[2][6].figure = QUEEN;
	Board[2][7].figure = BISHOP;
	Board[2][8].figure = KNIGHT;
	Board[2][9].figure = ROOK;
	Board[3][2].figure = PAWN;
	Board[3][3].figure = PAWN;
	Board[3][4].figure = PAWN;
	Board[3][5].figure = PAWN;
	Board[3][6].figure = PAWN;
	Board[3][7].figure = PAWN;
	Board[3][8].figure = PAWN;
	Board[3][9].figure = PAWN;
	Board[8][2].figure = PAWN;
	Board[8][3].figure = PAWN;
	Board[8][4].figure = PAWN;
	Board[8][5].figure = PAWN;
	Board[8][6].figure = PAWN;
	Board[8][7].figure = PAWN;
	Board[8][8].figure = PAWN;
	Board[8][9].figure = PAWN;
	Board[9][2].figure = ROOK;
	Board[9][3].figure = KNIGHT;
	Board[9][4].figure = BISHOP;
	Board[9][5].figure = KING;
	Board[9][6].figure = QUEEN;
	Board[9][7].figure = BISHOP;
	Board[9][8].figure = KNIGHT;
	Board[9][9].figure = ROOK;
	for(i = 4; i <= 7; i++)
		for(j = 2; j <= 9; j++)
		{
			Board[i][j].figure = EMPTY;
			Board[i][j].color = UNDEF;
		}
	for(i = 2; i <= 9; i++)
	{
		Board[2][i].color = WHITE;
		Board[3][i].color = WHITE;
		Board[8][i].color = BLACK;
		Board[9][i].color = BLACK;
	}
	for(i = 0; i < 2; i++)
		for(j = 0; j < 12; j++)
		{
			Board[i][j].figure = Board[11 - i][j].figure = WALL;
			Board[i][j].color = Board[11 - i][j].color = UNDEF;
			Board[j][i].figure = Board[11 - j][i].figure = WALL;
			Board[j][i].color = Board[11 - j][i].color = UNDEF;
		}
/*	for(i = 2; i <= 9; i++)
	{
		Board[0][i].figure = Board[1][i].figure = Board[11][i].figure = Board[10][i].figure = WALL;
		Board[0][i].color = Board[1][i].color = Board[11][i].color = Board[10][i].color = UNDEF;
	}*/
}
void print_mov(int mov[12][12])
{
	int i, j;
	for(i = 0; i < 12; i++)
	{
		printf("\t\t\t\t\t\t");
		printf("%d\t", i);
		for(j = 0; j < 12; j++)
			printf("[%2d]", mov[i][j]);
		putchar('\n');
	}
}
void print_board(struct board Board[12][12])
{
	char figure;
	int i, j;
	puts("-------------------------------------------------------------------");
	printf("\n\t\t\t");
	for(i = 0; i < 8; i++)
		printf(" %c ", 'a' + i);
	printf("\n\n");
	for(i = 2; i < 10; i++)
	{
		printf("\t\t");
		printf("%d\t", i - 1);
		for(j = 2; j < 10; j++)
		{
			if(Board[i][j].color == WHITE)
			{
				if(Board[i][j].figure == PAWN)
				{
					figure = 'P';
					RED;
					PRINT;
					END;
				}
				else if(Board[i][j].figure == ROOK)
				{
					figure = 'R';
					RED;
					PRINT;
					END;
				}
				else if(Board[i][j].figure == KNIGHT)
				{
					figure = 'N';
					RED;
					PRINT;
					END;
				}
				else if(Board[i][j].figure == BISHOP)
				{
					figure = 'B';
					RED;
					PRINT;
					END;
				}
				else if(Board[i][j].figure == QUEEN)
				{
					figure = 'Q';
					RED;
					PRINT;
					END;
				}
				else if(Board[i][j].figure == KING)
				{
					figure = 'K';
					RED;
					PRINT;
					END;
				}
			}
			else if(Board[i][j].color == BLACK)
			{
				if(Board[i][j].figure == PAWN)
				{
					figure = 'P';
					BLUE;
					PRINT;
					END;
				}
				else if(Board[i][j].figure == ROOK)
				{
					figure = 'R';
					BLUE;
					PRINT;
					END;
				}
				else if(Board[i][j].figure == KNIGHT)
				{
					figure = 'N';
					BLUE;
					PRINT;
					END;
				}
				else if(Board[i][j].figure == BISHOP)
				{
					figure = 'B';
					BLUE;
					PRINT;
					END;
				}
				else if(Board[i][j].figure == QUEEN)
				{
					figure = 'Q';
					BLUE;
					PRINT;
					END;
				}
				else if(Board[i][j].figure == KING)
				{
					figure = 'K';
					BLUE;
					PRINT;
					END;
				}
			}
			else if(Board[i][j].color == UNDEF)
			{
				if(Board[i][j].figure == EMPTY)
				{
					figure = ' ';
					PRINT;
				}
				else if(Board[i][j].figure == WALL)
				{
					figure = 'X';
					PRINT;
				}
			}
		}
		putchar('\n');
	}
	printf("\n\n");
	puts("-------------------------------------------------------------------");
	
}
void print_board_step(struct board Board[12][12], int mov[12][12], int t, int r)
{
	char figure;
	int i, j;
	puts("-------------------------------------------------------------------");
	printf("\n\t\t\t");
	for(i = 0; i < 8; i++)
		printf(" %c ", 'a' + i);
	printf("\n\n");
	for(i = 2; i < 10; i++)
	{
		printf("\t\t");
		printf("%d\t", i - 1);
		for(j = 2; j < 10; j++)
		{
			if(Board[i][j].color == WHITE)
			{
				if(Board[i][j].figure == PAWN)
				{
					figure = 'P';
					RED;
					if(mov[i][j] == 1)
					{
						BLUE_B;
					}
					if(i == t && j == r)
					{
						BLINK;
					}

					PRINT;
					END;
				}
				else if(Board[i][j].figure == ROOK)
				{
					figure = 'R';
					RED;
					if(mov[i][j] == 1)
					{
						BLUE_B;
					}

					if(i == t && j == r)
					{
						BLINK;
					}

					PRINT;
					END;
				}
				else if(Board[i][j].figure == KNIGHT)
				{
					figure = 'N';
					RED;
					if(mov[i][j] == 1)
					{
						BLUE_B;
					}

					if(i == t && j == r)
					{
						BLINK;
					}

					PRINT;
					END;
				}
				else if(Board[i][j].figure == BISHOP)
				{
					figure = 'B';
					RED;
					if(mov[i][j] == 1)
					{
						BLUE_B;
					}

					if(i == t && j == r)
					{
						BLINK;
					}

					PRINT;
					END;
				}
				else if(Board[i][j].figure == QUEEN)
				{
					figure = 'Q';
					RED;
					if(mov[i][j] == 1)
					{
						BLUE_B;
					}

					if(i == t && j == r)
					{
						BLINK;
					}

					PRINT;
					END;
				}
				else if(Board[i][j].figure == KING)
				{
					figure = 'K';
					RED;
					if(mov[i][j] == 1)
					{
						BLUE_B;
					}

					if(i == t && j == r)
					{
						BLINK;
					}

					PRINT;
					END;
				}
			}
			else if(Board[i][j].color == BLACK)
			{
				if(Board[i][j].figure == PAWN)
				{
					figure = 'P';
					BLUE;
					if(mov[i][j] == 1)
					{
						BLUE_B;
					}
					if(i == t && j == r)
					{
						BLINK;
					}
					PRINT;
					END;
				}
				else if(Board[i][j].figure == ROOK)
				{
					figure = 'R';
					BLUE;
					if(mov[i][j] == 1)
					{
						BLUE_B;
					}
					if(i == t && j == r)
					{
						BLINK;
					}

					PRINT;
					END;
				}
				else if(Board[i][j].figure == KNIGHT)
				{
					figure = 'N';
					BLUE;
					if(mov[i][j] == 1)
					{
						BLUE_B;
					}
					if(i == t && j == r)
					{
						BLINK;
					}

					PRINT;
					END;
				}
				else if(Board[i][j].figure == BISHOP)
				{
					figure = 'B';
					BLUE;
					if(mov[i][j] == 1)
					{
						BLUE_B;
					}
					if(i == t && j == r)
					{
						BLINK;
					}

					PRINT;
					END;
				}
				else if(Board[i][j].figure == QUEEN)
				{
					figure = 'Q';
					BLUE;
					if(mov[i][j] == 1)
					{
						BLUE_B;
					}
					if(i == t && j == r)
					{
						BLINK;
					}

					PRINT;
					END;
				}
				else if(Board[i][j].figure == KING)
				{
					figure = 'K';
					BLUE;
					if(mov[i][j] == 1)
					{
						BLUE_B;
					}
					if(i == t && j == r)
					{
						BLINK;
					}

					PRINT;
					END;
				}
			}
			else if(Board[i][j].color == UNDEF)
			{
				if(Board[i][j].figure == EMPTY)
				{
					figure = ' ';
					if(mov[i][j] == 1)
						BLUE_B;
					PRINT;
					END;
				}
				else if(Board[i][j].figure == WALL)
				{
					figure = 'X';
					PRINT;
				}
			}
			END;
		}
		putchar('\n');
	}
	printf("\n\n");
	puts("-------------------------------------------------------------------");
	
}
