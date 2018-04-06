#include "rt_v1.h"

void	save_sphere_coord(t_params *params, char *infos, int *nb_coord)
{
	int	current;

	current = params->current_sphere_index;
	if (*nb_coord == 0)
		params->sphere_list[current].center.vect_x = ft_atoi(infos);
	if (*nb_coord == 1)
		params->sphere_list[current].center.vect_y = ft_atoi(infos);
	if (*nb_coord == 2)
		params->sphere_list[current].center.vect_z = ft_atoi(infos);
}
