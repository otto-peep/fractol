/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:33:29 by pconin            #+#    #+#             */
/*   Updated: 2016/09/08 15:40:50 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_aff_option(void)
{
	ft_putstr("you have to chose one or many of those options as argument(s) : \n");
	ft_putstr("mandelbrot\njulia\nbudha");
	exit(0);
}

void	launch(int w, t_mem *s)
{
	pid_t father;

	father = fork();
	if (father > 0)
	{
		s->w = w;
		ft_setwin(s);
		return ;
	}
	else
		return ;
}

int		main(int argc, char **argv)
{
	t_mem mem;
	pid_t father;
	int i;

	i = 0;
	if (argc < 2)
		ft_aff_option();
	while (argv[++i])
	if (strcmp(argv[i], "mandelbrot") == 0)
		launch(1, &mem);
	else if (ft_strcmp(argv[i], "julia") == 0)
		launch(2, &mem);
	else if (ft_strcmp(argv[i], "budha") == 0)
		launch(3, &mem);
	else if (ft_strcmp(argv[i], "bship") == 0)
		launch(4, &mem);
	else
		ft_aff_option();
	return (0);
}
