#include "doom_nukem.h"

void	fake_parse(t_env *e)
{
	int		y;
	int		x;

	y = -1;
	while (++y < 20)
	{
		e->data.map[0][0][y][0] = 1;
		e->data.map[0][0][y][19] = 1;
	}
	x = -1;	
	while (++x < 20)
	{
		e->data.map[0][0][0][x] = 1;
		e->data.map[0][0][19][x] = 1;
	}
	e->data.map[0][1][10][10] = 1;
	e->data.map[0][1][18][18] = 1;
	e->data.map[0][1][12][12] = 1;
	e->data.map[0][1][13][13] = 1;
	e->data.map[0][1][13][14] = 1;
	e->data.map[0][1][13][15] = 1;
	e->data.map[1][0][10][10] = 1;
	e->data.map[1][0][18][18] = 1;
	e->data.map[1][0][12][12] = 1;
	e->data.map[1][0][13][13] = 1;
	e->data.map[1][0][13][14] = 1;
	e->data.map[1][0][13][15] = 1;
	e->player.pos.x = 1000;
	e->player.pos.y = 1000;
	e->data.max_x = 20;
	e->data.max_y = 20;
}
