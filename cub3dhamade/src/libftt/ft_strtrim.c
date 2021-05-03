

#include "libft.h"

char	*ft_strtrim(const	char *s1, const	char *set)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	len = ft_strlen((char*)s1);
	while ((ft_strchr(set, s1[i])) != 0 && s1[i])
		i++;
	while ((ft_strchr(set, s1[len - 1])) != 0 && (len - 1) > i)
		len--;
	str = (char*)malloc(sizeof(char) * (len - i + 1));
	if (str == NULL)
		return (NULL);
	while (i < len)
		str[j++] = s1[i++];
	str[j] = '\0';
	return (str);
}
