/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/11 20:17:55 by Myrkskog          #+#    #+#             */
/*   Updated: 2014/05/11 20:20:10 by Myrkskog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_philo.h>
#include <mlx.h>

static void		draw_philos(t_mdata *mdata)
{
	draw_circle(mdata, 25, to_vertex(400, 150, 0, 0xFF0000), get_philo(0));
	draw_circle(mdata, 25, to_vertex(550, 275, 0, 0xFF0000), get_philo(1));
	draw_circle(mdata, 25, to_vertex(550, 400, 0, 0xFF0000), get_philo(2));
	draw_circle(mdata, 25, to_vertex(450, 550, 0, 0xFF0000), get_philo(3));
	draw_circle(mdata, 25, to_vertex(350, 550, 0, 0xFF0000), get_philo(4));
	draw_circle(mdata, 25, to_vertex(250, 400, 0, 0xFF0000), get_philo(5));
	draw_circle(mdata, 25, to_vertex(250, 275, 0, 0xFF0000), get_philo(6));
}

void			*draw_scene(void *arg)
{
	t_mdata		*mdata;

	mdata = (t_mdata *)arg;
	if (mdata->iptr)
		mlx_destroy_image(mdata->mptr, mdata->iptr);
	mdata->iptr = mlx_new_image(mdata->mptr, mdata->w, mdata->h);
	mdata->idata = mlx_get_data_addr(mdata->iptr, &mdata->bpp,
										&mdata->sizeline, &mdata->endian);
	draw_rect(mdata, to_vertex(0, mdata->h - 200, 0, 0x666666),
					to_vertex(mdata->w, mdata->h, 0, 0x666666));
	draw_rect(mdata, to_vertex(300, 200, 0, 0x555555),
					to_vertex(500, 500, 0, 0x555555));
	draw_philos(mdata);
	draw_bread(mdata);
	return (NULL);
}
