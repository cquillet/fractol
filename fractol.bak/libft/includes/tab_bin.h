/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_bin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 11:46:17 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/17 15:58:46 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAB_BIN_H
# define TAB_BIN_H

char			*create_tab_bin(unsigned int n);
char			get_bin(char *t, unsigned int i);
int				let_bin(char *t, unsigned int i, char v);

#endif
