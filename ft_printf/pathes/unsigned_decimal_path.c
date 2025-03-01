/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_decimal_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:35:06 by opopov            #+#    #+#             */
/*   Updated: 2024/12/02 13:39:35 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	print_path(char *s, int count)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		count += write(1, &s[i], 1);
		i++;
	}
	return (count);
}

int	unsigned_decimal_path(unsigned int x, int count)
{
	unsigned int	x1;
	char			s[11];
	int				count_numb;

	count_numb = 0;
	if (x == 0)
	{
		write(1, "0", 1);
		return (++count);
	}
	x1 = x;
	while (x1 > 0)
	{
		x1 = x1 / 10;
		count_numb++;
	}
	s[count_numb] = '\0';
	while (x > 0)
	{
		s[--count_numb] = (x % 10) + '0';
		x = x / 10;
	}
	count += print_path(s, count);
	return (count);
}
