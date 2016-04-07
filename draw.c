/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:49:02 by pconin            #+#    #+#             */
/*   Updated: 2016/04/07 17:51:22 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_in_image(int x, int y, t_env *stock)
{
	int pl;
	int octet;
	int color;

	color = 0x0033CC33;
	octet = stock->bpp / 8;
	pl = (x * (stock->bpp / 8)) + (y * stock->line);
	if (x >= 0 && y >= 0 && x < S_WIDTH && y < S_HEIGHT)
		ft_memcpy(&stock->img[pl], &color, octet);
	else
		return ;
}
