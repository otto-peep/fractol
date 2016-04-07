/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:35:23 by pconin            #+#    #+#             */
/*   Updated: 2016/04/07 19:58:57 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_h(int keycode, t_env *stock)
{
	ft_putstr("hi");
	if (keycode == ESC)
		exit(0);
	if (keycode == ENTER)
		mandel(stock);
	mlx_put_image_to_window(stock->mlx, stock->win, stock->img_ptr, 0, 0);
	return (0);
}

void	ft_setwin(t_env *stock)
{
	stock->bpp = 0;
	stock->line = 0;
	stock->line = 0;
	ft_putstr("before init");
	stock->mlx = mlx_init();
	ft_putstr("after init");
	stock->win = mlx_new_window(stock->mlx, S_WIDTH, S_HEIGHT, "Fractol 42");
	ft_putstr("after window");
	stock->img_ptr = mlx_new_image(stock->mlx, S_WIDTH, S_HEIGHT);
	stock->img = mlx_get_data_addr(stock->img_ptr, &(stock->bpp), &(stock->line), &(stock->endi));
	ft_putstr("yo");
	mlx_key_hook(stock->win, &key_h, stock);
	mlx_loop(stock->mlx);
}
