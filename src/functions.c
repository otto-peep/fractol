/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:36:32 by pconin            #+#    #+#             */
/*   Updated: 2016/09/15 17:21:10 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr_win(t_mem *stock)
{
	if (stock->hide == 0)
	{
		mlx_string_put(stock->mlx, stock->win, 10, 10, 0xffffff, "Move= AWSD");
		mlx_string_put(stock->mlx, stock->win, 10, 25, 0xffffff, "init=enter");
		mlx_string_put(stock->mlx, stock->win,
		10, 40, 0xffffff, "Speed +/- = '+'/'-'");
		mlx_string_put(stock->mlx, stock->win, 
		10, 55, 0xffffff, "Adjust RGB : Y/H/U/J/I/K");
		mlx_string_put(stock->mlx, stock->win, 10, 70, 0xffffff, "Color= 'C'");
		mlx_string_put(stock->mlx, stock->win, 
		10, 85, 0xffffff, "+/- iteration = R/F");
		mlx_string_put(stock->mlx, stock->win, 
		10, 100, 0xffffff, "Hide commands = Q");
		mlx_string_put(stock->mlx, stock->win, 10, 115, 0xffffff,
		"Block Julia = 'E'");
	}
}
void	aff_fractal(t_mem *s)
{
	if (s->w == 1)
		mandel(s);
	else if (s->w == 2)
		julia(s);
	else if (s->w == 3)
		func_bship(s);
	else if (s->w == 4)
		func_bbird(s);
	else if (s->w == 5)
		func_cross(s);
}

void	ft_init2(t_mem *s)
{
	if (s->w == 2)
	{
		s->color = 2;
		s->x1 = -2;
		s->x2 = 1.3;
		s->y1 = -1.5;
		s->y2 = 2;
		s->iter = 80;
	}
	else if (s->w == 3 || s->w == 4 || s->w == 5)
	{
		s->color = 3;
		s->x1 = -2;
		s->x2 = 1.5;
		s->y1 = -1;
		s->y2 = 1;
		s->iter = 14;
	}
}

void	ft_init(t_mem *s)
{
	s->hide = 0;
	s->blok_julia = 0;
	s->spd = 2;
	s->zoom = 300;
	s->img_x = (s->x2 - s->x1) * s->zoom;
	s->img_y = (s->y2 - s->y1) * s->zoom;
	if (s->w == 1)
	{
		s->color = 1;
		s->x1 = -2.1;
		s->x2 = 1.5;
		s->y1 = -1.2;
		s->y2 = 1.2;
		s->iter = 50;
	}
	else
		ft_init2(s);
}
