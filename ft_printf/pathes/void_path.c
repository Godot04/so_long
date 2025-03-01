/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:32:44 by opopov            #+#    #+#             */
/*   Updated: 2024/12/02 13:39:32 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	print_path(int i, char *r, int count)
{
	while (i >= 0)
	{
		count += write (1, &r[i], 1);
		i--;
	}
	return (count);
}

static int	check_path(void *x)
{
	if (x == NULL)
	{
		write(1, "(nil)", 5);
		return (0);
	}
	return (1);
}

static int	main_calc(unsigned long long x1, int tr, char *s)
{
	int	i;

	i = 0;
	while (x1 > 0)
	{
		tr = x1 % 16;
		if (tr > 9)
			s[i] = (tr - 10) + 'a';
		else
			s[i] = tr + '0';
		x1 /= 16;
		i++;
	}
	s[i] = '\0';
	i--;
	return (i);
}

int	void_path(void *x, int count)
{
	char				s[17];
	int					i;
	int					tr;
	unsigned long long	x1;

	tr = 0;
	x1 = (unsigned long long)x;
	if (check_path(x) != 1)
	{
		count += 5;
		return (count);
	}
	count += write(1, "0x", 2);
	i = main_calc(x1, tr, s);
	count = print_path(i, s, count);
	return (count);
}
