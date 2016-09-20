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
	double	c_r = -0.8 + 0.005 * s->x_zoom;
	double	c_i = 0.1 + 0.005 * s->y_zoom;
	double	z_r = x / s->zoom + s->x1;
	double	z_i = y / s->zoom + s->y1;
	int i = 0;
	double tmp;
	
	while (z_r * z_r + z_i * z_i < 4 && i < s->iter)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * tmp + c_i;
		i++;
	}
	if (i == s->iter)
		put_pixel_in_image(x, y, 1, s);
	else
		put_pixel_in_image(x, y, i, s);
	return ;

}

void	julia(t_mem *s)
{
	double x;
	double y;
	
	x = 0;
	while (x < S_WIDTH)
	{
		y = 0;
		while (y < S_HEIGHT)
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
