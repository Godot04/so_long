/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:47:53 by opopov            #+#    #+#             */
/*   Updated: 2025/02/21 16:21:23 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pathes(char s, va_list args)
{
	int	count;

	count = 0;
	if (s == 'c')
		return (ch_path((char)va_arg(args, int), count));
	else if (s == 's')
		return (string_path (va_arg(args, char *), count));
	else if (s == 'p')
		return (void_path(va_arg(args, void *), count));
	else if (s == 'd' || s == 'i')
		return (decimal_path(va_arg(args, int), count));
	else if (s == 'u')
		return (unsigned_decimal_path(va_arg(args, unsigned int), count));
	else if (s == 'x')
		return (hexadecimal_lower_path(va_arg(args, unsigned int), count));
	else if (s == 'X')
		return (hexadecimal_upper_path(va_arg(args, unsigned int), count));
	else if (s == '%')
		return (write(1, "%", 1));
	else
		return (-1);
}

int	ft_printf(const char *f, ...)
{
	int		count;
	va_list	args;
	int		res;
	int		i;

	va_start(args, f);
	count = 0;
	i = 0;
	res = 0;
	while (f[i] != '\0')
	{
		if (f[i] == '%')
		{
			i++;
			res = ft_pathes(f[i], args);
			if (res == -1)
				return (-1);
			count += res;
		}
		else
			count += write(1, &f[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
