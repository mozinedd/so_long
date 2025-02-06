/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozinedd <mozinedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:54:16 by mozinedd          #+#    #+#             */
/*   Updated: 2024/11/20 11:29:04 by mozinedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	h;
	unsigned char	*as;

	h = (unsigned char)c;
	as = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		as[i] = h;
		i++;
	}
	return ((void *)b);
}
