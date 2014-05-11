/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 17:27:39 by sconso            #+#    #+#             */
/*   Updated: 2014/05/11 23:11:48 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_philo.h>
#include <unistd.h>

pthread_mutex_t		g_mutex;

int					istimeout(t_table *table, unsigned int timeout)
{
	if (time(NULL) >= timeout)
	{
		table->active = 2;
		return (1);
	}
	return (0);
}

void				*lifetime(void *arg)
{
	t_table			*table;
	int				i;
	unsigned int	timeout;

	timeout = time(NULL) + TIMEOUT;
	table = (t_table *)arg;
	while (table->active == 1)
	{
		usleep(1000000);
		i = -1;
		while (table->active == 1 && ++i < 7)
		{
			pthread_mutex_lock(&g_mutex);
			if (table->philo[i].status != EATING)
			{
				table->philo[i].life -= 1;
				if (table->philo[i].life <= 0 && !(table->active = 0))
					table->philo[i].status = DEAD;
			}
			pthread_mutex_unlock(&g_mutex);
		}
		if (istimeout(table, timeout))
			return (NULL);
	}
	return (NULL);
}

int					main(void)
{
	t_table			*table;
	int				i;
	int				err;

	table = get_table(0);
	i = -1;
	if (pthread_mutex_init(&g_mutex, NULL))
		ft_exit("Impossible d'initialiser le mutex");
	if ((err = pthread_create(&(table->mlx), NULL, &init, NULL)))
		ft_exit("Impossible de creer le thread MLX.\n");
	while (++i < 7)
	{
		err = pthread_create(&(table->philo[i].philo), NULL,
							&sheduler, &(table->philo[i]));
		if (err)
			ft_exit("Impossible de creer le thread Philosophe.\n");
	}
	if ((err = pthread_create(&(table->time), NULL, &lifetime, table)))
		ft_exit("Impossible de creer le thread Lifetime.\n");
	i = -1;
	while (++i < 7)
		pthread_join(table->philo[i].philo, NULL);
	pthread_join(table->mlx, NULL);
	pthread_mutex_destroy(&g_mutex);
	return (0);
}
