#include "doom_nukem.h"

/*
void	fake_parse(t_env *e)
{
	int		y;

	y = -1;
	while (++y < 20)
	{
		int j = -1;
		while (++j < 20)
		{
			if (j > 7 && j < 13)
				continue;
			e->data.map[0][1][y][j] = 3;
			e->data.map[1][0][y][j] = 0;
		}
		e->data.map[0][0][y][0] = 2;
		e->data.map[0][0][y][19] = 1;
		e->data.map[0][1][y][0] = 2;
		e->data.map[0][1][y][19] = 1;
	}
	int		x;
	x = -1;	
	while (++x < 20)
	{
		e->data.map[0][0][0][x] = 1;
		e->data.map[0][0][19][x] = 1;
		e->data.map[0][1][0][x] = 2;
		e->data.map[0][1][19][x] = 2;
	}
	e->data.map[0][1][0][12] = 0;
	e->player.pos.x = 1000;
	e->player.pos.y = 1000;
	e->data.max_x = 20;
	e->data.max_y = 20;
}
*/

void	fake_parse(t_env *e)
{
	int		y;

	y = 29;
	while (++y < 60)
	{
		int x;
		e->data.map[0][0][y][29] = 3;
		e->data.map[0][0][y][60] = 3;
		x = 29;
		while (++x < 35)
			e->data.map[0][1][y][x] = 3;
		x = 34;
		while (++x < 41)
			e->data.map[0][2][y][x] = 3;
		x = 40;
		while (++x < 45)
			e->data.map[0][3][y][x] = 3;
		e->data.map[0][3][y][50] = 3;
		x = 44;
		while (++x < 50)
			e->data.map[0][4][y][x] = 3;
		x = 49;
		while (++x < 55)
			e->data.map[0][2][y][x] = 3;
		x = 54;
		while (++x < 60)
			e->data.map[0][1][y][x] = 3;
	}
	e->player.pos.x = 5600;
	e->player.pos.y = 5600;
	e->data.max_x = 70;
	e->data.max_y = 70;
}
