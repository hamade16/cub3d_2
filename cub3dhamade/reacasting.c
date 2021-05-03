#include "cub3d.h"

void		draw_vesion(void)
{
	double		angle;
	double		radius;
	float		hor_dis;
	float		vert_dis;
	float		offset;

	angle = g_vision_player - (M_PI / 6);
	g_d = 0;
	while (angle < g_vision_player + (M_PI / 6))
	{
		hor_dis = horizontal_intersections(angle);
		vert_dis = vertical_intersections(angle);
		radius = (hor_dis == -1 || (hor_dis >= vert_dis && vert_dis != -1))
		? vert_dis : hor_dis;
		offset = (radius == vert_dis) ? (float)fmod(g_y, CUB) :
		(float)fmod(g_x, CUB);
		radius = (!radius) ? 1 : radius;
		g_int_col[g_d++] = radius;
		g_slice_height = (CUB / (radius * cos(angle - g_vision_player)))
		* g_distance_to_p;
		g_wall_to_p = (g_win_height / 2) - (g_slice_height / 2);
		drawing_wall(offset, angle, hor_dis, radius);
		angle += (M_PI / 3) / g_win_width;
	}
}

void		init_vision_player(int i, int j)
{
	g_xplayer = (j + 0.5) * CUB;
	g_yplayer = (i + 0.5) * CUB;
	if (g_map[i][j] == 'N')
		g_vision_player = (3 * M_PI) / 2;
	else if (g_map[i][j] == 'S')
		g_vision_player = M_PI / 2;
	else if (g_map[i][j] == 'W')
		g_vision_player = M_PI;
	else if (g_map[i][j] == 'E')
		g_vision_player = 2 * M_PI;
}

void		ft_exit(void)
{
	(g_save) ? bitmapp() : 0;
	free(g_texture.texture_ptah[0]);
	free(g_texture.texture_ptah[1]);
	free(g_texture.texture_ptah[2]);
	free(g_texture.texture_ptah[3]);
	free(g_sprite_path);
	exit(0);
}

void		raycasting(void)
{
	int		i;
	int		j;

	i = 0;
	draw_sky(((int)g_rgb[1].r << 16) +
	((int)g_rgb[1].g << 8) + (int)g_rgb[1].b);
	draw_floor(((int)g_rgb[0].r << 16) +
	((int)g_rgb[0].g << 8) + (int)g_rgb[0].b);
	g_distance_to_p = (g_win_width / 2) / tanf(M_PI / 6);
	while (i < g_i)
	{
		j = 0;
		while (j < g_j[i])
			if (ft_strchr("NWSE", g_map[i][j++]) && !g_xplayer && !g_yplayer)
				init_vision_player(i, --j);
		i++;
	}
	draw_vesion();
	calcul_sprite();
	(!g_save) ? mlx_put_image_to_window(g_mlx_ptr, g_win_ptr,
	g_img_ptr, 0, 0) : ft_exit();
}

