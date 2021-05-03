

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char*)s;
	i = 0;
	while (n > 0)
	{
		str[i] = '\0';
		n--;
		i++;
	}
}
