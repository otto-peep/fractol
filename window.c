/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:35:23 by pconin            #+#    #+#             */
/*   Updated: 2016/09/08 15:11:42 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr_win(t_mem *stock)
{
	mlx_string_put(stock->mlx, stock->win, 10, 10, 0xffffff, "Move = arrows");
	//mlx_string_put(stock->mlx, stock->win, 10, 25, 0xffffff, "Reinit = enter");
	mlx_string_put(stock->mlx, stock->win, 10, 40, 0xffffff, "Speed +/- = '+'/'-'");
	mlx_string_put(stock->mlx, stock->win, 10, 55, 0xffffff, "Zoom - = 'L'");
	mlx_string_put(stock->mlx, stock->win, 200, 10, 0xffffff, "Color = 'C'");
	mlx_string_put(stock->mlx, stock->win, 200, 25, 0xffffff,
			"Horizontal rotation = 'F' / 'D'");
	mlx_string_put(stock->mlx, stock->win, 200, 40, 0xffffff,
			"Vertical rotation = 'R' / 'E'");
}

int		key_h(int keycode, t_mem *s)
{
	if (keycode == KEY_LS || keycode == KEY_PL)
		ft_speed(keycode, s);
	if (keycode == ESC)
		exit(0);
	if (keycode == 12)
		s->iter *= 2;
	if (keycode == 0)
		ft_move(&(s->x1), &(s->x2), 0, s);
	if (keycode == 2)
		ft_move(&(s->x1), &(s->x2), 1, s);
	if (keycode == 13)
		ft_move(&(s->y1), &(s->y2), 0, s);
	if (keycode == 1)
		ft_move(&(s->y1), &(s->y2), 1, s);
	if (keycode == KEY_I)
		ft_init(s);
	printf("%s%f\n%s%i\n", "iter", s->iter, "keycode", keycode);
	mlx_clear_window(s->mlx, s->win);
	aff_fractal(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img_ptr, 0, 0);
	ft_putstr_win(s);
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
	ft_putstr_win(s);
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
	ft_putstr_win(s);
	mlx_hook(s->win, 6, (1L << 7), &julia_event, s);
	mlx_mouse_hook(s->win, &mouse_h, s);
	mlx_key_hook(s->win, &key_h, s);
	mlx_put_image_to_window(s->mlx, s->win, s->img_ptr, 0, 0);
	mlx_loop(s->mlx);
}
