/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:03:58 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/03/07 23:06:49 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

double	radians(double angle)
{
	return (angle * M_PI / 180);
}

double	max(double nbre1, double nbre2)
{
	double	output;

	output = (nbre1 > nbre2) ? nbre1 : nbre2;
	return (output);
}

void	draw_pixel(t_params *params, int i, int j, int color)
{
	int				cpt;
	unsigned int	p;

	cpt = 0;
	p = i * (params->bpp / 8) + j * (params->size_line);
	while (cpt < (params->bpp / 8))
	{
		params->img_data[p + cpt] = color;
		color >>= 8;
		cpt++;
	}
}
