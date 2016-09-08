/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:49:02 by pconin            #+#    #+#             */
/*   Updated: 2016/09/08 15:54:26 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_color(int i, t_mem *s)
{
	double c;
	int r;
	int g;
	int b;
	if (i == s->iter)
		return (1);
	c = s->color * (i + 1);
	r = cos(c) * 127 + 128;
	g = cos(c) * 127 + 129;
	b = cos(c) * 127 + 130;
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
