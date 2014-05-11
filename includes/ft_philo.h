/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 19:11:04 by sconso            #+#    #+#             */
/*   Updated: 2014/05/11 22:23:25 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <structs.h>

# define IDLE (1)
# define THINKING (2)
# define EATING (3)
# define DEAD (0)
# define MAX_LIFE (20)
# define EAT_T (2)
# define REST_T (2)
# define THINK_T (2)
# define TIMEOUT (10)

# define WIDTH (800)
# define HEIGHT (800)

# define ESC (65307)

/*
** draw.c
*/
void		draw_line(t_vertex v1, t_vertex v2, t_mdata *mdata);
void		draw_rect(t_mdata *mdata, t_vertex v1, t_vertex v2);
void		draw_circle(t_mdata *mdata, int ray, t_vertex center, int color);

/*
** draw_scene.c
*/
void		*draw_scene(void *arg);

/*
** draw_text.c
*/
void		draw_text(t_mdata *md);
void		draw_life(t_mdata *mdata);
void		draw_bread(t_mdata *mdata);

/*
** draw_utilities.c
*/
int			ft_abs(int nb);
t_vertex	to_vertex(float x, float y, float z, int color);

/*
** ft_errors.c
*/
void		ft_exit(char *str);

/*
** ft_itoa.c
*/
char		*ft_itoa(int n);

/*
** getters.c
*/
t_table		*get_table(char dofree);
int			get_philo(int nb);
int			get_bread(int nb);

/*
** hooks.c
*/
int			expose(t_mdata *mdata);
int			loop(t_mdata *mdata);
int			keyhook(int keycode, t_mdata *mdata);

/*
** init.c
*/
void		reset_philos(t_table *table);
t_table		*create_table(void);
void		*init(void *arg);

/*
** states.c
*/
void		*sheduler(void *arg);

#endif
