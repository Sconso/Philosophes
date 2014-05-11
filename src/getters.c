/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/11 20:13:09 by Myrkskog          #+#    #+#             */
/*   Updated: 2014/05/11 20:14:19 by Myrkskog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_philo.h>
#include <stdlib.h>

t_table					*get_table(char dofree)
{
	static t_table		*table = NULL;

	if (!table)
		table = create_table();
	else if (dofree && table)
	{
		free(table->bread);
		free(table->philo);
		free(table);
		table = NULL;
	}
	return (table);
}

int				get_philo(int nb)
{
	t_table		*table;
	t_philo		philo;

	table = get_table(0);
	philo = table->philo[nb];
	if (philo.status == IDLE)
		return (0xFFFFFF);
	if (philo.status == THINKING)
		return (0x00FF00);
	if (philo.status == EATING)
		return (0xFF0000);
	return (0x000000);
}

int				get_bread(int nb)
{
	t_table		*table;

	table = get_table(0);
	if (table->bread[nb])
		return (0xFF0000);
	return (0xFFFF00);
}
