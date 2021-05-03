#include "cub3d.h"

int		cheack_arg(int ac, char **av)
{
	int		i;

	i = 0;
	while (av[1][i] != '\0')
		if (!ft_strcmp(av[1] + i++, ".cub") && i - 1 != 0)
		{
			if (ac == 3 && ft_strcmp(av[2], "--save"))
				return (0);
			else
			{
				g_save = (ac == 3) ? 1 : 0;
				return (1);
			}
		}
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 2 || ac == 3)
	{
		g_mlx_ptr = mlx_init();
		if (cheack_arg(ac, av))
			cheack_map(av[1]);
		else
			ft_printf("Error\nInvalid argument...\n");
	}
	else if (ac == 1)
		ft_printf("Error\nMissing file .cub !?\n");
	else
		ft_printf("Error\nThe argument more than 2 !?\n");
	return (0);
}
