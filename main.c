/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarneir <ecarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:00:00 by code              #+#    #+#             */
/*   Updated: 2025/12/07 20:00:11 by ecarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** It explains how to use the program if the arguments are incorrect.
*/
static void	print_message(void)
{
	putstr_fd("Please enter \n", 1);
	putstr_fd("./fractol mandelbrot\n", 1);
	putstr_fd("./fractol julia <value_1> <value_2>\n", 1);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia_x = atodbl(argv[2]);
			fractal.julia_y = atodbl(argv[3]);
		}
		else
		{
			fractal.julia_x = 0;
			fractal.julia_y = 0;
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
        print_message();
	return (EXIT_SUCCESS);
}