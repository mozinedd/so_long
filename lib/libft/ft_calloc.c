/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozinedd <mozinedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:44:15 by mozinedd          #+#    #+#             */
/*   Updated: 2024/11/21 20:27:11 by mozinedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;

	if (size != 0 && count >= SIZE_MAX / size)
		return (NULL);
	pointer = malloc(count * size);
	if (pointer == NULL)
		return (NULL);
	ft_memset(pointer, 0, (count * size));
	return (pointer);
}
