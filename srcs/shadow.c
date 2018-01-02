#include "rt_v1.h"

int	is_shadowed(t_vect intersection, t_light light, t_params *params)
{
	int		output;
	t_ray	ray;

	ray.origin = intersection;
	ray.direction = substraction(light.position, intersection);
	ray_normalize(&ray.direction);
	output = 0;
	if (sphere_intersect(&ray, params->sphere2, params) /*|| sphere_intersect(&ray, params->sphere, params)*/)
		output = 1;
	return (output);
}

