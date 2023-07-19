/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/06 11:14:00 by gozturk       #+#    #+#                 */
/*   Updated: 2023/06/14 11:18:57 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(char *msg)
{
	int	i;

	i = 0;
	while (msg[i] != '\0')
	{
		write(2, &msg[i], 1);
		i++;
	}
}
