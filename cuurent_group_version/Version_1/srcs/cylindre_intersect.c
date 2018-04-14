/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 05:22:46 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/04 20:42:27 by neprocur         ###   ########.fr       */
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
	normal = set_vector(intersection.vect_x - base_tmp.vect_x, intersection.vect_y - base_tmp.vect_y, intersection.vect_z - base_tmp.vect_z);
	ray_normalize(&normal);
	return (normal);
}

int		cylinder_intersect(t_ray *ray, t_cylinder *cylinder, t_params *params)
{
	double	a;
	double	b;
	double	c;
	double	discr;
	double	root;
	t_vect	dist;

	dist = vect_sub(ray->origin, cylinder->center);
	ray_normalize(&cylinder->axe);
	a = dot_product(ray->direction, ray->direction) - pow(dot_product(ray->direction, cylinder->axe), 2);
	b = 2 * (dot_product(ray->direction, dist) - (dot_product(ray->direction, cylinder->axe) * dot_product(dist, cylinder->axe)));
	c = dot_product(dist, dist) - pow(dot_product(dist, cylinder->axe), 2) - pow(cylinder->size, 2);
	discr = b * b - 4 * a * c;
	if (discr > 0)
	{
		root = (-b - sqrt(discr)) / (2 * a);
		if (root <= 0)
			root = (-b + sqrt(discr)) / (2 * a);
		ray->t = root;
		save_intersection(ray);
		params->current_normal = get_normal_cylinder(ray->intersection, cylinder);
		return (IS_INTERSECTION);
	}
	return (NO_INTERSECTION);
}
