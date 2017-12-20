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

void	save_intersection(t_ray *ray)
{
	double	x_intersect;
	double	y_intersect;
	double	z_intersect;

	/*ray = O + DIR * t*/;
	x_intersect = ray->origin.vect_x + ray->direction.vect_x * ray->t;
	y_intersect = ray->origin.vect_y + ray->direction.vect_y * ray->t;
	z_intersect = ray->origin.vect_z + ray->direction.vect_z * ray->t;
	set_vector(&ray->intersection, x_intersect, y_intersect, z_intersect);
}

 int	sphere_intersect(t_ray *ray, t_sphere sphere, t_params *params)
{
	t_vect	depth;
	double	b;
	double	c;
	double	t0;
	double	t1;
	double	disc;

	depth = substraction(ray->origin, sphere.center);
	//depth.vect_z = (p.vect_z - params->eye.view_dist) - sphere.center.vect_z;
    b = 2 * dot_product(depth, ray->direction);
    c = dot_product(depth, depth) - (sphere.rayon * sphere.rayon);
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
	save_intersection(ray);
	//tmpNormal = (intersect - mCenter) / mRadius;
	//params->current_normal = multiply_vect(substraction(ray->intersection, sphere.center), 1 / sphere.rayon);
	params->current_normal = divide_vect(substraction(ray->intersection, sphere.center), sphere.rayon);
	
	/*get normal*/
    return (1);
}
