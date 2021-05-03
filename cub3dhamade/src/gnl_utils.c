#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen((char*)s1);
	s2 = (char*)malloc(sizeof(char) * len + 1);
	if (s2 == NULL)
		return (0);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

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

