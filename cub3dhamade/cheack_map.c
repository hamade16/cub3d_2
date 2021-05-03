#include "cub3d.h"

int		ft_skip_space(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

int		ft_map(char *str)
{
	int		i;
	int		j;

	i = ft_skip_space(str, 0);
	if (str[i] == '1' && !g_k && ft_cheack_element())
	{
		i = 0;
		j = 0;
		while (str[i] != '\0')
		{
			if (!ft_strchr(" 12NSWE0", str[i]))
				return (-1);
			g_map[g_i][j++] = str[i++];
		}
		g_j[g_i++] = j;
		g_l = (g_l < j) ? j : g_l;
		return (0);
	}
	if (str[i] == '\0')
	{
		g_k = (!g_k) ? g_i : g_k;
		if (g_k == g_i)
			return (0);
	}
	return (-1);
}

int		collect_elements(char *str)
{
	if (*str == 'R' && !g_i && !g_win_height && !g_win_width)
		return (r_collect(str));
	else if (!ft_strncmp(str, "NO", 2) && !g_texture.texture_ptah[0] && !g_i)
		return (nswe_collect(str, 0));
	else if (!ft_strncmp(str, "SO", 2) && !g_texture.texture_ptah[1] && !g_i)
		return (nswe_collect(str, 1));
	else if (!ft_strncmp(str, "WE", 2) && !g_texture.texture_ptah[2] && !g_i)
		return (nswe_collect(str, 2));
	else if (!ft_strncmp(str, "EA", 2) && !g_texture.texture_ptah[3] && !g_i)
		return (nswe_collect(str, 3));
	else if (*str == 'S' && !g_sprite_path && !g_i)
		return (nswe_collect(str, 4));
	else if (*str == 'F' && !g_rgb[0].was_here && !g_i)
		return (fc_collect(str, 0));
	else if (*str == 'C' && !g_rgb[1].was_here && !g_i)
		return (fc_collect(str, 1));
	else
		return (ft_map(str));
}

int		map_error(void)
{
	int		i;
	int		j;

	i = 0;
	g_k = 0;
	while (i < g_i)
	{
		j = 0;
		while (j < g_j[i])
		{
			j = ft_skip_space(g_map[i], j);
			if (ft_strchr("NSWE", g_map[i][j]))
				g_k++;
			if (((i == 0 || i == g_i - 1) && g_map[i][j] != '1') || g_k > 1)
				return (1);
			if (map_error_norminette(i, j))
				return (1);
			j++;
		}
		i++;
	}
	return ((g_k == 1) ? 0 : 1);
}

void	cheack_map(char *map_name)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd != -1)
	{
		while (i != -1 && (i = gnl(fd, &str)))
		{
			i = collect_elements(str);
			free(str);
		}
		i = (i != -1) ? collect_elements(str) : -2;
		(i == -1 || i == 0) ? free(str) : 0;
		if (i == -1 || i == -2)
			ft_printf("Error\nInvalid elements !?\n");
		else if (map_error())
			ft_printf("Error\nInvalid Map !?\n");
		else
			cub3d();
	}
	else
		ft_printf("Error\nFile .cub Incorrecte !?\n");
}

