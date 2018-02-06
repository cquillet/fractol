/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 15:01:02 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/30 18:14:11 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fractol.h"
#include "graphics.h"
#include "mlx.h"
#include "complex.h"
#include "libft.h"
#include <stdlib.h>
#include "mlx_keys_macos.h"
#include "mlx_mouse_macos.h"

int				exit_fractol(t_fractal *f, int ret_value)
{
	int			n;

	n = 0;
	while (n < f->nb_newton)
	{
		poly_del(&(f->poly_newton[n]));
		poly_del(&(f->poly_newton_deriv[n]));
		n++;
	}
	ft_memdel((void **)&(f->save));
	ft_memdel((void **)&(f->dyn_fract));
	mlx_destroy_image(f->mlx.mlx, f->mlx.win.img.ptr);
	mlx_destroy_window(f->mlx.mlx, f->mlx.win.win);
	exit(ret_value);
	return (ret_value);
}

static int		usage_fractol(char *s)
{
	if (*s)
		ft_putendl(s);
	ft_putendl("usage: fractol (mandel[brot] | julia | burning | newton)");
	return (EXIT_FAILURE);
}

static int		test_fract_type(t_fractal *f, char *s)
{
	if (!ft_strcmp(s, "mandel") || !ft_strcmp(s, "mandelbrot"))
		f->fractal_type = MANDELBROT;
	else if (!ft_strcmp(s, "julia"))
		f->fractal_type = JULIA;
	else if (!ft_strcmp(s, "newton"))
		f->fractal_type = NEWTON;
	else if (!ft_strcmp(s, "burning"))
		f->fractal_type = BURNING;
	else
		return (0);
	return (1);
}

int				main(int ac, char **av)
{
	t_mlx		mlx;
	t_fractal	f;

	if (ac != 2)
		return (usage_fractol(ac < 2 ? "No args!" : "Too much args!"));
	if (!test_fract_type(&f, av[1]))
		return (usage_fractol("Unkown fractal!"));
	mlx = create_mlx(mlx_init(), FRACT_WIDTH, FRACT_WIDTH);
	mlx.win = create_win(&mlx, av[0], mlx.width, mlx.height);
	mlx.win.img = init_img(mlx.mlx, mlx.win.width, mlx.win.height);
	if (!mlx.mlx || !mlx.win.win || !mlx.win.img.ptr || !init_fractal(&f, mlx))
		return (exit_fractol(&f, EXIT_FAILURE));
	f.fract_init[f.fractal_type](&f);
	if (fractal(&f) < 0)
		exit(exit_fractol(&f, EXIT_FAILURE));
	mlx_hook(f.mlx.win.win, KEY_PRESS, 0, fract_key_press, (void *)&f);
	mlx_hook(f.mlx.win.win, KEY_RELEASE, 0, fract_key_release, (void *)&f);
	mlx_hook(f.mlx.win.win, BUTTON_PRESS, 0, fract_mouse_press, (void *)&f);
	mlx_hook(f.mlx.win.win, MOUSE_MOVE, 0, fract_mouse_move, (void *)&f);
	mlx_hook(f.mlx.win.win, BUTTON_RELEASE, 0, fract_mouse_release, (void *)&f);
	mlx_hook(f.mlx.win.win, CLOSE_EVENT, 0, exit_fractol, (void *)&f);
	mlx_loop(f.mlx.mlx);
	return (EXIT_SUCCESS);
}
