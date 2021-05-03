

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*sourc;

	dest = dst;
	sourc = (char*)src;
	if ((!src && !dst) || ((!src || !dst) && len == 0))
		return (NULL);
	if (ft_memcmp(dst, src, len) == 0)
		return (dst);
	if (dst > src)
	{
		while (len--)
			dest[len] = sourc[len];
		return (dest);
	}
	else
		return (ft_memcpy(dst, src, len));
}
