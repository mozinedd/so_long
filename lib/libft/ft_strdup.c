/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozinedd <mozinedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:39:38 by mozinedd          #+#    #+#             */
/*   Updated: 2024/11/20 11:23:45 by mozinedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*copys1;
	char	*src;

	len = ft_strlen(s1) + 1;
	src = (char *) s1;
	copys1 = (char *) malloc(len);
	if (copys1 == NULL)
		return (NULL);
	ft_memcpy(copys1, src, len);
	return (copys1);
}
