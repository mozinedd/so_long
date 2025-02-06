/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozinedd <mozinedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:30:00 by mozinedd          #+#    #+#             */
/*   Updated: 2024/11/19 21:13:15 by mozinedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*pt;
	char	ch;

	pt = (char *)s;
	ch = (char) c;
	i = 0;
	while (i < n)
	{
		if (pt[i] == ch)
		{
			return ((void *)&pt[i]);
		}
		i++;
	}
	return (NULL);
}
