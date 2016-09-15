/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:49:02 by pconin            #+#    #+#             */
/*   Updated: 2016/09/15 17:42:23 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_color(t_mem *s)
{
	
	if (s->color == 1)
	{
		s->clr_r = 255;
		s->clr_g = 180;
		s->clr_b = 100;
		s->color = 2;
	}
	else if (s->color == 2)
	{//looks good
		s->clr_r = 100;
		s->clr_g = 255;
		s->clr_b = 180;
		s->color = 3;
	}
	else if (s->color == 3)
	{
		s->clr_r = 180;
		s->clr_g = 100;
		s->clr_b = 255;
		s->color = 1;
	}
}

int	ft_color(int i, t_mem *s)
{
	double c;
	int r;
	int g;
	int b;
	if (i == s->iter)
		return (1);
	c = 0.4 * (i + 1); // 0.3 ancienement s->color
	r = cos(c) * s->clr_r + 128;
	g = cos(c) * s->clr_g + 129;
	b = cos(c) * s->clr_b + 130;
//	printf("r = %i g = %i b = %i", r, g, b);
	return ((r << 16) + (b << 8) + g);
}

void	put_pixel_in_image(int x, int y, int i, t_mem *s)
{
	int pl;
	int octet;
	int color;

	color = ft_color(i, s);
	//	((i * 4 * (255/(int)s->iter) << 16) + (i * 4 * (255/(int)s->iter) << 8) + (0));
	octet = s->bpp / 8;
	pl = (x * (s->bpp / 8)) + (y * s->line);
	if (x >= 0 && y >= 0 && x < S_WIDTH && y < S_HEIGHT)
		ft_memcpy(&s->img[pl], &color, octet);
	else if (x == S_WIDTH || y == S_HEIGHT)
		;
	else
		return ;
}
