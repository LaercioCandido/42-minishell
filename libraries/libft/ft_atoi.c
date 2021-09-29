/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 19:23:25 by lcandido          #+#    #+#             */
/*   Updated: 2021/09/29 18:13:41 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	iswhtspc(char str)
{
	if (str == 0x20 || (str >= 0x09 && str <= 0x0d))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	sign;

	i = 0;
	j = 0;
	sign = -1;
	while (iswhtspc(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = 1;
	while (*str >= '0' && *str <= '9')
	{
		i = i * 10 - (*str++ - '0');
		if (j < i)
		{
			if (sign < 0)
				return (-1);
			return (0);
		}
		j = i;
	}
	return (i * sign);
}
