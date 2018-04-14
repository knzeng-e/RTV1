/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 20:40:08 by neprocur          #+#    #+#             */
/*   Updated: 2018/04/04 20:40:13 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

t_vect	get_normal_cone(t_vect intersection, t_cone *cone)
{
	t_vect	v;

	v = vect_multiply(cone->center, -1);
	v = vect_add(intersection, v);
	ray_normalize(&v);
	return (v);
}

int		cone_intersect(t_ray *ray, t_cone *cone, t_params *params)
{
	t_vect	dist;
	double	a;
	double	b;
	double	c;
	double	disc;
	double	rslt;

	dist = vect_sub(ray->origin, cone->center);
	ray_normalize(&cone->axe);
	a = dot_product(ray->direction, ray->direction) - (1 + pow(tan(cone->size), 2)) *
		pow(dot_product(ray->direction, cone->axe), 2);
	b = 2 * (dot_product(ray->direction, dist) - (1 + pow(tan(cone->size), 2)) *
			dot_product(ray->direction, cone->axe) * dot_product(dist, cone->axe));
	c = dot_product(dist, dist) - (1 + pow(tan(cone->size), 2)) *
		pow(dot_product(dist, cone->axe), 2);
	disc = b * b - 4 * a * c;
	if (disc > 0)
	{
		rslt = (-b - sqrt(disc)) / (2 * a);
		if (rslt > 0)
			ray->t = rslt;
		else
			ray->t = (-b + sqrt(disc)) / (2 * a);
		ray->t = rslt;
		save_intersection(ray);
		params->current_normal = get_normal_cone(ray->intersection, cone);
		return (IS_INTERSECTION);
	}
	return (NO_INTERSECTION);
}
