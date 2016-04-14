/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:05:28 by pconin            #+#    #+#             */
/*   Updated: 2016/04/14 15:35:45 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	func_mandel(double x, double y, t_env *s)
{
	double c_r = x / s->zoom - 2.1;
	double c_i = y / s->zoom - 1.2;
	double z_r = 0;
	double z_i = 0;
	double i = 0;
	double tmp;

	while (z_r * z_r + z_i * z_i < 4 && i < s->fr->iter)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * tmp + c_i;
		i++;
	}
	if (i == s->fr->iter)
		put_pixel_in_image(x, y, 1, s);
	else
		put_pixel_in_image(x, y, i, s);
	return ;
}

void	mandel(t_env *s)
{
	double x;
	double y;
	double image_x = (s->fr->x2 - s->fr->x1) * s->zoom;
	double image_y = (s->fr->y2 - s->fr->y1) * s->zoom;

	x = 0;
	while (x < S_WIDTH)
	{
		y = 0;
		while (y < S_HEIGHT)
		{
			func_mandel(x, y, s);
			y++;
		}
		x++;
	}
}
