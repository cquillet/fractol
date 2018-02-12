/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 02:08:40 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/05 22:51:43 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

# ifndef BUFF_SIZE
#  define BUFF_SIZE 80
# endif

# ifndef MAX_FD
#  define MAX_FD 75000
# endif

typedef struct	s_buffer
{
	char		str[BUFF_SIZE + 1];
	ssize_t		len;
	int			ret_value;
}				t_buffer;

int				get_next_line(const int fd, char **line);

#endif
