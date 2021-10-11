#ifndef ENUM_H
#define ENUM_H
enum FIGURE
{
	WALL,
	PAWN,
	KNIGHT,
	KING,
	EMPTY,
	QUEEN,
	BISHOP,
	ROOK,
	ENEMY
};
enum COLOR
{
	WHITE,
	BLACK,
	UNDEF
};
struct board
{
	enum FIGURE figure;
	enum COLOR color;
};
struct cell
{
	int r, c;
};
struct best_move
{
	struct cell from, to;
	int score;
};
#endif // ENUM_H
