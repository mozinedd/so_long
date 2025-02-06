/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozinedd <mozinedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:17:02 by mozinedd          #+#    #+#             */
/*   Updated: 2024/11/20 11:37:45 by mozinedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		index;
	char	chr;

	i = 0;
	index = -1;
	chr = (char)c;
	while (s[i])
	{
		if (s[i] == chr)
		{
			index = i;
		}
		i++;
	}
	if (s[i] == chr)
		return ((char *)s + i);
	if (index != -1)
		return ((char *)s + index);
	return (NULL);
}
