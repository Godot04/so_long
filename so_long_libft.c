/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_libft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:03:42 by opopov            #+#    #+#             */
/*   Updated: 2025/02/24 15:30:40 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlcpy(char *dst, const char *src, int size)
{
	int	a;
	int	src_len;

	src_len = 0;
	while (src[src_len])
	{
		src_len++;
	}
	if (size == 0)
	{
		return (src_len);
	}
	a = 0;
	while (a < (size - 1) && src[a])
	{
		dst[a] = src[a];
		a++;
	}
	dst[a] = '\0';
	return (src_len);
}

static char	*itoa_calc(char *res, int m, int n, size_t a)
{
	while (n > 0)
	{
		res[a] = (n % 10) + '0';
		n /= 10;
		a--;
	}
	if (m != 0)
		res[0] = '-';
	return (res);
}

static int	itoa_minus(int *n, size_t *a, int *m)
{
	if ((*n) < 0)
	{
		if ((*n) == -2147483648)
			return (-1);
		(*n) *= -1;
		(*m)++;
		(*a)++;
	}
	if ((*n) == 0)
		return (0);
	return (1);
}

char	*ft_strdup(const char *s)
{
	char	*s1;
	size_t	a;

	a = 0;
	while (s[a] != '\0')
	{
		a++;
	}
	s1 = (char *)malloc((a + 1) * sizeof(char));
	if (s1 == NULL)
	{
		return (NULL);
	}
	a = 0;
	while (s[a] != '\0')
	{
		s1[a] = s[a];
		a++;
	}
	s1[a] = '\0';
	return (s1);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	a;
	int		n1;
	int		m;

	a = 0;
	m = 0;
	if (itoa_minus(&n, &a, &m) == 0)
		return (ft_strdup("0"));
	if (itoa_minus(&n, &a, &m) == -1)
		return (ft_strdup("-2147483648"));
	n1 = n;
	while (n1 > 0)
	{
		n1 = n1 / 10;
		a++;
	}
	res = (char *)malloc((a + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[a] = '\0';
	a -= 1;
	res = itoa_calc(res, m, n, a);
	return (res);
}
