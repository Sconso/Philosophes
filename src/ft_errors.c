/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/11 22:07:24 by sconso            #+#    #+#             */
/*   Updated: 2014/05/11 22:07:25 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

static void		ft_putstr_fd(char const *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void			ft_exit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(0);
}
