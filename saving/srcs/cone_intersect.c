#include "rt_v1.h"

t_vect	get_normal_cone(t_vect intersection, t_cone *cone)
{
	t_vect	v;

	v = vect_multiply(cone->center, -1);
	v = vect_add(intersection, v);
	ray_normalize(&v);
	return (v);
}

/*int		cone_intersect(t_ray *ray, t_cone *cone, t_params *params)
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	rslt;

	a = pow(cos(cone->angle), 2) * pow((ray->direction.vect_x + ray->direction.vect_z), 2) - pow(sin(cone->angle), 2) * pow(ray->direction.vect_y, 2);
	b = 2 * pow(cos(cone->angle), 2) *
		(ray->direction.vect_x * (ray->origin.vect_x - cone->center.vect_x) +
		 ray->direction.vect_z * (ray->origin.vect_z - cone->center.vect_z)) -
		2 * pow(sin(cone->angle), 2) *
		ray->direction.vect_y * (ray->origin.vect_y - cone->center.vect_y);
	c = pow(cos(cone->angle), 2) *
		pow(ray->origin.vect_x - cone->center.vect_x + ray->origin.vect_z - cone->center.vect_z, 2)
		- pow(sin(cone->angle), 2) *
		pow(ray->origin.vect_y - cone->center.vect_y, 2);
	d = b * b - 4 * a * c;
	if (d > 0)
	{
		rslt = (-b - sqrt(d)) / (a);
		if (rslt > 0)
			ray->t = rslt;
		else
			ray->t = (-b + sqrt(d)) / (a);
		ray->t = rslt;
		save_intersection(ray);
		params->current_normal = get_normal_cone(ray->intersection, cone);
		return (IS_INTERSECTION);
	}
	return (NO_INTERSECTION);
}*/

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
