/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 05:22:46 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/11/25 07:41:43 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

t_vect	get_normal_cylinder(t_vect intersection, t_cylinder *cyl)
{
	t_vect	normal;
	t_vect	vect1;
	t_vect	vect2;

	vect1 = set_vector(intersection.vect_x, 0, intersection.vect_z);
	vect2 = set_vector(cyl->center.vect_x, 0, cyl->center.vect_y);
	normal = vect_add(vect1, vect2);
	ray_normalize(&normal);
	return (normal);
}

int	cylinder_intersect(t_ray *ray, t_cylinder *cyl, t_params *params)
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	rslt;

	a = pow(ray->direction.vect_x, 2) + pow(ray->direction.vect_z, 2);
	b = (2 * (ray->direction.vect_x * (ray->origin.vect_x - cyl->center.vect_x))) +
		(2 * (ray->direction.vect_z * (ray->origin.vect_z - cyl->center.vect_z)));
	c = pow(ray->origin.vect_x - cyl->center.vect_x, 2) +
		pow(ray->origin.vect_z - cyl->center.vect_z, 2) -
		cyl->radius * cyl->radius;
	d = b * b - 4 * a * c;
	if (d > 0)
	{
		rslt = ((-b - sqrt(d)) / (2 * a)) - 0.000001 > 0 ?
			(-b - sqrt(d)) / (2 * a) - 0.000001 :
			(-b + sqrt(d)) / (2 * a) - 0.000001;
		ray->t = rslt;
		save_intersection(ray);
		params->current_normal = get_normal_cylinder(ray->intersection, cyl);
		return (IS_INTERSECTION);
	}
	return (NO_INTERSECTION);

}
