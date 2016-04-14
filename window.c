/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:35:23 by pconin            #+#    #+#             */
/*   Updated: 2016/04/14 15:35:50 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_h(int keycode, t_env *s)
{
	s->img_ptr = mlx_new_image(s->mlx, S_WIDTH, S_HEIGHT);
	s->img = mlx_get_data_addr(s->img_ptr, &(s->bpp), &(s->line),
					&(s->endi));
	if (keycode == ESC)
		exit(0);
	if (keycode == KEY_A)
		s->fr->iter += 600;
	if (keycode == KEY_P)
		s->zoom += 50;
	if (keycode == KEY_L)
		s->zoom -= 50;
	mandel(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img_ptr, 0, 0);
	return (0);
}

int		mouse_h(int button, int x, int y, t_env *s)
{
	s->img_ptr = mlx_new_image(s->mlx, S_WIDTH, S_HEIGHT);
	s->img = mlx_get_data_addr(s->img_ptr, &(s->bpp), &(s->line), &(s->endi));
	if (button == 1)
		zoom_mandel(s, x, y);
	mandel(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img_ptr, 0, 0);
	return (0);
}

void	ft_setwin(t_env *s)
{
	
	t_frac *mand;

	mand = (t_frac*)malloc(sizeof(t_frac));
	s->fr = mand;
	s->fr->h = 0.9;
	s->bpp = 0;
	s->line = 0;
	s->line = 0;
	s->zoom = 150;
	init_mandel(s->fr);
	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, S_WIDTH, S_HEIGHT, "Fractol 42");
	s->img_ptr = mlx_new_image(s->mlx, S_WIDTH, S_HEIGHT);
	s->img = mlx_get_data_addr(s->img_ptr, &(s->bpp), &(s->line), &(s->endi));
	mlx_mouse_hook(s->win, &mouse_h, s);
	mlx_key_hook(s->win, &key_h, s);
	mlx_loop(s->mlx);
}
