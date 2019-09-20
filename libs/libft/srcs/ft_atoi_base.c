/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:27:27 by slimon            #+#    #+#             */
/*   Updated: 2019/09/12 19:20:53 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_digit(char c, int numDigits)
{
	int max_digit;

	if (numDigits <= 10)
		max_digit = numDigits + '0';
	else
		max_digit = numDigits - 10 + 'a';
	if ((c >= '0' && c <= '9') && c <= max_digit)
		return (c - '0');
	else if ((c >= 'a' && c <= 'f') && c <= max_digit)
		return (c + 10 - 'a');
	else
		return (-1);
}

int				ft_atoi_base(const char *str, int base)
{
	int result;
	int sign;
	int digit;

	result = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	while ((digit = get_digit(ft_tolower(*str), base)) >= 0)
	{
		result *= base;
		result += digit * sign;
		++str;
	}
	return (result);
}
