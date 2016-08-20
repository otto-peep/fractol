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
	s->fr->c_r = x / s->fr->zoom + s->fr->x1;
	s->fr->c_i = y / s->fr->zoom - s->fr->y1;
	s->fr->z_r = 0;
	s->fr->z_i = 0;
	s->fr->i = 0;
	while (s->fr->z_r * s->fr->z_r + s->fr->z_i * s->fr->z_i < 4 && s->fr->i < s->fr->iter)
	{
		s->fr->tmp = s->fr->z_r;
		s->fr->z_r = s->fr->z_r * s->fr->z_r - s->fr->z_i * s->fr->z_i + s->fr->c_r;
		s->fr->z_i = 2 * s->fr->z_i * s->fr->tmp + s->fr->c_i;
		s->fr->i++;
	}
	if (s->fr->i == s->fr->iter)
		put_pixel_in_image(x, y, 1, s);
	else
		put_pixel_in_image(x, y, s->fr->i, s);
	return ;

}

void	mandel(t_env *s)
{
	double x;
	double y;

	x = 0;
	ft_putendl("helloworld");
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
