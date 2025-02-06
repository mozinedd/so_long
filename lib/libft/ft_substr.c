/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozinedd <mozinedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:46:10 by mozinedd          #+#    #+#             */
/*   Updated: 2024/11/14 15:09:38 by mozinedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*substr;
	unsigned int	sizeofs;
	unsigned int	lent;

	if (!s)
		return (NULL);
	sizeofs = (unsigned int)ft_strlen(s);
	lent = (unsigned int ) len;
	if (start > sizeofs || sizeofs == 0)
		return (ft_strdup(""));
	if (lent > sizeofs - start)
		lent = sizeofs - start;
	substr = (char *)malloc(lent + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < lent)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
