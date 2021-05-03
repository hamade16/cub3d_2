

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = ft_strlen((char*)s);
	if (c == '\0')
		return ((char*)s + i);
	while (*s && *s != c)
		s++;
	if (*s == '\0')
		return (NULL);
	return ((char*)s);
}
