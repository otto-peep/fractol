/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:35:23 by pconin            #+#    #+#             */
/*   Updated: 2016/04/19 15:20:28 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move(double *a, double *b, int code, double zoom)
{
	if (code == 0)
	{
		*a += 0.2 / (0.01 * zoom);
		*b -= 0.2 / (0.01 * zoom);
	}
	else if (code == 1)
	{
		ft_putendl("yo");
		*a -= 0.2 / (0.01 * zoom);
		*b += 0.2 / (zoom * 0.01);
	}
}

void	ft_zoom(t_env *s, int x, int y, int code)
{
	double dx;
	double dy;
	t_zoom t;

	dy = 0;
	dx = 0;
	t.j = s->fr->x1;
	t.k = s->fr->x2;
	t.l = s->fr->y1;
	t.m = s->fr->y2;
	s->fr->zoom *= 2;
	dx = s->fr->x1 + x * (s->fr->x2 - s->fr->x1) / s->fr->img_x;
	dy = s->fr->y1 + y * (s->fr->y2 - s->fr->y1) / s->fr->img_y;
	if (code == 1)
	{
		s->fr->x1 = dx - (t.k - t.j) / 4;
		s->fr->x2 = dx + (t.k - t.j) / 4;
		s->fr->y1 = dy - (t.m - t.l) / 4;
		s->fr->y2 = dy + (t.m - t.l) / 4;
		s->fr->iter *= 2;
	}
	else if (code == 0)
	{
		s->fr->x1 = dx - (t.k - t.j);
		s->fr->x2 = dx + (t.k - t.j);
		s->fr->y1 = dy - (t.m - t.l);
		s->fr->y2 = dy + (t.m - t.l);
		s->fr->iter /= 2;
	}
}

int		key_h(int keycode, t_env *s)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == 12)
		s->fr->iter *= 2;
	if (keycode == 2)
		ft_move(&(s->fr->x1), &(s->fr->x2), 0, s->fr->zoom);
	if (keycode == 0)
		ft_move(&(s->fr->x1), &(s->fr->x2), 1, s->fr->zoom);
	if (keycode == 1)
		ft_move(&(s->fr->y1), &(s->fr->y2), 0, s->fr->zoom);
	if (keycode == 13)
		ft_move(&(s->fr->y1), &(s->fr->y2), 1, s->fr->zoom);
	printf("%s%f\n%s%i\n", "iter", s->fr->iter, "keycode", keycode);
	mlx_clear_window(s->mlx, s->win);
	aff_fractal(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img_ptr, 0, 0);
	return (0);
}

int		mouse_h(int button, int x, int y, t_env *s)
{
	mlx_clear_window(s->mlx, s->win);
	printf("%s%i\n", "button =", button);
	if (button == 5 || button == 1)
		ft_zoom(s, x, y, 1);
	if (button == 4 || button == 2)
		ft_zoom(s, x, y, 0);
	if (button == 1)
	{
		ft_putstr("hergef");
	}
	aff_fractal(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img_ptr, 0, 0);
	return (0);
}

void	ft_setwin(t_env *s)
{
	t_frac fr;

	s->fr = &fr;
	s->fr->h = 0.9;
	ft_init(s);
	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, S_WIDTH, S_HEIGHT, "Fractol 42");
	s->img_ptr = mlx_new_image(s->mlx, S_WIDTH, S_HEIGHT);
	s->img = mlx_get_data_addr(s->img_ptr, &(s->bpp), &(s->line), &(s->endi));
	mlx_hook(s->win, 2, 1, &key_h, s);
	mlx_mouse_hook(s->win, &mouse_h, s);
	mlx_key_hook(s->win, &key_h, s);
	mlx_put_image_to_window(s->mlx, s->win, s->img_ptr, 0, 0);
	mlx_loop(s->mlx);
}
