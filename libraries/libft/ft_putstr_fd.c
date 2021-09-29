/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 20:12:42 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/29 18:14:28 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	counter;

	counter = 0;
	if (!str)
		return ;
	while (str[counter] != '\0')
	{
		write(fd, &str[counter], 1);
		counter++;
	}
}
