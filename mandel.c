/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:48:28 by pconin            #+#    #+#             */
/*   Updated: 2016/04/07 19:58:53 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	func_mandel(double x, double y, t_env *stock)
{
	double c_r = x;
	double c_i = y;
	double z_r = 0;
	double z_i = 0;
	double i = 0;
	double tmp;

	while (z_r * z_r + z_i * z_i < 4 && i < 50)
	{
	{
		z = z * z + c;
		i++;
	}
	if (i == 50)
	{
		put_pixel_in_image(x, y, stock);
		ft_putstr("hello");
	}
	else
		ft_putstr("yo");
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
