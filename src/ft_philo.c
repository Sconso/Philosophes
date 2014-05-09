/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 17:27:39 by sconso            #+#    #+#             */
/*   Updated: 2014/05/09 20:19:52 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_philo.h>
#include <stdlib.h>
#include <stdio.h>

void			print_table(t_table *table)
{
	int			i;

	i = -1;
	while (++i < 7)
	{
		printf("Philo n*%d : \n", i);
		printf("Status = %d\n", table->philo[i].status);
		printf("Life = %d\n", table->philo[i].life);
		printf("Bread = %d\n\n", table->bread[i].quantity);
	}
}

t_table			*create_table(void)
{
	t_table		*table;
	t_philo		*philo;
	t_bread		*bread;
	int			i;

	if (!(table = (t_table *)malloc(sizeof(*table))))
		exit(0);
	if (!(philo = (t_philo *)malloc(sizeof(*philo) * 7)))
		exit(0);
	if (!(bread = (t_bread *)malloc(sizeof(*bread) * 7)))
		exit(0);
	i = -1;
	while (++i < 7)
	{
		philo[i].life = LIFE;
		philo[i].status = IDLE;
		bread[i].quantity = QUANTITY;
	}
	table->philo = philo;
	table->bread = bread;
	return (table);
}

int			main(void)
{
	t_table		*table;

	table = create_table();
	print_table(table);
	return (0);
}
