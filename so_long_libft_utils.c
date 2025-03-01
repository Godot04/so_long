/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_libft_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:28:27 by opopov            #+#    #+#             */
/*   Updated: 2025/02/24 15:30:34 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	a;

	a = 0;
	while (s1[a] && s2[a])
	{
		if (s1[a] != s2[a])
		{
			return ((unsigned char)s1[a] - (unsigned char)s2[a]);
		}
		a++;
	}
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
	{
		a++;
	}
	if (c == '\0')
	{
		return ((char *)&s[a]);
	}
	while (a >= 0)
	{
		if (s[a] == (char) c)
		{
			return ((char *)&s[a]);
		}
		a--;
	}
	return (NULL);
}
