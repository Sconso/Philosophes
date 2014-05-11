/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/11 20:36:37 by Myrkskog          #+#    #+#             */
/*   Updated: 2014/05/11 20:39:25 by Myrkskog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_philo.h>
#include <unistd.h>

extern pthread_mutex_t		g_mutex;

static void					philo_eat(int nb, t_table *table)
{
		table->philo[nb].status = EATING;
		table->bread[nb] = 1;
		table->bread[(nb + 1) % 7] = 1;
		pthread_mutex_unlock(&g_mutex);
		usleep(EAT_T * 1000000);
		pthread_mutex_lock(&g_mutex);
		table->philo[nb].life = (table->active == 1 ? MAX_LIFE + 1 : MAX_LIFE);
		table->bread[nb] = 0;
		table->bread[(nb + 1) % 7] = 0;
		pthread_mutex_unlock(&g_mutex);
}

static void					philo_think(int nb, t_table *table)
{
	char					*bread;

	table->philo[nb].status = THINKING;
	if (!table->bread[nb])
		bread = &(table->bread[nb]);
	else if (!table->bread[(nb + 1) % 7])
		bread = &(table->bread[(nb + 1) % 7]);
	else
		return ;
	*bread = 1;
	pthread_mutex_unlock(&g_mutex);
	usleep(THINK_T * 1000000);
	pthread_mutex_lock(&g_mutex);
	*bread = 0;
	pthread_mutex_unlock(&g_mutex);
}

static void					philo_idle(int nb, t_table *table)
{
	table->philo[nb].status = IDLE;
	pthread_mutex_unlock(&g_mutex);
	usleep(REST_T * 1000000);
}

void						*sheduler(void *arg)
{
	t_philo					*philo;
	t_table					*table;
	char					left;
	char					right;
	int						i;

	philo = (t_philo *)arg;
	table = get_table(0);
	i = philo->nb;
	while (philo->status != DEAD && table->active == 1)
	{
		pthread_mutex_lock(&g_mutex);
		right = table->bread[i];
		left = table->bread[(i + 1) % 7];
		if (philo->status != EATING && !left && !right)
			philo_eat(philo->nb, table);
		else if (philo->status != THINKING && philo->status != EATING && (!left || !right))
			philo_think(philo->nb, table);
		else
			philo_idle(philo->nb, table);
	}
	return (NULL);
}

