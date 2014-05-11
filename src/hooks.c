/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/11 22:08:24 by sconso            #+#    #+#             */
/*   Updated: 2014/05/11 22:20:24 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_philo.h>
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

extern pthread_mutex_t		g_mutex;

int							expose(t_mdata *mdata)
{
	if (!mdata->iptr)
		draw_scene(mdata);
	mlx_put_image_to_window(mdata->mptr, mdata->wptr, mdata->iptr, 0, 0);
	return (0);
}

int							loop(t_mdata *mdata)
{
	t_table					*table;

	table = get_table(0);
	if (table->active != 1)
		reset_philos(table);
	draw_scene(mdata);
	mlx_put_image_to_window(mdata->mptr, mdata->wptr, mdata->iptr, 0, 0);
	if (table->active != 2)
		draw_text(mdata);
	else
		mlx_string_put(mdata->mptr, mdata->wptr, 325, mdata->h - 100, 0xFF0000,
						"Now, it is time... To DAAAAAAAANCE!!!");
	draw_life(mdata);
	return (0);
}

int							keyhook(int keycode, t_mdata *mdata)
{
	if (keycode == ESC)
	{
		if (mdata->iptr)
			mlx_destroy_image(mdata->mptr, mdata->iptr);
		mlx_destroy_window(mdata->mptr, mdata->wptr);
		pthread_mutex_destroy(&g_mutex);
		get_table(1);
		free(mdata);
		exit(0);
	}
	return (0);
}
