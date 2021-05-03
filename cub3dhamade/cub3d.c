#include "cub3d.h"

int			hitwall(int xp, int yp, int sign)
{
	xp *= sign;
	yp *= sign;
	if (g_map[((int)g_yplayer + yp) / CUB][((int)g_xplayer + xp) / CUB] != '1'
	&& g_map[((int)g_yplayer + yp) / CUB][((int)g_xplayer + xp) / CUB] != '2')
		return (1);
	else
		return (0);
}

void		cheakwall(int key, int xp, int yp)
{
	if (key == g_up && hitwall(xp, yp, 1))
	{
		g_yplayer += yp;
		g_xplayer += xp;
	}
	else if (key == g_down && hitwall(xp, yp, -1))
	{
		g_yplayer -= yp;
		g_xplayer -= xp;
	}
	else if (key == g_nleft && hitwall(xp, yp, 1))
	{
		g_yplayer += yp;
		g_xplayer += xp;
	}
	else if (key == g_nright && hitwall(xp, yp, -1))
	{
		g_yplayer -= yp;
		g_xplayer -= xp;
	}
	else if (key == g_right)
		g_vision_player += 0.1;
	else if (key == g_left)
		g_vision_player -= 0.1;
	g_vision_player = normalize_angle(g_vision_player);
}

void		ft_key(int key)
{
	int		xp;
	int		yp;

	xp = (key == g_nleft || key == g_nright) ? (CUB / 4) *
	cos(normalize_angle(g_vision_player - (M_PI / 4))) :
	(CUB / 2) * cos(g_vision_player);
	yp = (key == g_nleft || key == g_nright) ? (CUB / 4) *
	sin(normalize_angle(g_vision_player - (M_PI / 4))) :
	(CUB / 2) * sin(g_vision_player);
	cheakwall(key, xp, yp);
}

int			keypressed(int key)
{
	if (key == 53)
		ft_exit();
	ft_key(key);
	g_a = 0;
	g_nbr_sprite = 0;
	if (key == g_up || key == g_down || key == g_right || key == g_left
	|| key == g_nleft || key == g_nright)
		raycasting();
	return (0);
}

void		cub3d(void)
{
	g_img_ptr = mlx_new_image(g_mlx_ptr, g_win_width, g_win_height);
	g_pxl_ptr = (int *)mlx_get_data_addr(g_img_ptr, &g_k, &g_k, &g_k);
	init_globale_variable();
	(g_save) ? raycasting() : 0;
	g_win_ptr = mlx_new_window(g_mlx_ptr, g_win_width, g_win_height, "cub3D");
	(!g_save) ? raycasting() : 0;
	mlx_hook(g_win_ptr, 2, 0, keypressed, (void *)0);
	mlx_loop(g_mlx_ptr);
}

