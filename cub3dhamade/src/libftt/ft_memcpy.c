

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*str;
	const unsigned char	*sourc;
	size_t				i;

	str = dst;
	sourc = src;
	i = 0;
	if ((!str && !sourc) || ft_memcmp(str, sourc, n) == 0)
		return (dst);
	while (i < n)
	{
		str[i] = sourc[i];
		i++;
	}
	return (dst);
}
