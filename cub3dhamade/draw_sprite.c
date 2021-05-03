#include "cub3d.h"

int			sprite_utils(int i, int *k, int r, int j)
{
	if (r)
	{
		if (g_sprite[i].it_x + *k >= 0 && (g_sprite[i].it_x + *k) < g_win_width
		&& (g_sprite[i].it_y + j >= 0) && (g_sprite[i].it_y + j < g_win_height))
			return (1);
		else
			return (0);
	}
	else
	{
		if ((g_sprite[i].it_x + *k < 0 || g_sprite[i].it_x + *k > g_win_width)
		|| (g_sprite[i].distance >= g_int_col[(int)g_sprite[i].it_x + *k] &&
		g_int_col[(int)g_sprite[i].it_x + *k] != 0))
		{
			*k += 1;
			return (1);
		}
		else
			return (0);
	}
}

void		count_sprite(void)
{
	int		i;
	int		j;

	i = 0;
	while (i < g_i)
	{
		j = 0;
		while (j < g_j[i])
		{
			if (g_map[i][j] == '2')
			{
				g_sprite[g_nbr_sprite].x = (j + 0.5) * CUB;
				g_sprite[g_nbr_sprite].y = (i + 0.5) * CUB;
				g_sprite[g_nbr_sprite].distance =
				find_distance(g_sprite[g_nbr_sprite].x,
				g_xplayer, g_sprite[g_nbr_sprite].y, g_yplayer);
				g_nbr_sprite++;
			}
			j++;
		}
		i++;
	}
}

void		draw_sprite(int i)
{
	int		j;
	int		k;
	int		color;

	j = 0;
	color = 0;
	while (j < (int)g_sprite[i].size)
	{
		k = 0;
		while (k < (int)g_sprite[i].size)
		{
			if (sprite_utils(i, &k, 0, j))
				continue;
			if ((int)(64 * (j * 64 / (int)g_sprite[i].size) +
			(k * 64 / (int)g_sprite[i].size)) < (64 * 64))
				color = g_texture.tx_ptr[4][(int)(64 *
				(j * 64 / (int)g_sprite[i].size) +
				(k * 64 / (int)g_sprite[i].size))];
			if (sprite_utils(i, &k, 1, j) && color > 0)
				g_pxl_ptr[(int)(g_sprite[i].it_y + j) * g_win_width +
				(int)(g_sprite[i].it_x + k)] = color;
			k++;
		}
		j++;
	}
}

void		sort_sprite(void)
{
	int			i;
	int			j;
	t_sprite	sprite_swap;

	i = 0;
	while (i < g_nbr_sprite - 1)
	{
		j = i + 1;
		while (j < g_nbr_sprite)
		{
			if (g_sprite[i].distance < g_sprite[j].distance)
			{
				sprite_swap = g_sprite[i];
				g_sprite[i] = g_sprite[j];
				g_sprite[j] = sprite_swap;
			}
			j++;
		}
		i++;
	}
}

void		calcul_sprite(void)
{
	int		i;

	i = 0;
	count_sprite();
	while (i < g_nbr_sprite)
	{
		g_sprite[i].angle = atan2(g_sprite[i].y -
		g_yplayer, g_sprite[i].x - g_xplayer);
		while (g_sprite[i].angle - g_vision_player > M_PI)
			g_sprite[i].angle -= 2 * M_PI;
		while (g_sprite[i].angle - g_vision_player < -M_PI)
			g_sprite[i].angle += 2 * M_PI;
		g_sprite[i].size = (g_win_width / g_sprite[i].distance) * CUB;
		g_sprite[i].it_x = (g_sprite[i].angle - g_vision_player)
		/ g_fov * g_win_width + (g_win_width / 2 - g_sprite[i].size / 2);
		g_sprite[i].it_y = g_win_height / 2 - g_sprite[i].size / 2;
		i++;
	}
	sort_sprite();
	i = 0;
	while (i < g_nbr_sprite)
		draw_sprite(i++);
}

