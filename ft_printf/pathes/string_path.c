/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:00:28 by opopov            #+#    #+#             */
/*   Updated: 2024/12/02 13:56:12 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	string_path(char *s, int count)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i] != '\0')
	{
		count += write(1, &s[i], 1);
		i++;
	}
	return (count);
}
