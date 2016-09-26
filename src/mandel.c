/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:48:28 by pconin            #+#    #+#             */
/*   Updated: 2016/09/15 17:59:13 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	func_mandel(t_mem *s)
{
	s->c_r = s->x / s->zoom + s->x1;
	s->c_i = s->y / s->zoom + s->y1;
	s->z_r = 0;
	s->z_i = 0;
	s->i = 0;
	while (s->z_r * s->z_r + s->z_i * s->z_i < 4 && s->i < s->iter)
	{
		s->tmp = s->z_r;
		s->z_r = s->z_r * s->z_r - s->z_i * s->z_i + s->c_r;
		s->z_i = 2 * s->z_i * s->tmp + s->c_i;
		s->i++;
	}
		put_pixel_in_image(s->x, s->y, s->i, s);
	return ;

}

void	mandel(t_mem *s)
{
	s->x = 0;
	while (s->x < s->img_x)
	{
		s->y = 0;
		while (s->y < s->img_y)
		{
			func_mandel(s);
			s->y++;
		}
		s->x++;
	}
}
