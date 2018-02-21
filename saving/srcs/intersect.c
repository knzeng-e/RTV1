/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 04:36:51 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/02/15 13:10:57 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int	intersect(t_ray *ray, t_object *obj, t_params *params)
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
