/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:48:24 by opopov            #+#    #+#             */
/*   Updated: 2025/02/22 13:36:35 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *f, ...);
int		ch_path(char x, int count);
int		string_path(char *s, int count);
int		decimal_path(int x, int count);
int		unsigned_decimal_path(unsigned int x, int count);
int		hexadecimal_lower_path(unsigned int x, int count);
int		hexadecimal_upper_path(unsigned int x, int count);
int		void_path(void *x, int count);
char	*ft_itoa1(int n);

#endif
