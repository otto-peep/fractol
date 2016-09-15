/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:36:32 by pconin            #+#    #+#             */
/*   Updated: 2016/09/08 15:42:20 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	aff_fractal(t_mem *s)
{
	if (s->w == 1)
		mandel(s);
	else if (s->w == 2)
		julia(s);
	else if (s->w == 4)
		func_bship(s);
}

void	ft_init(t_mem *s)
{
	s->spd = 1;
	s->color = 0.2;
	s->zoom = 100;
	if (s->w == 1)
	{
		s->x1 = -2.1;
		s->x2 = 0.6;
		s->y1 = -1.2;
		s->y2 = 1.2;
		s->img_x = (s->x2 - s->x1) * s->zoom;
		s->img_y = (s->y2 - s->y1) * s->zoom;
		s->iter = 50;
	}
	else if (s->w == 2)
	{
		s->x1 = -1.5;
		s->x2 = 1.5;
		s->y1 = -1.5;
		s->y2 = 1.5;
		s->iter = 150;
	}
	else if (s->w == 4)
	{
		s->x1 = -1.7;;
		s->x2 = 1;
		s->y1 = -1.7;
		s->y2 = 1.7;
		s->iter = 100;
		s->img_x = (s->x2 - s->x1) * s->zoom;
		s->img_y = (s->y2 - s->y1) * s->zoom;
	}
}
