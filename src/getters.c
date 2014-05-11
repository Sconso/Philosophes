/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/11 22:07:55 by sconso            #+#    #+#             */
/*   Updated: 2014/05/11 22:08:10 by sconso           ###   ########.fr       */
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

int						get_philo(int nb)
{
	t_table				*table;
	t_philo				philo;

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

int						get_bread(int nb)
{
	t_table				*table;

	table = get_table(0);
	if (table->bread[nb])
		return (0xFF0000);
	return (0xFFFF00);
}
