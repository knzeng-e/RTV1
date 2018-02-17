#include "rt_v1.h"

int	is_shadowed(t_vect intersection, t_params *params, t_object *obj)
{
	t_ray		shadow_ray;
	t_object	*current_obj;
	int			output;
	int			index_light;
	int			save_intersect;

	current_obj = params->objects;
	output = 0;
	while (current_obj)
	{
		if (current_obj->id != obj->id)
		{
			index_light = -1;
			while (++index_light < NB_LIGHTS)
			{
				shadow_ray.origin = intersection;
				shadow_ray.direction = vect_sub(params->light[index_light].position, intersection);
				ray_normalize(&shadow_ray.direction);
				save_intersect = params->ray_depth;
				if (intersect(&shadow_ray, current_obj, params))
				{
					params->ray_depth = save_intersect;
					return (1);
				}
				params->ray_depth = save_intersect;
			}
			current_obj = current_obj->next;
		}
		else
			current_obj = current_obj->next;
	}
	return (0);
}

