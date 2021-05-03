#include "cub3d.h"

t_rgb	colorconverter(int hexvalue)
{
	t_rgb	rgbcolor;

	rgbcolor.r = ((hexvalue >> 16) & 0xFF);
	rgbcolor.g = ((hexvalue >> 8) & 0xFF);
	rgbcolor.b = ((hexvalue) & 0xFF);
	return (rgbcolor);
}

int		r_collect(char *str)
{
	str++;
	if (*str != ' ')
		return (-1);
	while (*str)
	{
		if (!g_win_width)
			g_win_width = ft_atoi(&str);
		if (!g_win_height)
			g_win_height = ft_atoi(&str);
		if ((*str != '\0' && *str != ' ') || !g_win_width || !g_win_height)
			return (-1);
		(*str != '\0') ? str++ : 0;
	}
	return (0);
}

int		nswe_collect(char *str, int n)
{
	(n != 4) ? str += 2 : str++;
	if (*str != ' ')
		return (-1);
	while (*str == ' ')
		str++;
	if (n == 4)
	{
		g_sprite_path = ft_strjoin(g_sprite_path, str);
		g_xpm_ptr = mlx_xpm_file_to_image(g_mlx_ptr, g_sprite_path,
		&g_texture.tx_width, &g_texture.tx_height);
	}
	else
	{
		g_texture.texture_ptah[n] = ft_strjoin(g_texture.texture_ptah[n], str);
		g_xpm_ptr = mlx_xpm_file_to_image(g_mlx_ptr, g_texture.texture_ptah[n],
		&g_texture.tx_width, &g_texture.tx_height);
	}
	return ((!g_xpm_ptr) ? -1 : 0);
	return (0);
}

int		fc_collect(char *str, int i)
{
	g_rgb[i].was_here = 1;
	str++;
	if (*str != ' ')
		return (-1);
	g_rgb[i].r = ft_atoi(&str);
	while (*str == ' ')
		str++;
	if (*str == ',')
	{
		str++;
		g_rgb[i].g = ft_atoi(&str);
		while (*str == ' ')
			str++;
		if (*str == ',')
		{
			str++;
			g_rgb[i].b = ft_atoi(&str);
			while (*str == ' ')
				str++;
			if (*str == '\0' && g_rgb[i].r >= 0 && g_rgb[i].g >= 0
				&& g_rgb[i].b >= 0)
				return (0);
		}
	}
	return (-1);
}

int		map_error_norminette(int i, int j)
{
	if (g_map[i][j] == '0' || g_map[i][j] == '2' ||
		ft_strchr("NSWE", g_map[i][j]))
	{
		if (j - 1 >= 0 && j + 1 < g_j[i] &&
			g_map[i][j - 1] != ' ' && g_map[i][j + 1] != ' ')
		{
			if (i - 1 >= 0 && i + 1 < g_i && j < g_j[i - 1] && j < g_j[i + 1]
				&& g_map[i - 1][j] != ' ' && g_map[i + 1][j] != ' ')
			{
				if (!(j - 1 >= 0 && j + 1 < g_j[i - 1] && j + 1 < g_j[i + 1] &&
				g_map[i - 1][j - 1] != ' ' && g_map[i - 1][j + 1] != ' ' &&
				g_map[i + 1][j - 1] != ' ' && g_map[i + 1][j + 1]))
					return (1);
			}
			else
				return (1);
		}
		else
			return (1);
	}
	return (0);
}
