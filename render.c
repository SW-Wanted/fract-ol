/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarneir <ecarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:59:01 by ecarneir          #+#    #+#             */
/*   Updated: 2025/12/07 19:59:02 by ecarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (x - WIDTH / 2.0) * (4.0 / WIDTH) * fractal->zoom + fractal->shift_x;
	z.y = (y - HEIGHT / 2.0) * (4.0 / HEIGHT) * fractal->zoom + fractal->shift_y;
	mandel_vs_julia(&z, &c, fractal);
	while (i < fractal->iterations_definition)
	{
		double temp_x = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = temp_x;
		if ((z.x * z.x + z.y * z.y) > fractal->escape_value)
		{
			color = 0x0000FF * i; // Cor baseada na iteração
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, BLACK);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}