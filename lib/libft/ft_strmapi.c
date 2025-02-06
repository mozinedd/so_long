/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozinedd <mozinedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:39:35 by mozinedd          #+#    #+#             */
/*   Updated: 2024/11/21 20:24:18 by mozinedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	lentofs;
	char			*strf;

	if (!s || !f)
		return (NULL);
	lentofs = ft_strlen(s);
	strf = malloc(lentofs + 1);
	if (!strf)
		return (NULL);
	i = 0;
	while (i < lentofs)
	{
		strf[i] = f(i, s[i]);
		i++;
	}
	strf[i] = '\0';
	return (strf);
}
