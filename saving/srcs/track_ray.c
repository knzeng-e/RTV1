/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:42:53 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/11/25 03:44:33 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	draw_pixel(t_params *params, int i, int j, int color)
{
	params->img_data[j  * WIDTH + i] = color;
}

int	track_ray(t_params *params)
{
	t_ray	*ray;
	int		i;
	int		j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			ray = (t_ray *)malloc(sizeof(t_ray));
			if (ray == NULL)
				return (ft_free(params));
			params->rays_to_free++;
			set_origin(i, j, ray, params);
			if (!plane_intersect(ray, (params->plane), params))
				draw_pixel(params, i, j, 0x004E1609);
			if (sphere_intersect(ray, params->sphere2, params))
				draw_pixel(params, i, j, 0x000000FF);
			else if (sphere_intersect(ray, params->sphere3, params))
				draw_pixel(params, i, j, 0x0000FF00);
			else if (sphere_intersect(ray, params->sphere, params))
				draw_pixel(params, i, j, 0x00FFFF00);
			/*else
				draw_pixel(params, i, j, 0x00CECECE);*/
			j++;
		}
		i++;
	}
	return (0);
}
