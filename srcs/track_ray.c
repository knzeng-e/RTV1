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
	t_vect	light_vector;
	double	angle;
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
			ray->ray_normalize(&ray->direction);
			//ray_normalize(&ray->direction);
			if (plane_intersect(ray, (params->plane), params))
				draw_pixel(params, i, j, 0x004E1609);
			if (sphere_intersect(ray, params->sphere2, params))
			{
			light_vector = substraction(ray->intersection, params->light[0].position);
			ray_normalize(&light_vector);
			angle = dot_product(params->current_normal, light_vector);
			if (angle > 0)
				draw_pixel(params, i, j, 0x000000FF * AMBIANT_LIGHT * angle);
				else
				draw_pixel(params, i, j, 0x000000FF * AMBIANT_LIGHT);
				}
			else if (sphere_intersect(ray, params->sphere3, params))
			{
			light_vector = substraction(ray->intersection, params->light[0].position);
			ray_normalize(&light_vector);
			angle = dot_product(params->current_normal, light_vector);
			if (angle > 0)
				draw_pixel(params, i, j, 0x000000FF * AMBIANT_LIGHT * angle);
				else
				draw_pixel(params, i, j, 0x000000FF * AMBIANT_LIGHT);
				}
			/*	draw_pixel(params, i, j, 0x000000FF * AMBIANT_LIGHT * angle);
			else if (sphere_intersect(ray, params->sphere, params))
				draw_pixel(params, i, j, 0x000000FF * AMBIANT_LIGHT * angle);*/
			/*else
				draw_pixel(params, i, j, 0x00CECECE);*/
			j++;
		//	printf("\nRay Direction1:\n\tx = %f\ty = %f\tz = %f", ray->direction.vect_x, ray->direction.vect_y, ray->direction.vect_z);
		}
			//printf("\nRay Direction 2:\n\tx = %f\ty = %f\tz = %f", ray->direction.vect_x, ray->direction.vect_y, ray->direction.vect_z);
		i++;
	}
	return (0);
}
