/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:39:28 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/11/05 18:28:50 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

/*t_vect	get_sphere_normale()
{

}*/

 int	sphere_intersect(t_ray *ray, t_sphere sphere, t_params *params)
{
    t_vect	p;
	t_vect	d;
	t_vect	oc;
	double	b;
	double	c;
	double	t0;
	double	t1;
	double	disc;

	p = ray->origin;

	/*const Vec3 d = ray.d;*/

	d = ray->direction;

	/*const Vec3 oc = o - c;*/

	oc.vect_x = p.vect_x  - sphere.center.vect_x;
	oc.vect_y = p.vect_y  - sphere.center.vect_y;
	oc.vect_z = (p.vect_z - params->eye.view_dist) - sphere.center.vect_z;

    b = 2 * dot_product(oc, d);
    c = dot_product(oc, oc) - (sphere.rayon * sphere.rayon);
    disc = b * b - 4 * c;
    /*if (disc < 1e-4) */
    if (disc < 0)
		return (0);
    /*disc = sqrt(disc) / 2;*/
    disc = sqrt(disc);
    t0 = -b - disc;
    t1 = -b + disc;
    ray->t = (t0 < t1) ? t0 : t1;
	params->ray_depth = ray->t;
	/*get normal*/
    return (1);
}
