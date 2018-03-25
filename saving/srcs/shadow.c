#include "rt_v1.h"

char	*get_item(int obj_item)
{
	char	*output;

	output = "";
	if (obj_item == 1)
		output = "SPHERE";
	if (obj_item == 2)
		output = "PLANE";
	if (obj_item == 3)
		output = "CYLINDER";
	if (obj_item == 4)
		output = "CONE";
	if (obj_item == 5)
		output = "LIGHT";
	return (output);
}

int	is_shadowed(t_vect intersection, t_params *params, t_object *obj)
{
	int			output;
	int			index_light;
	double		length;
	double		t_min;
	t_ray		shadow_ray;
	t_object	*current_obj;
	t_vect		saved_normal;

	current_obj = params->objects;
	output = 0;
	t_min = MAX_DISTANCE;
	while (current_obj)
	{
		if (current_obj->id != obj->id && current_obj->item != LIGHT)
		{
		//	if (obj->item == PLANE)
				//printf("\t%s and %s", get_item(current_obj->item), get_item(obj->item));
			index_light = -1;
			while (++index_light < NB_LIGHTS)
			{
				params->other_intersect = 0;
				shadow_ray.origin = intersection;
				shadow_ray.direction = vect_sub(params->light[index_light].position, intersection);
				length = get_length(&shadow_ray.direction);
				//ray_normalize(&shadow_ray.direction);
				saved_normal = params->current_normal;
				if (intersect(&shadow_ray, current_obj, params))
				{
					if (t_min > shadow_ray.t)
						t_min = shadow_ray.t;
					params->current_normal = saved_normal;
					if (shadow_ray.t > length && params->other_intersect == 0)
						return (0);
				//	params->other_intersect = 0;
					////if (shadow_ray.t <= length)
						params->other_intersect = 1;
					return (1);
				}
				params->current_normal = saved_normal;
			}
		}
		current_obj = current_obj->next;
	}
	return (0);
}
