/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/11 22:39:10 by sconso            #+#    #+#             */
/*   Updated: 2014/05/11 22:39:11 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_philo.h>
#include <mlx.h>

void			draw_text(t_mdata *md)
{
	int			i;
	char		*str;
	int			philo;
	int			height;

	i = -1;
	while (++i < 7)
	{
		philo = get_philo(i);
		height = (md->h - 150) + (i * 20);
		mlx_string_put(md->mptr, md->wptr, 50, height, philo, "Philo n*");
		mlx_string_put(md->mptr, md->wptr, 100, height, philo, ft_itoa(i + 1));
		mlx_string_put(md->mptr, md->wptr, 105, height, philo, " is ");
		if (philo == 0xFFFFFF)
			str = "resting";
		else if (philo == 0x00FF00)
			str = "thinking";
		else if (philo == 0xFF0000)
			str = "eating";
		else
			str = "dead...";
		mlx_string_put(md->mptr, md->wptr, 128, height, philo, str);
	}
	mlx_string_put(md->mptr, md->wptr, md->w - 130, md->h - 10, 0x000000,
					"By Sconso & Ffondane");
}

void			draw_life(t_mdata *mdata)
{
	t_table		*table;

	table = get_table(0);
	mlx_string_put(mdata->mptr, mdata->wptr, 395, 155, 0xFF0000,
					ft_itoa(table->philo[0].life));
	mlx_string_put(mdata->mptr, mdata->wptr, 545, 280, 0xFF0000,
					ft_itoa(table->philo[1].life));
	mlx_string_put(mdata->mptr, mdata->wptr, 545, 405, 0xFF0000,
					ft_itoa(table->philo[2].life));
	mlx_string_put(mdata->mptr, mdata->wptr, 445, 555, 0xFF0000,
					ft_itoa(table->philo[3].life));
	mlx_string_put(mdata->mptr, mdata->wptr, 345, 555, 0xFF0000,
					ft_itoa(table->philo[4].life));
	mlx_string_put(mdata->mptr, mdata->wptr, 245, 405, 0xFF0000,
					ft_itoa(table->philo[5].life));
	mlx_string_put(mdata->mptr, mdata->wptr, 245, 280, 0xFF0000,
					ft_itoa(table->philo[6].life));
}

void			draw_bread(t_mdata *mdata)
{
	draw_line(to_vertex(310, 210, 0, get_bread(0)),
				to_vertex(360, 260, 0, get_bread(0)),
				mdata);
	draw_line(to_vertex(490, 210, 0, get_bread(1)),
				to_vertex(440, 260, 0, get_bread(1)),
				mdata);
	draw_line(to_vertex(490, 350, 0, get_bread(2)),
				to_vertex(430, 350, 0, get_bread(2)),
				mdata);
	draw_line(to_vertex(490, 480, 0, get_bread(3)),
				to_vertex(440, 430, 0, get_bread(3)),
				mdata);
	draw_line(to_vertex(400, 490, 0, get_bread(4)),
				to_vertex(400, 430, 0, get_bread(4)),
				mdata);
	draw_line(to_vertex(310, 480, 0, get_bread(5)),
				to_vertex(350, 430, 0, get_bread(5)),
				mdata);
	draw_line(to_vertex(310, 350, 0, get_bread(6)),
				to_vertex(375, 350, 0, get_bread(6)),
				mdata);
}
