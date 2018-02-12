/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 14:58:01 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/18 15:40:27 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIFO_H
# define FIFO_H

# include "unistd.h"

typedef struct		s_fifo
{
	void			*data;
	size_t			data_size;
	struct s_fifo	*prev;
}					t_fifo;

#endif
