#include "cub3d.h"

float		find_distance(float x1, float x2, float y1, float y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

float		horizontal_utils(int *y, double angle)
{
	if (!(angle > 0 && angle < M_PI))
	{
		*y = 1;
		return (floor(g_yplayer / CUB) * CUB);
	}
	else
	{
		*y = 0;
		return (floor(g_yplayer / CUB) * CUB + CUB);
	}
}

float		vertical_utils(int *x, double angle)
{
	if (angle < 0.5 * M_PI || angle > 1.5 * M_PI)
	{
		*x = 0;
		return (floor(g_xplayer / CUB) * CUB + CUB);
	}
	else
	{
		*x = 1;
		return (floor(g_xplayer / CUB) * CUB);
	}
}

float		horizontal_intersections(double angle)
{
	float	int_y;
	float	int_x;
	float	distance;
	int		y;

	angle = normalize_angle(angle);
	int_y = horizontal_utils(&y, angle);
	int_x = g_xplayer + (int_y - g_yplayer) / tan(angle);
	if (int_x > CUB * g_l || int_x < 0)
		return (-1);
	while (g_map[(int)(int_y - y) / CUB][(int)int_x / CUB] != '1')
	{
		int_y = (!(angle > 0 && angle < M_PI)) ? int_y - CUB : int_y + CUB;
		if (!(angle > 0 && angle < M_PI))
			int_x += -CUB / tan(angle);
		else
			int_x += CUB / tan(angle);
		if (int_x > CUB * g_l || int_x < 0)
			return (-1);
	}
	g_x = int_x;
	distance = find_distance(g_xplayer, int_x, g_yplayer, int_y);
	return (distance);
}

float		vertical_intersections(double angle)
{
	float	int_y;
	float	int_x;
	float	distance;
	int		x;

	angle = normalize_angle(angle);
	int_x = vertical_utils(&x, angle);
	int_y = g_yplayer + (int_x - g_xplayer) * tan(angle);
	if (int_y > CUB * g_i || int_y < 0)
		return (-1);
	while (g_map[(int)int_y / CUB][(int)(int_x - x) / CUB] != '1')
	{
		int_x = (angle < 0.5 * M_PI || angle > 1.5 * M_PI) ?
			int_x + CUB : int_x - CUB;
		if ((angle < 0.5 * M_PI || angle > 1.5 * M_PI))
			int_y += CUB * tan(angle);
		else
			int_y += -CUB * tan(angle);
		if (int_y > CUB * g_i || int_y < 0)
			return (-1);
	}
	g_y = int_y;
	distance = find_distance(g_xplayer, int_x, g_yplayer, int_y);
	return (distance);
}

