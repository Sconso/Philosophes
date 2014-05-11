/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/11 22:17:41 by sconso            #+#    #+#             */
/*   Updated: 2014/05/11 22:19:36 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>

typedef struct			s_philo
{
	pthread_t			philo;
	int					life;
	char				status;
	char				nb;
}						t_philo;

typedef struct			s_table
{
	t_philo				*philo;
	char				*bread;
	pthread_t			time;
	pthread_t			mlx;
	int					active;
	pthread_mutex_t		mutex;
}						t_table;

typedef struct			s_mdata
{
	void				*mptr;
	void				*wptr;
	void				*iptr;
	char				*idata;
	int					w;
	int					h;
	int					bpp;
	int					sizeline;
	int					endian;
}						t_mdata;

typedef struct			s_vertex
{
	float				x;
	float				y;
	float				z;
	float				w;
	unsigned int		color;
}						t_vertex;

typedef struct			s_delta
{
	float				x1;
	float				x2;
	float				y1;
	float				y2;
}						t_delta;

#endif
