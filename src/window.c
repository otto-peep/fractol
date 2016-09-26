/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:35:23 by pconin            #+#    #+#             */
/*   Updated: 2016/09/15 18:11:55 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int		key_h(int keycode, t_mem *s)
{
	s->iter = (keycode == KEY_R) ? s->iter * 1.2 : s->iter;
	s->iter = (keycode == KEY_F) ? s->iter / 1.2 : s->iter;
	if (keycode == KEY_E)
	{
		s->blok_julia = (s->blok_julia == 1) ? 0 : 1;
		return (0);
	}
	else if (keycode == KEY_LS || keycode == KEY_PL)
		ft_speed(keycode, s);
	else if (keycode == ESC)
		exit(0);
	else if (keycode == KEY_Q)
		s->hide = (s->hide == 1) ? 0 : 1;
	else if (keycode == 0)
		ft_move(&(s->x1), &(s->x2), 0, s);
	else if (keycode == 2)
		ft_move(&(s->x1), &(s->x2), 1, s);
	else if (keycode == 13)
		ft_move(&(s->y1), &(s->y2), 0, s);
	else if (keycode == 1)
		ft_move(&(s->y1), &(s->y2), 1, s);
	else if (keycode == ENTER)
		ft_init(s);
	else if (keycode == KEY_C)
		change_color(s);
	else if (keycode == KEY_Y || keycode == KEY_H || keycode == KEY_U 
	|| keycode == KEY_J || keycode == KEY_I || keycode == KEY_K)
		adjust_color(s, keycode);
	mlx_clear_window(s->mlx, s->win);
	aff_fractal(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img_ptr, 0, 0);
	ft_putstr_win(s);
	return (0);
}

int		mouse_h(int button, int x, int y, t_mem *s)
{
	mlx_clear_window(s->mlx, s->win);
	if (button == 5 || button == 1)
		ft_zoom(s, x, y);
	else if (button == 4 || button == 2)
		ft_dezoom(s, x, y);
	aff_fractal(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img_ptr, 0, 0);
	ft_putstr_win(s);
	return (0);
}


void	ft_setwin(t_mem *s)
{
	change_color(s);
	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, S_WIDTH, S_HEIGHT, "Fractol 42");
	s->img_ptr = mlx_new_image(s->mlx, S_WIDTH, S_HEIGHT);
	s->img = mlx_get_data_addr(s->img_ptr, &(s->bpp), &(s->line), &(s->endi));
	if (s->w == 2)
		mlx_hook(s->win, 6, (1L << 6), &julia_event, s);
	mlx_mouse_hook(s->win, &mouse_h, s);
	mlx_key_hook(s->win, &key_h, s);
	aff_fractal(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img_ptr, 0, 0);
	ft_putstr_win(s);
	mlx_loop(s->mlx);
}
