/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:33:29 by pconin            #+#    #+#             */
/*   Updated: 2016/04/07 19:22:17 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_env	*stock;
	
	stock = (t_env *)malloc(sizeof(t_env));
	ft_putstr("hello");
	ft_setwin(stock);
	return (0);
}
