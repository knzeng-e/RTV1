/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:42:53 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/01/23 16:29:56 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	draw_pixel(t_params *params, int i, int j, int color)
{
	int	new_color;

	new_color = mlx_get_color_value(params->mlx, color);
	params->img_data[j  * WIDTH + i] = new_color;
}

int	track_ray(t_params *params)
{
	t_ray	*ray;
	t_vect	light_vector;
	double	normal;
	double	angle;
	double	length;
	int		i;
	int		j;

	length = 0;
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
			if (plane_intersect(ray, (params->v_plane), params))
			{

				light_vector = substraction(params->light[0].position, ray->intersection);
				length = get_length(&light_vector);
				normal = get_length(&params->v_plane->normale);
				ray_normalize(&light_vector);
				ray_normalize(&params->current_normal);
				angle = dot_product(params->v_plane->normale, light_vector);
				draw_pixel(params, i, j, 0x00FF0000 + 0x0000FF00 * angle * 0.5);
			}
			if (plane_intersect(ray, (params->plane), params))
			{

				light_vector = substraction(params->light[0].position, ray->intersection);
				length = get_length(&light_vector);
				normal = get_length(&params->plane->normale);
				ray_normalize(&light_vector);
				ray_normalize(&params->current_normal);
				angle = dot_product(params->plane->normale, light_vector);
				draw_pixel(params, i, j, 0x004E1609 + 0x000000FF * angle * 0.5);
			}
			if (sphere_intersect(ray, params->sphere2, params))
			{
				set_color(&params->sphere2.color, 0, 0, 0xFF);
				light_vector = substraction(params->light[0].position, ray->intersection);
				length = get_length(&light_vector);
				normal = get_length(&params->current_normal);
				ray_normalize(&light_vector);
				ray_normalize(&params->current_normal);
				angle = dot_product(params->current_normal, light_vector);
				draw_pixel(params, i, j, (get_color(params->sphere2.color)  + 0x000000FF * angle) * 0.5);
			}
			/*	else*/ if (sphere_intersect(ray, params->sphere3, params))
			{	

				set_color(&params->sphere3.color, 0, 0, 0xFF);
				light_vector = substraction(params->light[0].position, ray->intersection);
				length = get_length(&light_vector);
				normal = get_length(&params->current_normal);
				ray_normalize(&light_vector);
				ray_normalize(&params->current_normal);
				if (is_shadowed(ray->intersection, params->light[0], params))
					draw_pixel(params, i, j, (get_color(params->sphere3.color) * (AMBIANT_LIGHT)));
				else 
				{
					angle = dot_product(params->current_normal, light_vector);
					if (angle < 0)
						angle = 0;
					draw_pixel(params, i, j, (get_color(params->sphere3.color) * (AMBIANT_LIGHT + DIFFUSE_LIGHT * angle)));
					//draw_pixel(params, i, j, (get_color(params->sphere3.color)  + 0x000000FF * angle) * 0.5);
				}
			}
			/*	draw_pixel(params, i, j, 0x000000FF * AMBIANT_LIGHT * angle);
				else if (sphere_intersect(ray, params->sphere, params))
				draw_pixel(params, i, j, 0x000000FF * AMBIANT_LIGHT * angle);*/
			/*else
			  draw_pixel(params, i, j, 0x00CECECE);*/
			j++;
		}
		i++;
	}
	return (0);
}
