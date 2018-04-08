/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 20:44:21 by neprocur          #+#    #+#             */
/*   Updated: 2018/04/04 20:44:45 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int	get_obj_color(t_params *params, char **infos, int object_id)
{
	int				color[3];
	static int		nb_coord = -1;

	params += 0;
	if (*infos && ++nb_coord < 3)
	{
		printf("\nSAVING ==> [%s] && nb_coord == %d\n", *infos, nb_coord);
		fflush(stdout);
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
	printf("\nNB_COORDS output == %d\n", nb_coord);
	if (nb_coord > 2)
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
