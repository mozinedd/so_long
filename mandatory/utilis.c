/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozinedd <mozinedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:03:53 by mozinedd          #+#    #+#             */
/*   Updated: 2025/02/05 14:59:32 by mozinedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	exit_game()
{
	exit(1);
}
void	handle_error(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	
	exit_game();
}