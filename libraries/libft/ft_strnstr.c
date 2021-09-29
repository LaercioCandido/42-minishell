/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:17:55 by mirkios           #+#    #+#             */
/*   Updated: 2021/09/29 18:14:40 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	needle_len;

	needle_len = ft_strlen(small);
	if (!needle_len)
		return ((char *)big);
	while (*big && len >= needle_len)
	{
		if (!ft_strncmp(big, small, needle_len))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
