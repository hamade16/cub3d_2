

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	dstl;
	size_t	j;
	size_t	srcl;

	j = 0;
	if (!dst && size == 0)
		return (0);
	i = 0;
	dstl = ft_strlen(dst);
	srcl = ft_strlen(src);
	if (size == 0)
		return (srcl);
	if (size <= dstl)
		len = srcl + size;
	else
	{
		len = dstl + srcl;
		while (i < (size - dstl - 1) && src[i])
			dst[dstl + j++] = src[i++];
		dst[dstl + i] = '\0';
	}
	return (len);
}
