

#include "libft.h"

int		ft_calcul_par(const char *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
			{
				i++;
				if (s[i] == c)
					j++;
				if (s[i] == '\0' && s[i - 1] != c)
					j++;
			}
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (j);
}

int		ft_calcul_char(const char *s, int i, char c)
{
	int k;

	k = 1;
	if (!s)
		return (0);
	while (s[i] != c && s[i])
	{
		i++;
		if (s[i] != c && s[i] != '\0')
			k++;
	}
	return (k);
}

void	*fr_ee(char **split, int j)
{
	while (j--)
		free(split[j]);
	free(split);
	return (NULL);
}

char	**split2(char const *s, char c, char **split)
{
	int		i;
	int		j;
	int		k;
	int		tol;
	int		len;

	j = 0;
	i = 0;
	tol = ft_calcul_par(s, c);
	while (j < tol && s[i] != '\0')
	{
		k = 0;
		while (s[i] == c)
			i++;
		len = ft_calcul_char(s, i, c);
		split[j] = (char*)malloc(sizeof(char) * (len + 1));
		if (split[j] == NULL)
			return (fr_ee(split, j));
		while (k < len)
			split[j][k++] = s[i++];
		split[j++][k++] = '\0';
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	if (!(split = (char**)malloc(sizeof(char*) * (ft_calcul_par(s, c) + 1))))
		return (NULL);
	return (split2(s, c, split));
}
