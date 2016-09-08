/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 10:13:53 by pconin            #+#    #+#             */
/*   Updated: 2016/09/08 12:49:11 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_speed(int keycode, t_mem *s)
{
	if (keycode == KEY_LS)
		s->spd += 0.1;
	else if (s->spd > 0.1)
		s->spd -= 0.1;
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

void	ft_zoom(t_mem *s, int x, int y, int code)
{
	double h;

	printf("x=%i y=%i\n", x, y);
	h = 0.01;
	if (code == 1)
	{
		s->zoom *= 2;
	//	s->x1 = x - h;
	//	s->x2 = x + h;
	//	s->y1 = y - h;
	//	s->y2 = y + h;
	}
	else if (code == 0)

		;
/*/	double dx;
	double dy;
	t_zoom t;

	dy = 0;
	dx = 0;
	t.j = s->x1;
	t.k = s->x2;
	t.l = s->y1;
	t.m = s->y2;
	dx = s->x1 + x * (s->x2 - s->x1) / s->img_x;
	dy = s->y1 + y * (s->y2 - s->y1) / s->img_y;
	if (code == 1)
	{
		s->zoom *= 2;
		s->x1 = dx - (t.k - t.j) / 4;
		s->x2 = dx + (t.k - t.j) / 4;
		s->y1 = dy - (t.m - t.l) / 4;
		s->y2 = dy + (t.m - t.l) / 4;
		s->iter *= 2;
	}
	else if (code == 0)
	{
		s->zoom /= 2;
		s->x1 = dx - (t.k - t.j);
		s->x2 = dx + (t.k - t.j);
		s->y1 = dy - (t.m - t.l);
		s->y2 = dy + (t.m - t.l);
		s->iter /= 2;
	}/*/
}
