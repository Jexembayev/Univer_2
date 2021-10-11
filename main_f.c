#include <stdio.h>
#include "turns.h"
#include "init_print.h"
#include "sum.h"
struct best_move white(struct board Board[12][12], int level, int max);
void make_move(struct board Board[12][12], struct cell from, struct cell to)
{
	Board[to.r][to.c] = Board[from.r][from.c];
	Board[from.r][from.c].figure = EMPTY;
	Board[from.r][from.c].color = UNDEF;
}
void make_move_f(struct board Board[12][12], struct cell from, struct cell to, enum FIGURE *figure, enum COLOR *color)
{
	*figure = Board[to.r][to.c].figure;
	*color = Board[to.r][to.c].color;
	Board[to.r][to.c] = Board[from.r][from.c];
	Board[from.r][from.c].figure = EMPTY;
	Board[from.r][from.c].color = UNDEF;
}
void remake_move(struct board Board[12][12], struct cell from, struct cell to, enum FIGURE *figure, enum COLOR *color)
{
	Board[to.r][to.c] = Board[from.r][from.c];
	Board[from.r][from.c].figure = *figure;
	Board[from.r][from.c].color = *color;
}
void init_mov(int mov[12][12])
{
	int i, j;
	for(i = 0; i < 12; i++)
		for(j = 0; j < 12; j++)
			mov[i][j] = 0;
}
struct best_move black(struct board Board[12][12], int level, int max)
{
	enum FIGURE figure = EMPTY;
	enum COLOR color = UNDEF;
	struct best_move ans, max_move = {{-1, -1}, {-1, -1}, 0};
	int ours, theirs;
	if(level == max)
	{
		ours = mark(Board, BLACK);
		theirs = mark(Board, WHITE);
		max_move.score = ours - theirs;
	//	printf(" solve in black == %d\n", max_move.score);
		return max_move;
	}
	int i, j, res, k, l, r, max_value = -3000;
	struct cell current_from, current_to;
	int mov[12][12];
	for(i = 9; i >= 2; i--)
		for(j = 2; j < 10; j++)
			if(Board[i][j].figure != EMPTY)
				if(Board[i][j].color == BLACK)
				{
					current_from.r = i;
					current_from.c = j;
					init_mov(mov);
					if(Board[i][j].figure == PAWN)
						Pawn(Board, BLACK, &current_from, mov);
					if(Board[i][j].figure == ROOK)
						Rook(Board, BLACK, &current_from, mov);
					if(Board[i][j].figure == KNIGHT)
						Knight(Board, BLACK, &current_from, mov);
					if(Board[i][j].figure == BISHOP)
						Bishop(Board, BLACK, &current_from, mov);
					if(Board[i][j].figure == QUEEN)
						Queen(Board, BLACK, &current_from, mov);
					if(Board[i][j].figure == KING)
						King(Board, BLACK, &current_from, mov);
					for(k = 2; k < 10; k++)
					{
						for(l = 2; l < 10; l++)
						{
							if(mov[k][l] == 1)
							{
								current_to.r = k;
								current_to.c = l;
								if(Board[current_to.r][current_to.c].color == UNDEF)
								{
									make_move(Board, current_from, current_to);
							//		print_board(Board);
									ans = white(Board, level + 1,  max);
								//	res = ans.score;
								//	printf("iresult %d\n", res);
									if(res > max_value)
									{
								//		printf("zachel v if %d\n", res);
										max_move.score = res;
										max_move.from = current_from;
										max_move.to = current_to;
									}
									make_move(Board, current_to, current_from);
								}
								if(Board[current_to.r][current_to.c].color == WHITE)
								{
									make_move_f(Board, current_from, current_to, &figure, &color);
									ans = white(Board, level + 1,  max);
									res = ans.score;
								//	printf("%d\n", res);
									if(res > max_value)
									{
										max_value = res;
										max_move.from = current_from;
										max_move.to = current_to;
									}
									remake_move(Board, current_to, current_from, &figure, &color);
									figure = EMPTY;
									color = UNDEF;
								}
							}
						}
					}
				}
	return max_move;
}
struct best_move white(struct board Board[12][12], int level, int max)
{
	enum FIGURE figure = EMPTY;
	enum COLOR color = UNDEF;
	struct best_move max_move = {{-1, -1}, {-1, -1}, 0}, ans;
	int ours, theirs;
	if(level == max)
	{
		ours = mark(Board, WHITE);
		theirs = mark(Board, BLACK);
	//	printf(" solve in white == %d\n", max_move.score);
		max_move.score = ours - theirs;
		return max_move;
	}
	int i, j, res, k, l, max_value = -3000;
	struct cell current_from, current_to;//, best_from = {0, 0}, best_to = {0, 0};
	int mov[12][12];
	for(i = 2; i < 10; i++)
		for(j = 2; j < 10; j++)
			if(Board[i][j].figure != EMPTY)
				if(Board[i][j].color == WHITE)
				{
					current_from.r = i;
					current_from.c = j;
					init_mov(mov);
					if(Board[i][j].figure == PAWN)
						Pawn(Board, WHITE, &current_from, mov);
					if(Board[i][j].figure == ROOK)
						Rook(Board, WHITE, &current_from, mov);
					if(Board[i][j].figure == KNIGHT)
						Knight(Board, WHITE, &current_from, mov);
					if(Board[i][j].figure == BISHOP)
						Bishop(Board, WHITE, &current_from, mov);
					if(Board[i][j].figure == QUEEN)
						Queen(Board, WHITE, &current_from, mov);
					if(Board[i][j].figure == KING)
						King(Board, WHITE, &current_from, mov);
					for(k = 2; k < 10; k++)
					{
						for(l = 2; l < 10; l++)
						{
							if(mov[k][l] == 1)
							{
								current_to.r = k;
								current_to.c = l;
								if(Board[current_to.r][current_to.c].color == UNDEF)
								{
									make_move(Board, current_from, current_to);
									print_board(Board);
									ans = black(Board, level + 1,  max);
									res = -ans.score;
									if(res > max_value)
									{
									//	printf("max %d\n", max_value);
										max_move.score = res;
										max_move.from = current_from;
										max_move.to = current_to;
									}
									make_move(Board, current_to, current_from);
								}
								if(Board[current_to.r][current_to.c].color == BLACK)
								{
									make_move_f(Board, current_from, current_to, &figure, &color);
									print_board(Board);
									ans = black(Board, level + 1,  max);
									res = -ans.score;
								//	printf("%d\n", res);
									if(res > max_value)
									{
										max_value = res;
										max_move.from = current_from;
										max_move.to = current_to;
									}
									remake_move(Board, current_to, current_from, &figure, &color);
									figure = EMPTY;
									color = UNDEF;
								}
							}
						}
					}
				}
	return max_move;
}
