/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozinedd <mozinedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:16:07 by mozinedd          #+#    #+#             */
/*   Updated: 2024/11/20 11:24:15 by mozinedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	unsigned int	lentofs;

	i = 0;
	if (!s || !f)
		return ;
	lentofs = (ft_strlen(s));
	while (i < lentofs)
	{
		f(i, &s[i]);
		i++;
	}
}
