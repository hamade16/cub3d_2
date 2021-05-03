

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int				i;
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	nb = n;
	i = 1;
	while ((nb /= 10) > 0)
		i *= 10;
	nb = n;
	while (i)
	{
		ft_putchar_fd((nb / i) + '0', fd);
		nb %= i;
		i /= 10;
	}
}
