#include "rt_v1.h"

int	get_obj_color(t_params *params, char **infos, int object_id)
{
	int		color[3];
	int		nb_coord;

	params += 0;
	nb_coord = -1;
	while (*infos && ++nb_coord < 3)
	{
		if (!ft_isnumber(*infos))
			return (ERROR_OBJECT_DESCRIPTION);
		color[nb_coord] = ft_atoi(*infos);
		infos++;
	}
	if (nb_coord != 2)
		return (ERROR_OBJECT_DESCRIPTION);
	if (object_id == SPHERE)
	{
		//params->sphere_list[params->current_sphere_index++].color = rgb_to_int(color[0], color[1], color[2]);
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
