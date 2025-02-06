/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozinedd <mozinedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:13:41 by mozinedd          #+#    #+#             */
/*   Updated: 2024/11/21 20:21:27 by mozinedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	const char		*srrc;

	i = 0;
	dest = (unsigned char *) dst;
	srrc = (const char *) src;
	if (dst == src)
		return (dst);
	if (dest == (NULL) && srrc == (NULL))
		return (dest);
	while (i < n)
	{
		dest[i] = srrc[i];
		i++;
	}
	return (dest);
}
