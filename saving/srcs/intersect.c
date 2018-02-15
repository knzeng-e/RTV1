/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 04:36:51 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/02/15 06:19:59 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int	intersect(t_ray *ray, t_object *obj, t_params *params)
{
	if (obj->item == SPHERE)
		return (sphere_intersect(ray, *(obj->type.sphere), params));
	//if (obj->item == PLANE)
	return (plane_intersect(ray, obj->type.plane, params));
	//return (0);
}
