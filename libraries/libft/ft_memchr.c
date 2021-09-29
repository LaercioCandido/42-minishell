/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:02:11 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/29 18:14:14 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (!n)
		return (0);
	else if (*(unsigned char *)s == (unsigned char)c)
		return ((void *)s);
	else
		return (ft_memchr(++s, c, --n));
}
