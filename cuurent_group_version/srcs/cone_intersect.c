/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 03:19:05 by neprocur          #+#    #+#             */
/*   Updated: 2018/04/16 04:28:15 by neprocur         ###   ########.fr       */
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

void	set_coeff(t_ray *ray, t_cone *cone, t_params *params, t_vect dist)
{
	params->a = dot_product(ray->direction, ray->direction) - \
				(1 + pow(tan(cone->size), 2)) * \
				pow(dot_product(ray->direction, cone->axe), 2);
	params->b = 2 * (dot_product(ray->direction, dist) - \
			(1 + pow(tan(cone->size), 2)) *
		dot_product(ray->direction, cone->axe) * dot_product(dist, cone->axe));
	params->c = dot_product(dist, dist) - (1 + pow(tan(cone->size), 2)) *
		pow(dot_product(dist, cone->axe), 2);
}

int		cone_intersect(t_ray *ray, t_cone *cone, t_params *params)
{
	t_vect	dist;
	double	rslt;

	dist = vect_sub(ray->origin, cone->center);
	ray_normalize(&cone->axe);
	set_coeff(ray, cone, params, dist);
	params->disc = params->b * params->b - 4 * params->a * params->c;
	if (params->disc > 0)
	{
		rslt = (-params->b - sqrt(params->disc)) / (2 * params->a);
		ray->t = (rslt > 0) ? rslt \
				: (-params->b + sqrt(params->disc)) / (2 * params->a);
		ray->t_max = (cone->hauteur > 0) ? cone->center.vect_y :\
			(cone->center.vect_y - cone->hauteur);
		ray->t_min = (cone->hauteur > 0) ? (cone->center.vect_y -\
				(cone->hauteur)) : (cone->center.vect_y);
		save_intersection(ray);
		params->current_normal = get_normal_cone(ray->intersection, cone);
		return (IS_INTERSECTION && ray->is_inter);
	}
	return (NO_INTERSECTION);
}
