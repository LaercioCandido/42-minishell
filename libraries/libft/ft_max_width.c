/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:06:49 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/29 18:14:09 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	maximum(int arg_size, ...)
{
	int		max;
	int		current;
	va_list	numbers;

	va_start(numbers, arg_size);
	max = va_arg(numbers, int);
	while (--arg_size > 0)
	{
		current = va_arg(numbers, int);
		if (current > max)
			max = current;
	}
	va_end(numbers);
	return (max);
}
