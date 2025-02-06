/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozinedd <mozinedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:41:04 by mozinedd          #+#    #+#             */
/*   Updated: 2024/11/20 11:22:34 by mozinedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dest;
	char		*srrc;

	dest = (char *)dst;
	srrc = (char *)src;
	if (dst == src)
		return (dst);
	if (!dst && !src)
		return (NULL);
	i = 0;
	if (dest > srrc)
	{
		i = len;
		while (i > 0)
		{
			i--;
			dest[i] = srrc[i];
		}
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
