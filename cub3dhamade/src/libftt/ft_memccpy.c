
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*str;
	const unsigned char	*sourc;
	size_t				i;

	i = 0;
	str = (unsigned char*)dst;
	sourc = (unsigned char*)src;
	while (i < n)
	{
		if (sourc[i] == (unsigned char)c)
		{
			str[i] = sourc[i];
			return (dst + i + 1);
		}
		else
		{
			str[i] = sourc[i];
			i++;
		}
	}
	return (NULL);
}
