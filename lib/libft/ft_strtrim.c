/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozinedd <mozinedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:43:22 by mozinedd          #+#    #+#             */
/*   Updated: 2024/11/19 22:23:14 by mozinedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chek(char s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

static int	star(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (chek(s1[i], set) == 0)
		{
			break ;
		}
		i++;
	}
	return (i);
}

static int	end(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1);
	while (i >= 0)
	{
		i--;
		if (chek(s1[i], set) == 0)
		{
			break ;
		}
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s;
	size_t	e;
	size_t	i;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	s = star(s1, set);
	e = end(s1, set) + 1;
	if (s == ft_strlen(s1))
		return (ft_strdup(""));
	str = malloc((e - s + 1) * sizeof (char));
	if (!str)
		return (NULL);
	i = 0;
	while (s < e)
		str[i++] = s1[s++];
	str[i] = '\0';
	return (str);
}
