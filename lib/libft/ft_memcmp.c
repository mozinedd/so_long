/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozinedd <mozinedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:30:44 by mozinedd          #+#    #+#             */
/*   Updated: 2024/11/20 11:22:14 by mozinedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*w;
	unsigned char	*t;

	w = (unsigned char *) s1;
	t = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (w[i] != t[i])
			return (w[i] - t[i]);
		i++;
	}
	return (0);
}
