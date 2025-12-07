/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarneir <ecarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:48:32 by ecarneir          #+#    #+#             */
/*   Updated: 2025/12/07 19:48:33 by ecarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define WIDTH	800
# define HEIGHT	800

/* Cores Psicodélicas (Hex) */
# define BLACK	0x000000
# define WHITE	0xFFFFFF
# define NEON_BLUE 0x00FFFF
# define FIRE_RED 0xFF4500
# define LIME_GREEN 0x32CD32

/*
** Complex Number Structure
** z = x + yi
*/
typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

/*
** Image Data Structure (MiniLibX requires this)
*/
typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

/*
** Main Fractal Structure
*/
typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_fractal;

/* Utils */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	putstr_fd(char *s, int fd);
double	atodbl(char *s);

/* Init */
void	fractal_init(t_fractal *fractal);

/* Render */
void	fractal_render(t_fractal *fractal);

/* Events */
int		key_handler(int keysym, t_fractal *fractal);
int		close_handler(t_fractal *fractal);
int		mouse_handler(int button, int x, int y, t_fractal *fractal);

#endif