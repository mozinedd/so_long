/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozinedd <mozinedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:55:25 by mozinedd          #+#    #+#             */
/*   Updated: 2024/11/20 11:18:43 by mozinedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_int(int n)
{
	unsigned int	number;
	int				counter;

	number = n;
	counter = 0;
	if (number == 0)
		return (1);
	if (n < 0)
	{
		counter++;
		number = -n;
	}
	while (number != 0)
	{
		number /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				lenght;
	unsigned int	num;

	num = n;
	if (n < 0)
		num = -n;
	lenght = count_int(n);
	str = (char *)malloc((lenght + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[lenght] = '\0';
	while (lenght > 0 && num != 0)
	{
		lenght--;
		str[lenght] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	return (str);
}
