/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:48:28 by pconin            #+#    #+#             */
/*   Updated: 2016/04/19 15:20:29 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	func_mandel(double x, double y, t_env *s)
{
	double c_r = x / s->fr->zoom - 2.1;
	double c_i = y / s->fr->zoom - 1.2;
	double z_r = 0;
	double z_i = 0;
	double i = 0;
	double tmp;

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

void	mandel(t_env *s)
{
	double x;
	double y;
	s->fr->img_x = (s->fr->x2 - s->fr->x1) * s->fr->zoom;
	s->fr->img_y = (s->fr->y2 - s->fr->y1) * s->fr->zoom;
	x = 0;
	while (x < S_WIDTH)
	{
		y = 0;
		while (y < S_HEIGHT)
		{
		//	if (y > s->fr->zy - 100 && y < s->fr->zy + 100)
			func_mandel(x, y, s);
			y++;
		}
		x++;
	}
}
