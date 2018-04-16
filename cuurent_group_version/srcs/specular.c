/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 08:01:56 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/16 02:40:30 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

double	get_specular(t_vect normal, t_ray *ray, t_params *params)
{
	double	specular;
	double	angle;
	t_vect	reflected_ray;
	t_vect	viewing_vector;

	specular = 0;
	viewing_vector = vect_multiply(ray->direction, -1);
	reflected_ray = vect_sub(vect_multiply(normal, \
				(2 * dot_product(normal, params->light_vector))),\
				params->light_vector);
	angle = dot_product(reflected_ray, viewing_vector);
	if (angle > 0)
		specular = params->current_light.intensity * \
		pow(angle / get_length(&reflected_ray) * get_length(&viewing_vector), \
		params->current_obj.specular);
	return (specular);
}
