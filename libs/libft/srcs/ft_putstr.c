/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 11:18:56 by slimon            #+#    #+#             */
/*   Updated: 2019/09/17 05:51:12 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(const char *s, int n)
{
	if (s == NULL)
		return ;
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}
