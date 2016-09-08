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
		*a += 0.2 / (0.02 * zoom);
		*b -= 0.2 / (0.02 * zoom);
	}
	else if (code == 1)
	{
		*a -= 0.2 / (0.02 * zoom);
		*b += 0.2 / (zoom * 0.02);
	}
}

void	ft_zoom(t_mem *s, int x, int y, int code)
{
	double dx;
	double dy;
	t_zoom t;

	dy = 0;
	dx = 0;
	t.j = s->x1;
	t.k = s->x2;
	t.l = s->y1;
	t.m = s->y2;
	dx = s->x1 + x * (s->x2 - s->x1) / s->img_x;
	dy = s->y1 + y * (s->y2 - s->y1) / s->img_y;
	if (code == 1)
	{
		s->zoom *= 2;
		s->x1 = dx - (t.k - t.j) / 4;
		s->x2 = dx + (t.k - t.j) / 4;
		s->y1 = dy - (t.m - t.l) / 4;
		s->y2 = dy + (t.m - t.l) / 4;
		s->iter *= 2;
	}
	else if (code == 0)
	{
		s->zoom /= 2;
		s->x1 = dx - (t.k - t.j);
		s->x2 = dx + (t.k - t.j);
		s->y1 = dy - (t.m - t.l);
		s->y2 = dy + (t.m - t.l);
		s->iter /= 2;
	}
}

int		key_h(int keycode, t_mem *s)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == 12)
		s->iter *= 2;
	if (keycode == 0)
		ft_move(&(s->x1), &(s->x2), 0, s->zoom);
	if (keycode == 2)
		ft_move(&(s->x1), &(s->x2), 1, s->zoom);
	if (keycode == 13)
		ft_move(&(s->y1), &(s->y2), 0, s->zoom);
	if (keycode == 1)
		ft_move(&(s->y1), &(s->y2), 1, s->zoom);
	printf("%s%f\n%s%i\n", "iter", s->iter, "keycode", keycode);
	mlx_clear_window(s->mlx, s->win);
	aff_fractal(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img_ptr, 0, 0);
	return (0);
}

int		mouse_h(int button, int x, int y, t_mem *s)
{
	mlx_clear_window(s->mlx, s->win);
	printf("%s%i\n", "button =", button);
	if (button == 5 || button == 1)
		ft_zoom(s, x, y, 1);
	if (button == 4 || button == 2)
		ft_zoom(s, x, y, 0);
	aff_fractal(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img_ptr, 0, 0);
	return (0);
}

void	ft_setwin(t_mem *s)
{
	s->h = 0.9;
	ft_init(s);
	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, S_WIDTH, S_HEIGHT, "Fractol 42");
	s->img_ptr = mlx_new_image(s->mlx, S_WIDTH, S_HEIGHT);
	s->img = mlx_get_data_addr(s->img_ptr, &(s->bpp), &(s->line), &(s->endi));
	aff_fractal(s);
	mlx_hook(s->win, 2, 1, &key_h, s);
	mlx_mouse_hook(s->win, &mouse_h, s);
	mlx_key_hook(s->win, &key_h, s);
	mlx_put_image_to_window(s->mlx, s->win, s->img_ptr, 0, 0);
	mlx_loop(s->mlx);
}
