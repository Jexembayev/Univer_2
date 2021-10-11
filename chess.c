#include <stdio.h>
#include "init_print.h"
#include "turns.h"
#include "move.h"
#include "sum.h"
#include "main_f.h"
#include "enum.h"
int main()
{
	int i, j, ours, theirs, res, rus, player, mmove = 0;
	struct board Board[12][12];
	struct best_move max_move = {{-1, -1}, {-1, -1}, 0};
	init(Board);
	ours = mark(Board, WHITE);
	theirs = mark(Board, BLACK);
	printf("\e[30m");
	puts("|               -ccc-h----eeee--sss--sss------------------      |");
	printf("\e[37m");
	puts("|               c----h----e----s----s-------------              |");
	printf("\e[30m");
	puts("|              c ----hhh--e----s----s-----------                |");
	printf("\e[37m");
	puts("|              c ----h--h-eeee--ss---ss----------------         |");
	printf("\e[30m");
	puts("|               c----h--h-e-------s----s----------              |");
	printf("\e[37m");
	puts("|               -ccc-h--h-eeee-sss--sss---------------------    |");
	printf("\e[0m");
	puts("|                                                               |");
	puts("|                                                               |");
	printf("\e[31m");
	printf("|          Проект был сделан совместно с Дукенбай Аслан         |\n");
	printf("\e[0m");
	puts("|                   Добро пожаловать в ШАХМАТЫ                  |");
	puts("|            Это альфа версия, так что могут быть ошибки        |");
	puts("|                 Выберите 1 player или 2 player                |");
	scanf("%d", &player);
	if(player == 1)
	{
		puts("|                Вы можете выбрать один из трех уровне          |");
		puts("|            (на 3 уровня возможно долгое обдумывание!!)        |");
		puts("|                       1 - обход до 1 уровня                   |");
		printf("\e[36m");
		puts("|                       2 - обход до 3 уровня                   |");
		printf("\e[31m");
		puts("|                       3 - обход до 5 уровня                   |");
		printf("\e[0m");
		scanf("%d", &rus);
		if(rus == 1)
		{
			puts("|                            Уровень 1                          |");
			rus = 1;
		}
		else if(rus == 2)
		{
			puts("|                            Уровень 2                          |");
			rus = 3;
		}
		else if(rus == 3)
		{
			puts("|                            Уровень 3                          |");
			rus = 5;
		}
	}
	else if(player == 2)
	{
		player = 2;
	}
	int on = 0;
	puts("|                 Хотите включить возможные ходы?               |");
	puts("|                       1 - ДА    2 - НЕТ                       |");
	scanf("%d", &on);
	if(on == 1)
	{
		puts("|       Чтобы хорошо работали возможные ходы вводи сначала      |");
		puts("|        Ту позицию, которой вы хотите пойти. Например е2       |");
		puts("|      И вы увидите возможные ходы этой фигуры, а  потом е4     |");
		on = 1;
	}
	else
	{
		puts("|                        Пример ввода e2 e4                     |");
	}
		puts("|                             Вы синие                          |");
	print_board(Board);
	struct cell from = {0, 0}, to = {0, 0};
	while(ours >= 10000 && theirs >= 10000)
	{
		do
		{	
			mmove = move_white(Board, on);
		}while(mmove != 1);	
		if(player != 2)
		{
			print_board(Board);
			max_move = black(Board, 0, rus);
			make_move(Board, max_move.from, max_move.to);
		}
		print_board(Board);
		ours = mark(Board, WHITE);
		theirs = mark(Board, BLACK);
	}
	if(ours < 10000)
		puts("black wins!");
	else if(theirs < 10000)
	{
		printf("\e[31m");
		puts("-*-----*---****---*-----*---*-----------*-*-**-----*--------");
		puts("--*---*---*----*--*-----*---*-----------*---*-*----*--------");
		puts("---*-*----*----*--*-----*----*---------*--*-*--*---*--------");
		puts("----*-----*----*--*-----*----*----*----*--*-*---*--*--------");
		puts("----*-----*----*--*-----*-----*--*-*--*---*-*----*-*--------");
		puts("----*-----*----*---*---*-------*-*-*-*----*-*-----**--------");
		puts("----*------****-----***---------*---*-----*-*------*--------");
		printf("\e[0m");
	}
	return 0;
}
