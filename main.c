/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:33:29 by pconin            #+#    #+#             */
/*   Updated: 2016/04/19 15:20:50 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_aff_option(void)
{
	ft_putstr("you have to chose one of this option as argument : \n");
	ft_putstr("mandelbrot\njulia\nother");
	exit(0);
}

int		main(int argc, char **argv)
{
	t_env	stock;

	if (argc != 2)
		ft_aff_option();
	if (strcmp(argv[1], "mandelbrot") == 0)
		stock.w = 1;
	else if (strcmp(argv[1], "julia") == 0)
		stock.w = 2;
	else if (strcmp(argv[1], "other") == 0)
		stock.w = 3;
	else
		ft_aff_option();
	ft_setwin(&stock);
	return (0);
}
