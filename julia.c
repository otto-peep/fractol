/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:47:53 by pconin            #+#    #+#             */
/*   Updated: 2016/04/19 15:16:55 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	func_julia(double x, double y, t_env *s)
{
	double	c_r = 0.285;
	double	c_i = 0.01;
	double	z_r = x / s->fr->zoom + s->fr->x1;
	double	z_i = y / s->fr->zoom + s->fr->y1;
	int i = 0;
	double tmp;
	
	ft_putstr("julia");
	while (z_r * z_r + z_i * z_i < 4 && i < s->fr->iter)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * tmp + c_i;
		i++;
	}
	if (i == s->fr->iter)
		put_pixel_in_image(x, y, 1, s);
	else
		put_pixel_in_image(x, y, i, s);
	return ;

}

void	julia(t_env *s)
{
	double x;
	double y;
	
	s->fr->img_x = (s->fr->x2 - s->fr->x1) * s->fr->zoom;
	s->fr->img_y = (s->fr->y2 - s->fr->y1) * s->fr->zoom;
	x = 0;
	while (x < s->fr->img_x)
	{
		y = 0;
		while (y < s->fr->img_y)
		{
			func_julia(x, y, s);
			y++;
		}
		x++;
	}
}

