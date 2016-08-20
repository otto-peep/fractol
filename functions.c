/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:36:32 by pconin            #+#    #+#             */
/*   Updated: 2016/04/19 15:20:46 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	aff_fractal(t_env *s)
{
	if (s->w == 1)
		mandel(s);
	else if (s->w == 2)
		julia(s);
}

void	ft_init(t_env *s)
{
	s->fr->zoom = 400;
	if (s->w == 1)
	{
		s->fr->x1 = -2.1;
		s->fr->x2 = 0.6;
		s->fr->y1 = -1.2;
		s->fr->y2 = 1.2;
		s->fr->img_x = (s->fr->x2 - s->fr->x1) * s->fr->zoom;
		s->fr->img_y = (s->fr->y2 - s->fr->y1) * s->fr->zoom;
		s->fr->iter = 150;
	}
	else if (s->w == 2)
	{
		s->fr->x1 = -1.5;
		s->fr->x2 = 1.5;
		s->fr->y1 = -1.5;
		s->fr->y2 = 1.5;
		s->fr->iter = 150;
	}
}

