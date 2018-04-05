#include "rt_v1.h"

int	get_obj_color(t_params *params, char **infos, int object_id)
{
	static int				color[3] = {-1, -1, -1};
	static int		nb_coord = -1;

	params += 0;
	if (++nb_coord < 3 /*&& *infos*/)
	{
		if (!ft_isnumber(*infos))
		{
			printf("\nNOT A NUMBER");
			fflush(stdout);
			return (ERROR_OBJECT_DESCRIPTION);
		}
		color[nb_coord] = ft_atoi(*infos);
		//infos++;
		//printf("\nNext coord ==> [%s]\n", *infos);
		//fflush(stdout);
	}
	if (nb_coord > 2)
	{
		return (ERROR_OBJECT_DESCRIPTION);
	}
	if ((nb_coord >= 2) && ((color[0] == -1) || color[1] == -1 || color[2] == -1 ))
		return (ERROR_OBJECT_DESCRIPTION);
	if (object_id == SPHERE)
	{
		printf("\nSetting Current Sphere index ==> %d", params->current_sphere_index);
		fflush(stdout);
		params->sphere_list[params->current_sphere_index++].color = rgb_to_int(color[0], color[1], color[2]);
		printf("\nSphere Color = [%d, %d, %d]\n", color[0], color[1], color[2]);
		fflush(stdout);
	
	}
	if (object_id == CONE)
	{
		//params->cone_list[params->current_cone_index++].color = rgb_to_int(color[0], color[1], color[2]);
	}
	if (object_id == CYLINDER)
	{
		//params->sphere_list[params->current_cylinder_index++].color = rgb_to_int(color[0], color[1], color[2]);
	}
	if (object_id == PLANE)
	{
		//params->sphere_list[params->current_plane_index++].color = rgb_to_int(color[0], color[1], color[2]);
	}
	if (object_id == LIGHT)
	{
		//params->sphere_list[params->current_light_index++].color = rgb_to_int(color[0], color[1], color[2]);
	}

	return (PARSE_OK);
}
