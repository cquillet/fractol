/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:38:21 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/29 20:39:19 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"
#include "libft.h"
#include "ft_printf.h"

void			cplx_print(t_cplx z, int precision)
{
	if (sizeof(t_re) == sizeof(double))
		ft_printf("%.*f %+.*fi\n", precision, z.re, precision, z.im);
	else if (sizeof(t_re) == sizeof(long double))
		ft_printf("%.*Lf %+.*Lfi\n", precision, z.re, precision, z.im);
}
