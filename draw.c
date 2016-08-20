/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:49:02 by pconin            #+#    #+#             */
/*   Updated: 2016/04/12 13:43:22 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_in_image(int x, int y, int i, t_env *s)
{
	int pl;
	int octet;
	int color;

	color = ((i * 4 * (255/(int)s->fr->iter) << 16) + (i * 4 * (255/(int)s->fr->iter) << 8) + (0));
	octet = s->bpp / 8;
	pl = (x * (s->bpp / 8)) + (y * s->line);
	if (x >= 0 && y >= 0 && x < S_WIDTH && y < S_HEIGHT)
		ft_memcpy(&s->img[pl], &color, octet);
	else if (x == S_WIDTH || y == S_HEIGHT)
		ft_putstr("prob");
	else
		return ;
}
