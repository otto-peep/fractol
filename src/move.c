/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 10:13:53 by pconin            #+#    #+#             */
/*   Updated: 2016/09/15 18:11:56 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_speed(int keycode, t_mem *s)
{
	if (keycode == KEY_LS)
		s->spd += 0.2;
	else if (s->spd > 0.2)
		s->spd -= 0.2;
}

void	ft_move(double *a, double *b, int code, t_mem *s)
{
	if (code == 0)
	{
		*a += s->spd / (0.1 * s->zoom);
		*b -= s->spd / (0.1 * s->zoom);
	}
	else if (code == 1)
	{
		*a -= s->spd / (0.1 * s->zoom);
		*b += s->spd / (s->zoom * 0.1);
	}
}

void	ft_zoom(t_mem *s, int x, int y)
{
	double	a;
	double	b;
	double	sx;
	double	sy;

	if (x > 0 && y > 0)
	{
		sx = s->x2 - s->x1;
		sy = s->y2 - s->y1;
		a = s->x1 + ((x * sx) / s->img_x);
		b = s->y1 + ((y * sy) / s->img_y);
		s->x1 = a - sx / 4;
		s->x2 = a + sx / 4;
		s->y1 = b - sy / 4;
		s->y2 = b + sy / 4;
		s->zoom *= 2;
		s->iter *= 1.2;
	}
}

void	ft_dezoom(t_mem *s, int x, int y)
{
	double	a;
	double	b;
	double	sx;
	double	sy;

	if (x > 0 && y > 0)
	{
		sx = s->x2 - s->x1;
		sy = s->y2 - s->y1;
		a = s->x1 + x * sx / s->img_x;
		b = s->y1 + y * sy / s->img_y;
		s->x1 = a - sx;
		s->x2 = a + sx;
		s->y1 = b - sy;
		s->y2 = b + sy;
		s->zoom /= 2;
		s->iter /= 1.2;
	}
}
