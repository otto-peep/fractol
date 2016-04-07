/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 18:06:09 by pconin            #+#    #+#             */
/*   Updated: 2016/04/07 18:11:48 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

#define FRACTOL_H

# define ENTER 36
# define S_WIDTH 1000
# define S_HEIGHT 1000

#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include "./libft/libft.h"
#include <string.h>
#include <math.h>


typedef struct	s_env
{
	void		*win;
	void		*mlx;
	void		*img_ptr;
	void		*img;
	int			bpp;
	int			endi;
	int			line;
}				t_env;

void	ft_setwin(t_env *stock);
int		key_h(int keycode, t_env *stock);
void	mandel(t_env *stock);
void	put_pixel_in_image(int x, int y, t_env *stock);

#endif
