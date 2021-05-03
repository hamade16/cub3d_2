

#include "libft.h"

int		ft_len(int n)
{
	unsigned int	nb;
	int				j;

	j = 1;
	if (n < 0)
	{
		j++;
		nb = -n;
	}
	else
		nb = n;
	while (nb > 9)
	{
		nb /= 10;
		j++;
	}
	return (j);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	char			*str;
	unsigned int	nb;

	len = ft_len(n);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n < 0)
		nb = -n;
	else
		nb = n;
	while (nb != 0)
	{
		str[len--] = (nb % 10 + 48);
		nb = nb / 10;
	}
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	return (str);
}
