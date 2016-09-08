/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   budha.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:00:19 by pconin            #+#    #+#             */
/*   Updated: 2016/09/08 15:54:29 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	func_budha(t_mem *s)
{
	if (!(((int)s->x / 1) % 3 == 1 && ((int)s->y / 1) % 3 == 1)
					&&
					!(((int)s->x / 3) % 3 == 1 && ((int)s->y / 3) % 3 == 1)
					&&
					!(((int)s->x / 9) % 3 == 1 && ((int)s->y / 9) % 3 == 1)
					&&
					!(((int)s->x / 27) % 3 == 1 && ((int)s->y / 27) % 3 == 1)
					&&
					!(((int)s->x / 81) % 3 == 1 && ((int)s->y / 81) % 3 == 1)
			   )
	put_pixel_in_image(s->x, s->y, s->i, s);
	return ;
}

void	budha(t_mem *s)
{
	s->x = 0;
	while (s->x < S_WIDTH)
	{
		s->y = 0;
		while (s->y < S_HEIGHT)
		{
			func_budha(s);
			s->y++;
		}
		s->x++;
	}
}
/*/
void	f_sierpinski(t_mem s)
{
	int	y;
	int	x;
	int	color;
	int	b;

	y = 0;
	b = 4;
	while (y  < s.height)
	{
		x = 0;
		while(x < s.width)
		{
			if (!((x / 1) % 3 == 1 && (y / 1) % 3 == 1)
					&&
					!((x / 3) % 3 == 1 && (y / 3) % 3 == 1)
					&&
					!((x / 9) % 3 == 1 && (y / 9) % 3 == 1)
					&&
					!((x / 27) % 3 == 1 && (y / 27) % 3 == 1)
					&&
					!((x / 81) % 3 == 1 && (y / 81) % 3 == 1)
			   )
			{
				color = createRGB(y*x*255,0,0);
				mlx_pixel_to_image(&s, x, y, color);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(s.mlx, s.win, s.img_ptr, 0, 0);
	mlx_string_put(s.mlx, s.win, 2, 2, WHITE, "Sierpinski");
}
/*/
