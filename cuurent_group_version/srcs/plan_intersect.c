/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 22:08:16 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/16 08:02:47 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int		intersect(t_ray *ray, t_object *obj, t_params *params)
{
	int	output;

	output = 0;
	if (obj->item == SPHERE)
		output = (sphere_intersect(ray, *(obj->type.sphere), params));
	if (obj->item == PLANE)
		output = (plane_intersect(ray, obj->type.plane, params));
	if (obj->item == CYLINDER)
		output = (cylinder_intersect(ray, obj->type.cylinder, params));
	if (obj->item == CONE)
		output = (cone_intersect(ray, obj->type.cone, params));
	return (output);
}

double	plane_normal(t_vect origin, t_vect direction)
{
	double	normal;

	normal = (-origin.vect_y / direction.vect_y);
	return (normal);
}

int		plane_intersect(t_ray *ray, t_plane *plane, t_params *params)
{
	double	angle;
	double	result;

	angle = dot_product(ray->direction, plane->normale);
	if (fabs(angle) < 1e-6)
		return (0);
	plane->distance = vect_sub(plane->position, ray->origin);
	params->current_normal = plane->normale;
	result = dot_product(plane->distance, plane->normale) / angle;
	params->ray_depth = result;
	if (result >= 0)
	{
		ray->t = result;
		save_intersection(ray);
	}
	return (result >= 0);
}
