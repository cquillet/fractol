/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   landsea.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 19:11:45 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/10 15:08:21 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "libft.h"
#include "int_2d.h"

unsigned int	rgb_sea(int z, int zmin, int zmax)
{
	int		depth_ocean;

	if (zmax > 0)
		zmax = 1;
	depth_ocean = -5000;
	if (zmin >= depth_ocean)
		return (rgb_between(z, create_2d(zmin, zmax), DARK_OCEAN, PALE_OCEAN));
	if (z < depth_ocean)
		return (rgb_darker(DARK_OCEAN, z, depth_ocean, zmin));
	return (rgb_between(z, create_2d(depth_ocean, zmax), DARK_OCEAN,
																PALE_OCEAN));
}

unsigned int	rgb_land(int z, int zmin, int zmax)
{
	int		alt_moutain;

	if (zmin < 0)
		zmin = 0;
	if (zmax < 4000)
	{
		return (rgb_between(z, create_2d(zmin, zmax), GREEN_LAND,
																BROWN_MOUTAIN));
	}
	alt_moutain = 95 * zmax / 100;
	if (z > alt_moutain)
		return (rgb_lighter(BROWN_MOUTAIN, z, alt_moutain, zmax));
	return (rgb_between(z, create_2d(zmin, alt_moutain), GREEN_LAND,
																BROWN_MOUTAIN));
}

unsigned int	rgb_earth(int z, int zmin, int zmax)
{
	if (z > 0)
		return (rgb_land(z, zmin, zmax));
	return (rgb_sea(z, zmin, zmax));
}
