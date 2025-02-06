/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozinedd <mozinedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:46:13 by mozinedd          #+#    #+#             */
/*   Updated: 2024/11/21 17:16:32 by mozinedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	num;
	long	holder;

	sign = 1;
	num = 0;
	holder = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		if (num < holder)
			return (-(1 + sign) / 2);
		holder = num;
		str++;
	}
	return (sign * num);
}
