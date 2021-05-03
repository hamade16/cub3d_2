#include "cub3d.h"

void		rayfacing(double angle)
{
	angle = normalize_angle(angle);
	g_rayfacing.up = (angle > 0 && angle < M_PI);
	g_rayfacing.down = !g_rayfacing.up;
	g_rayfacing.right = (angle < 0.5 * M_PI || angle > 1.5 * M_PI);
	g_rayfacing.left = !g_rayfacing.right;
}

void		init_globale_variable(void)
{
	g_fov = M_PI / 3;
	g_up = 13;
	g_down = 1;
	g_left = 123;
	g_right = 124;
	g_nleft = 0;
	g_nright = 2;
	g_texture.tx_width = 64;
	g_texture.tx_height = 64;
	g_sprite[0].width = 64;
	g_sprite[0].height = 64;
	findwall();
}

void		findwall(void)
{
	g_texture.tx_xpm_ptr[0] = mlx_xpm_file_to_image(g_mlx_ptr,
	g_texture.texture_ptah[0], &g_k, &g_k);
	g_texture.tx_xpm_ptr[1] = mlx_xpm_file_to_image(g_mlx_ptr,
	g_texture.texture_ptah[1], &g_k, &g_k);
	g_texture.tx_xpm_ptr[2] = mlx_xpm_file_to_image(g_mlx_ptr,
	g_texture.texture_ptah[2], &g_k, &g_k);
	g_texture.tx_xpm_ptr[3] = mlx_xpm_file_to_image(g_mlx_ptr,
	g_texture.texture_ptah[3], &g_k, &g_k);
	g_texture.tx_xpm_ptr[4] = mlx_xpm_file_to_image(g_mlx_ptr,
	g_sprite_path, &g_sprite[0].width, &g_sprite[0].height);
	g_texture.tx_ptr[0] = (int *)mlx_get_data_addr(g_texture.tx_xpm_ptr[0],
	&g_k, &g_k, &g_k);
	g_texture.tx_ptr[1] = (int *)mlx_get_data_addr(g_texture.tx_xpm_ptr[1],
	&g_k, &g_k, &g_k);
	g_texture.tx_ptr[2] = (int *)mlx_get_data_addr(g_texture.tx_xpm_ptr[2],
	&g_k, &g_k, &g_k);
	g_texture.tx_ptr[3] = (int *)mlx_get_data_addr(g_texture.tx_xpm_ptr[3],
	&g_k, &g_k, &g_k);
	g_texture.tx_ptr[4] = (int *)mlx_get_data_addr(g_texture.tx_xpm_ptr[4],
	&g_k, &g_k, &g_k);
}

int			ft_cheack_element(void)
{
	if (g_win_width < 1 || g_win_height < 1 || !g_texture.texture_ptah[0] ||
	!g_texture.texture_ptah[1] || !g_texture.texture_ptah[2] ||
	!g_texture.texture_ptah[3] || !g_sprite_path ||
	!g_rgb[0].was_here || !g_rgb[1].was_here)
		return (0);
	if (g_rgb[0].r > 255 || g_rgb[0].g > 255 || g_rgb[0].b > 255
	|| g_rgb[1].r > 255 || g_rgb[1].g > 255 || g_rgb[1].b > 255)
		return (0);
	else
	{
		g_win_width = (g_win_width > 2560) ? 2560 : g_win_width;
		g_win_width = (g_win_width < 50) ? 50 : g_win_width;
		g_win_height = (g_win_height > 1440) ? 1440 : g_win_height;
		g_win_height = (g_win_height < 50) ? 50 : g_win_height;
		return (1);
	}
}

int			wish_texture(double angle, double hor_dis, double radius)
{
	rayfacing(angle);
	if (radius == hor_dis)
	{
		if (g_rayfacing.up)
			return (1);
		else
			return (0);
	}
	else
	{
		if (g_rayfacing.right)
			return (2);
		else
			return (3);
	}
}

