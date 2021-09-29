/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_of.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:09:24 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/29 18:14:21 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow_pos(int n, int exp)
{
	int	result;

	result = 1;
	while (exp-- > 0)
		result *= n;
	return (result);
}
