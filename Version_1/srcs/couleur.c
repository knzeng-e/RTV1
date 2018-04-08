/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   couleur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 07:39:00 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/04 20:40:56 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	clamp(int *r, int *g, int *b)
{
	*r = ( *r > 255) ? 255 : *r;
	*g = ( *g > 255) ? 255 : *g;
	*r = ( *b > 255) ? 255 : *b;
}

int		rgb_to_int(int r, int g, int b)
{
	int	color;

	r = (r > 255) ? 255 : ((r < 0) ? 0 : r);
	g = (g > 255) ? 255 : ((g < 0) ? 0 : g);
	b = (b > 255) ? 255 : ((b < 0) ? 0 : b);
	color = (256 * 256 * r) + (256 * g) + b;
	return (color);
}

t_color	get_rgb(int color)
{
	t_color	rgb;
	
	rgb.red = color / (256 * 256);
	rgb.green = color / 256 % 256 * 256;
	rgb.blue = color % 256;
	return (rgb);
}

int	couleur(double intensity)
{
	int	r;
	int	g;
	int	b;

	r = 127.5 * cos(intensity) + 1;
	g = 127.5 * sin(intensity) + 1;
	b = 127.5 * (1 - cos(intensity));
	return (RGB(r, g, b));
}

int		calc_color(int color, double i)
{
	double	r;
	double	g;
	double	b;

	b = (color % 256);
	r = (color / (256 * 256));
	g = (color / 256) - r * 256;
	b =  b * i;
	r =  r * i;
	g =  g * i;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return (RGB(r, g, b));
}

int	get_color(t_color color)
{
	return (rgb_to_int(color.red, color.green, color.blue));
}
