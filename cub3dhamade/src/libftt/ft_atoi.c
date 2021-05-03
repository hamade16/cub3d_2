

#include "libft.h"

int	ft_atoi(char **str)
{
	int				sign;
	unsigned long	res;

	sign = 1;
	res = 0;
	while (**str && (**str == ' '))
		*str += 1;
	if (**str == '+')
		return (-1);
	else if (**str == '-')
		return (-1);
	if (!ft_isdigit(**str))
		return (-1);
	while (**str && (**str >= '0' && **str <= '9'))
	{
		if (res < 21474830)
			res = res * 10 + **str - 48;
		*str += 1;
	}
	return (res * sign);
}
