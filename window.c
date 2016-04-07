/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:35:23 by pconin            #+#    #+#             */
/*   Updated: 2016/04/07 18:11:50 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_h(int keycode, t_env *stock)
{
	if (keycode == ENTER)
		mandel(stock);
	mlx_put_image_to_window(stock->mlx, stock->win, stock->img_ptr, 0, 0);
	return (0);
}

void	ft_setwin(t_env *stock)
{
	stock->mlx = mlx_init();
	stock->win = mlx_new_window(stock->mlx, S_WIDTH, S_HEIGHT, "Fractol 42");
	stock->img_ptr = mlx_new_image(stock->mlx, S_WIDTH, S_HEIGHT);
	stock->img = mlx_get_data_addr(stock->img_ptr, &(stock->bpp),
			&(stock->line), &(stock->endi));
	mlx_key_hook(stock->win, &key_h, stock);
	mlx_loop(stock->mlx);
}
