/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 19:11:04 by sconso            #+#    #+#             */
/*   Updated: 2014/05/09 20:27:21 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <pthread.h>

# define IDLE (1);
# define THINKING (2);
# define EATING (3);
# define DEAD (0);
# define LIFE (20);
# define QUANTITY (100);

typedef struct			s_philo
{
	pthread_t			philo;
	int					life;
	char				status;
}						t_philo;

typedef struct			s_bread
{
	int					quantity;
}						t_bread;

typedef struct			s_table
{
	t_philo				*philo;
	t_bread				*bread;
	int					active;
	pthread_mutex_t		mutex;
}						t_table;

#endif
