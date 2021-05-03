

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1l;
	size_t	s2l;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	s1l = (s1) ? ft_strlen((char*)s1) : 0;
	s2l = ft_strlen((char*)s2);
	if (!(str = (char*)malloc((s1l + s2l + 1) * sizeof(char))))
		return (NULL);
	while (i < s1l)
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
