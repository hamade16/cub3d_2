#include "cub3d.h"

double		normalize_angle(double angle)
{
	while (angle < 0)
		(angle += 2 * M_PI);
	while (angle > 2 * M_PI)
		(angle -= 2 * M_PI);
	return (angle);
}

void		drawcub(int x, int y, int color, int width)
{
	int		i;
	int		j;

	i = y;
	while (i < y + width)
	{
		j = x;
		while (j < x + width)
			g_pxl_ptr[(i * g_win_width) + j++] = color;
		i++;
	}
}

void		draw_sky(int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < g_win_height / 2)
	{
		j = 0;
		while (j < g_win_width)
			g_pxl_ptr[i * g_win_width + j++] = color;
		i++;
	}
}

void		draw_floor(int color)
{
	int		i;
	int		j;

	i = g_win_height / 2;
	while (i < g_win_height)
	{
		j = 0;
		while (j < g_win_width)
			g_pxl_ptr[i * g_win_width + j++] = color;
		i++;
	}
}

void		drawing_wall(int offset, double angle, double hor_dis,
			double radius)
{
	int			i;
	float		txt_y;
	float		step;
	int			j;

	i = 0;
	txt_y = 0;
	j = wish_texture(angle, hor_dis, radius);
	step = (float)(g_texture.tx_width / g_slice_height);
	while (i < g_slice_height && g_a < g_win_width)
	{
		if (g_wall_to_p + i >= 0 && g_wall_to_p + i < g_win_height)
		{
			if ((int)(txt_y) * g_texture.tx_height +
			(int)offset < g_texture.tx_height * g_texture.tx_width)
			{
				g_pxl_ptr[(g_wall_to_p + i) * g_win_width + g_a] =
				g_texture.tx_ptr[j][(int)txt_y * g_texture.tx_width + offset];
			}
		}
		txt_y += step;
		i++;
	}
	g_a++;
}
