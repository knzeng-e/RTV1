/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   couleur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 07:39:00 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/16 07:41:11 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

t_color	set_color(double red, double green, double blue)
{
	t_color	color;

	color.red = red;
	color.green = green;
	color.blue = blue;
	return (color);
}

int		rgb_to_int(int r, int g, int b)
{
	int	color;
	int	red;
	int	green;
	int	blue;

	red = ((r < 0) ? 0 : r);
	green = ((g < 0) ? 0 : g);
	blue = ((b < 0) ? 0 : b);
	r = ((r > 255) ? 255 : red);
	g = ((g > 255) ? 255 : green);
	b = ((b > 255) ? 255 : blue);
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

int		get_color(t_color color)
{
	return (rgb_to_int(color.red, color.green, color.blue));
}
