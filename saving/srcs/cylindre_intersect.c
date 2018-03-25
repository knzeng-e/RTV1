/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 05:22:46 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/03/25 06:39:56 by knzeng-e         ###   ########.fr       */
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

int	cylinder_intersect(t_ray *ray, t_cylinder *cylinder, t_params *params)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	root;

	//ray_normalize(&ray->direction);
	a = ray->direction.vect_x * ray->direction.vect_x + ray->direction.vect_z * ray->direction.vect_z;
	b = ray->direction.vect_x * (ray->origin.vect_x - cylinder->center.vect_x) +
		ray->direction.vect_z * (ray->origin.vect_z - cylinder->center.vect_z);
	c = (ray->origin.vect_x - cylinder->center.vect_x) * (ray->origin.vect_x - cylinder->center.vect_x) +
		(ray->origin.vect_z - cylinder->center.vect_z) * (ray->origin.vect_z - cylinder->center.vect_z) -
		cylinder->radius * cylinder->radius;
	delta = b * b - a * c;
	if (delta > 0)
	{
		root = (-b - sqrt(delta)) / a;
		if (root <= 0)
			root = (-b + sqrt(delta)) / a;
		ray->t = root;
		save_intersection(ray);
		params->current_normal = get_normal_cylinder(ray->intersection, cylinder);
		return (IS_INTERSECTION);
	}
	return (NO_INTERSECTION);
}

