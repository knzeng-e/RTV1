/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 04:12:55 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/03/26 05:40:31 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

double	shading(t_ray *ray, t_params *params)
{
	t_object	*light;
	double		angle;
	double		lightning;

	lightning = 0;
	light = params->objects;
	while (light && light->item != LIGHT)
		light = light->next;
	while (light && light->item == LIGHT)
	{
		params->current_light.intensity = light->specular;
		params->light_vector = vect_sub(light->position, ray->intersection);
		params->distance_to_light = get_length(&params->light_vector);
		ray_normalize(&params->light_vector);
		ray_normalize(&params->current_normal);
		angle = dot_product(params->current_normal, params->light_vector);
		if (angle < 0)
			angle = 0;
		lightning += (DIFFUSE_LIGHT * angle) + get_specular(params->current_normal, ray, params);
		light = light->next;
	}
	return (lightning);
}
