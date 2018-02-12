/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:50:44 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/28 22:32:02 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include "int_2d.h"
# include "float_2f.h"

# ifndef INTENSITY_MAX
#  define INTENSITY_MAX 0xFF
# endif

# ifndef GAMMA_KORR
#  define GAMMA_KORR 0.8
# endif

# ifndef BASIC_COLORS
#  define BASIC_COLORS
#  define WHITE 0xFFFFFF
#  define DARK_OCEAN 0x006699
#  define PALE_OCEAN 0x00FFFF
#  define GREEN_LAND 0x00CD00
#  define BROWN_MOUTAIN 0x660000
# endif

typedef struct	s_color
{
	char		alpha;
	char		r;
	char		g;
	char		b;
}				t_color;

unsigned int	color_from_wavelength(double wavelength);

unsigned int	spectrum_color(int value, int min, int max);
unsigned int	spectrum_gray(int value, int min, int max);
unsigned int	rgb_darker(unsigned int color, int value, int start, int black);
unsigned int	rgb_lighter(unsigned int color, int value, int start,
																	int white);
unsigned int	rgb_between(int value, t_2d start_end,
							unsigned int color_start, unsigned int color_end);

unsigned int	rgb_sea(int z, int zmin, int zmax);
unsigned int	rgb_land(int z, int zmin, int zmax);
unsigned int	rgb_earth(int z, int zmin, int zmax);

unsigned int	spectrum_colorf(t_re value, t_re min, t_re max);
unsigned int	spectrum_grayf(t_re value, t_re min, t_re max);
unsigned int	rgb_darkerf(unsigned int color, t_re value, t_re start,
																	t_re black);
unsigned int	rgb_lighterf(unsigned int color, t_re value, t_re start,
																	t_re white);
unsigned int	rgb_betweenf(t_re value, t_2f start_end,
							unsigned int color_start, unsigned int color_end);

#endif
