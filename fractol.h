/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 18:06:09 by pconin            #+#    #+#             */
/*   Updated: 2016/04/19 15:20:31 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# define ESC 53
# define ENTER 36
# define KEY_P 35
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_T 17
# define KEY_Y 16
# define KEY_U 32
# define KEY_I 34
# define KEY_O 31
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_G 5
# define KEY_H 4
# define KEY_J 38
# define KEY_K 40
# define KEY_L 37
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_N 45
# define KEY_M 46


# define S_WIDTH 1200
# define S_HEIGHT 600

#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include "./libft/libft.h"
#include <string.h>
#include <math.h>
# include <fcntl.h>
#include <unistd.h>

typedef struct	s_mem
{
	double		x;
	double		y;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		iter;
	double		h;
	double		x_zoom;
	double		y_zoom;
	double		img_x;
	double		img_y;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		i;
	double		tmp;
	double		zoom;
	int			zx;
	int			zy;
	int			w;
	void		*win;
	void		*mlx;
	void		*img_ptr;
	void		*img;
	int			bpp;
	int			endi;
	int			line;
	double			color;
}				t_mem;

typedef struct	s_zoom
{
	int	j;
	int	k;
	int	l;
	int	m;
}				t_zoom;

void	aff_fractal(t_mem *s);
void	ft_setwin(t_mem *stock);
int		key_h(int keycode, t_mem *stock);
void	mandel(t_mem *stock);
void	put_pixel_in_image(int x, int y, int i, t_mem *stock);
void	julia(t_mem *s);
void	ft_init(t_mem *s);
#endif
