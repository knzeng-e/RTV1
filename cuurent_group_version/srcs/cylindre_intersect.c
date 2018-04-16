/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 05:22:46 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/16 05:09:40 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

t_vect	get_normal_cylinder(t_vect intersection, t_cylinder *cylinder)
{
	t_vect	base_tmp;
	t_vect	normal;
	t_vect	intersection_tmp;

	base_tmp = cylinder->center;
	intersection_tmp = intersection;
	base_tmp.vect_y = intersection_tmp.vect_y;
	normal = set_vector(intersection.vect_x - base_tmp.vect_x, \
		intersection.vect_y - base_tmp.vect_y, intersection.vect_z \
		- base_tmp.vect_z);
	ray_normalize(&normal);
	return (normal);
}

void	get_dist(t_params *params, t_cylinder *cylinder, t_ray *ray)
{
	ray->t = (-params->b - sqrt(params->disc)) / (2 * params->a);
	if (ray->t <= 0)
		ray->t = (-params->b + sqrt(params->disc)) / (2 * params->a);
	ray->t_max = (cylinder->hauteur > 0) ? cylinder->center.vect_y : \
		(cylinder->center.vect_y - cylinder->hauteur);
	ray->t_min = (cylinder->hauteur > 0) ? (cylinder->center.vect_y -\
			(cylinder->hauteur)) : (cylinder->center.vect_y);
}

int		cylinder_intersect(t_ray *ray, t_cylinder *cylinder, t_params *params)
{
	t_vect	dist;

	dist = vect_sub(ray->origin, cylinder->center);
	ray_normalize(&cylinder->axe);
	params->a = dot_product(ray->direction, ray->direction) - \
				pow(dot_product(ray->direction, cylinder->axe), 2);
	params->b = 2 * (dot_product(ray->direction, dist) - \
			(dot_product(ray->direction, cylinder->axe) * \
	dot_product(dist, cylinder->axe)));
	params->c = dot_product(dist, dist) - \
	pow(dot_product(dist, cylinder->axe), 2) - pow(cylinder->size, 2);
	params->disc = params->b * params->b - 4 * params->a * params->c;
	if (params->disc > 0)
	{
		get_dist(params, cylinder, ray);
		save_intersection(ray);
		params->current_normal = get_normal_cylinder(ray->intersection,\
				cylinder);
		return (IS_INTERSECTION && ray->is_inter);
	}
	return (NO_INTERSECTION);
}
