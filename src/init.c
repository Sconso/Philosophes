/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/11 20:15:56 by Myrkskog          #+#    #+#             */
/*   Updated: 2014/05/11 20:28:33 by Myrkskog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_philo.h>
#include <mlx.h>
#include <stdlib.h>

static t_mdata		*init_mlx(void)
{
	t_mdata			*mdata;

	mdata = (t_mdata *)malloc(sizeof(t_mdata));
	if (!mdata)
		exit(0);
	mdata->w = WIDTH;
	mdata->h = HEIGHT;
	mdata->mptr = mlx_init();
	mdata->wptr = mlx_new_window(mdata->mptr, mdata->w, mdata->h, "Philo");
	mdata->iptr = NULL;
	mlx_key_hook(mdata->wptr, keyhook, mdata);
	mlx_expose_hook(mdata->wptr, expose, mdata);
	mlx_loop_hook(mdata->mptr, loop, mdata);
	mlx_loop(mdata->mptr);
	return (mdata);
}

void			reset_philos(t_table *table)
{
	int			i;

	i = -1;
	while (++i < 7)
	{
		if (table->philo[i].status != DEAD)
		{
			table->philo[i].life -= (table->philo[i].life == 21 ? 1 : 0);
			table->philo[i].status = IDLE;
		}
		table->bread[i] = 0;
	}
}

t_table				*create_table(void)
{
	t_table			*table;
	t_philo			*philo;
	char			*bread;
	int				i;

	if (!(table = (t_table *)malloc(sizeof(*table))))
		exit(0);
	if (!(philo = (t_philo *)malloc(sizeof(*philo) * 7)))
		exit(0);
	if (!(bread = (char *)malloc(sizeof(*bread) * 7)))
		exit(0);
	i = -1;
	while (++i < 7)
	{
		philo[i].nb = i;
		philo[i].life = MAX_LIFE;
		philo[i].status = IDLE;
		bread[i] = 0;
	}
	table->philo = philo;
	table->bread = bread;
	table->active = 1;
	return (table);
}

void				*init(void *arg)
{
	t_mdata			*mdata;

	mdata = init_mlx();
	(void)arg;
	return (mdata);
}
