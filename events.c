/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarneir <ecarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:52:26 by ecarneir          #+#    #+#             */
/*   Updated: 2025/12/07 20:01:33 by ecarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <X11/keysym.h>

/*
** Close the window cleanly.
*/
int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
	return (0);
}

/*
** Handles ESC
*/
int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	return (0);
}

/*
** Deals with Zoom (Scroll)
** Button 4: Zoom In
** Button 5: Zoom Out
*/
int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		fractal->zoom *= 0.95;
	}
	else if (button == 5)
	{
		fractal->zoom *= 1.05;
	}
	fractal_render(fractal);
	return (0);
}