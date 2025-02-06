/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozinedd <mozinedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:37:20 by mozinedd          #+#    #+#             */
/*   Updated: 2024/11/20 11:25:13 by mozinedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*w;
	unsigned char	*t;

	w = (unsigned char *)s1;
	t = (unsigned char *)s2;
	i = 0;
	while ((w[i] != '\0' && t[i] != '\0') && w[i] == t[i] && n != 0)
	{
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	return (w[i] - t[i]);
}
