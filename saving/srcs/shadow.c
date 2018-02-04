#include "rt_v1.h"

int	is_shadowed(t_vect intersection, t_params *params, int obj_id)
{
	t_ray	ray;
	int		output;
	int		cpt;

	cpt = -1;
	ray.origin = intersection;
	ray.direction = vect_sub(params->light[0].position, intersection);
	ray_normalize(&ray.direction);
	output = 0;
	while (++cpt < NB_SPHERES)
	{
		if ((cpt != obj_id) \
			&& sphere_intersect(&ray, params->sphere_list[cpt], params) /*|| sphere_intersect(&ray, params->sphere, params)*/)
			return (1);
	}
	return (output);
}

