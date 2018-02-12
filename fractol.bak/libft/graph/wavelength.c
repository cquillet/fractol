/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wavelength.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:20:08 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/23 17:18:32 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include <math.h>
#include "vector.h"
#include "libft.h"

/*
** Method adapted from
** http://www.physics.sfasu.edu/astro/color.html
**
** R=645, G=510, B=440
**
** Color	Wavelength
** violet	380 - 450 nm
** blue		450 – 495 nm
** green	495 – 570 nm
** yellow	570 – 590 nm
** orange	590 – 620 nm
** red		620 – 780 nm
**
** classic spectrum:	400 - 650 nm
** sea spectrum:		440 - 490 nm
** land spectrum:		510 - 620 nm (with yellow)
** land spectrum:		510 - 560, 580 - 620 nm (wihtout yellow)
** sea+land spectrum:	440 - 620 nm
*/

static double	factor_vision_limits(double wavelength)
{
	if (wavelength > 700.)
		return (0.3 + 0.7 * (780. - wavelength) / (780. - 700.));
	if (wavelength < 420.)
		return (0.3 + 0.7 * (wavelength - 380.) / (420. - 380.));
	if ((wavelength < 380.) || (wavelength > 780.))
		return (0.0);
	return (1.0);
}

static t_re		gamma_adjust(t_re color)
{
	return (pow(color, GAMMA_KORR));
}

unsigned int	color_from_wavelength(double wavelength)
{
	t_vector	rgb;

	rgb = create_vector(0., 0., 0.);
	if ((wavelength >= 380.) && (wavelength <= 490.))
	{
		rgb.x = (wavelength < 440.) ? (440. - wavelength) / (440. - 380.) : 0.;
		rgb.y = (wavelength < 440.) ? 0. : (wavelength - 440.) / (490. - 440.);
		rgb.z = 1.0;
	}
	else if ((wavelength > 490.) && (wavelength <= 580.))
	{
		rgb.x = (wavelength < 510.) ? 0. : (wavelength - 510.) / (580. - 510.);
		rgb.y = 1.0;
		rgb.z = (wavelength < 510.) ? (510. - wavelength) / (510. - 490.) : 0.;
	}
	else if ((wavelength > 580.) && (wavelength <= 780.))
	{
		rgb.x = 1.0;
		rgb.y = (wavelength < 645.) ? (645. - wavelength) / (645. - 580.) : 0.;
		rgb.z = 0.0;
	}
	rgb = vector_scalar(rgb, factor_vision_limits(wavelength));
	rgb = vector_map(rgb, &gamma_adjust);
	rgb = vector_scalar(rgb, 255.);
	return ((1 << 16) * (int)rgb.x + (1 << 8) * (int)rgb.y + (int)rgb.z);
}
