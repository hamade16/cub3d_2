/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:41:32 by ael-azra          #+#    #+#             */
/*   Updated: 2019/10/27 10:31:05 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 && len == 0)
		return (NULL);
	while (s1[i] && i < len)
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while (s1[i + j] == s2[j] && s2[j] && (i + j) < len)
			{
				if (s2[j + 1] == '\0')
					return (char*)(s1 + i);
				j++;
			}
		}
		i++;
	}
	if (*s2 == '\0')
		return (char*)s1;
	else
		return (NULL);
}
