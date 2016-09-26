/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:47:53 by pconin            #+#    #+#             */
/*   Updated: 2016/09/08 15:54:27 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	func_julia(double x, double y, t_mem *s)
{
	s->c_r = s->x_zoom / 1000;
	s->c_i = s->y_zoom / 1000;
	s->z_r = x / s->zoom + s->x1;
	s->z_i = y / s->zoom + s->y1;
	s->i = 0;
	
	while (s->z_r * s->z_r + s->z_i * s->z_i < 4 && s->i < s->iter)
	{
		s->tmp = s->z_r;
		s->z_r = s->z_r * s->z_r - s->z_i * s->z_i + s->c_r;
		s->z_i = 2 * s->z_i * s->tmp + s->c_i;
		s->i++;
	}
	if (s->i == s->iter)
		put_pixel_in_image(x, y, 1, s);
	else
		put_pixel_in_image(x, y, s->i, s);
	return ;

}

void	julia(t_mem *s)
{
	double x;
	double y;
	
	x = 0;
	while (x < s->img_x)
	{
		y = 0;
		while (y < s->img_y)
		{
			func_julia(x, y, s);
			y++;
		}
		x++;
	}
}

int		julia_event(int x, int y, t_mem *s)
{
	if (s->w == 2 && s->blok_julia == 0)
	{
		s->x_zoom = x;
		s->y_zoom = y;
		aff_fractal(s);
		mlx_put_image_to_window(s->mlx, s->win, s->img_ptr, 0, 0);
		ft_putstr_win(s);
	}
	return (0);
}
