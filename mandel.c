/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:48:28 by pconin            #+#    #+#             */
/*   Updated: 2016/04/07 18:11:45 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	func_mandel(double x, double y, t_env *stock)
{
	double c;
	double z;
	double i;

	z = 0;
	i = 0;
	while (z < 2 && i < 50)
	{
		ft_putstr("mandelwhile");
		c = x + (i * y);
		z = z * z + c;
		i++;
	}
	if (i == 50)
		put_pixel_in_image(x, y, stock);
	else
		return ;

}

void	mandel(t_env *stock)
{
	double x;
	double y;
	
	x = 0;
	while (x < S_WIDTH)
	{
		y = 0;
		while (y < S_HEIGHT)
		{
			func_mandel(x, y, stock);
			y++;
		}
		x++;
	}
}
