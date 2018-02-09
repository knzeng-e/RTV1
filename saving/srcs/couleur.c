/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   couleur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 07:39:00 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/02/06 12:18:16 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	clamp(int *r, int *g, int *b)
{
	*r = ( *r > 255) ? 255 : *r;
	*g = ( *g > 255) ? 255 : *g;
	*r = ( *b > 255) ? 255 : *b;
}

int	couleur(double intensity)
{
	int	r;
	int	g;
	int	b;

	r = 127.5 * cos(intensity) + 1;
	g = 127.5 * sin(intensity) + 1;
	b = 127.5 * (1 - cos(intensity));
	//clamp(&r, &g, &b);
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

int	get_color(int r, int g, int b)
{
	int	result;

	result = 0;
	result += r << 16;
	result += g << 8;
	result += b;
	return (result);
}
