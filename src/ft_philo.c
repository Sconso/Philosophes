/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 17:27:39 by sconso            #+#    #+#             */
/*   Updated: 2014/05/09 20:47:23 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_philo.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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
		philo[i].life += i;
		philo[i].status = IDLE;
		bread[i].quantity = QUANTITY;
	}
	table->philo = philo;
	table->bread = bread;
	return (table);
}

void			*test(void *arg)
{
	t_table		*table;

	table = (t_table *)arg;
	pthread_mutex_lock(&(table->mutex));
	printf("Philo %d created !\n", table->active);
	pthread_mutex_unlock(&(table->mutex));
	return (NULL);
}

int			main(void)
{
	t_table		*table;
	int			i;
	int			err;

	table = create_table();
	print_table(table);
	i = -1;
	if (pthread_mutex_init(&(table->mutex), NULL))
	{
		printf("Ton père le MUTEX\n");
		return (1);
	}
	while (++i < 7)
	{
		table->active = i;
		err = pthread_create(&(table->philo[i].philo), NULL, &test, table);
		if (err)
		{
			printf("Nique ton thread fils de mutex !\n");
			exit(0);
		}
	}
	i = -1;
	while (++i < 7)
		pthread_join(table->philo[i].philo, NULL);
	pthread_mutex_destroy(&(table->mutex));
	return (0);
}
