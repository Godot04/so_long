/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal_upper_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:55:58 by opopov            #+#    #+#             */
/*   Updated: 2024/12/02 13:39:47 by opopov           ###   ########.fr       */
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

static int	check_path(unsigned int *x)
{
	if (*x == 0)
	{
		write(1, "0", 1);
		return (0);
	}
	return (1);
}

static char	*fill_arr(char *arr)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		arr[i] = 'A' + i;
		i++;
	}
	return (arr);
}

int	hexadecimal_upper_path(unsigned int x, int count)
{
	int		i;
	int		tr;
	char	r[9];
	char	arr[6];

	if (check_path(&x) != 1)
		return (++count);
	fill_arr(arr);
	i = 0;
	while (x > 0)
	{
		tr = x % 16;
		if (tr > 9)
			r[i] = arr[tr - 10];
		else
			r[i] = tr + '0';
		x /= 16;
		i++;
	}
	r[i] = '\0';
	count += print_path(i - 1, r, count);
	return (count);
}
