/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects_params.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 16:42:44 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/03/01 14:46:39 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int	check_sphere_params(t_params *params)
{
	static int	cpt_params = NB_SPHERES_PARAMS; /* position, color, radius, specular  */

		if (cpt_params <= 0)
			return (ERROR_NB_PARAMS);
		while (*(params->line_content))
		{
			if (ft_strcmp(*(params->line_content), "center:") || ft_strcmp(*(params->line_content), "position:"))
			{
				cpt_params--;
				(params->line_content)++;
				if (get_sphere_position(params, ft_strsplit(*(params->line_content), ',')) == 0)
					return (ERROR_OBJECT_DESCRIPTION);
			}
			else if (ft_strcmp(*(params->line_content), "color:"))
			{
				cpt_params--;
				(params->line_content)++;
				if (get_obj_color(params, ft_strsplit(*(params->line_content), ','), SPHERE)  == 0)
					return (ERROR_OBJECT_DESCRIPTION);
			}
			else if (ft_strcmp(*(params->line_content), "radius:"))
			{
				cpt_params--;
				(params->line_content)++;
				/*Risque de pb ici: ++(params->line_content)*/
				if ((ft_isnumber(*(params->line_content)) == 0) || (++(params->line_content)))
					return (ERROR_OBJECT_DESCRIPTION);
					params->sphere_list[params->current_sphere_index].rayon = (double)ft_atoi(*(params->line_content));
			}
			else if (ft_strcmp(*(params->line_content), "specular:"))
			{
				cpt_params--;
				(params->line_content)++;
				/* get_specular */
				/*Risque de pb ici: ++(params->line_content)*/
				if ((ft_isnumber(*(params->line_content)) == 0) || (++(params->line_content)))
					return (ERROR_OBJECT_DESCRIPTION);
				params->sphere_list[params->current_sphere_index].specular = (double)ft_atoi(*(params->line_content));
			}




			ft_putstr("\n- ");
			ft_putstr(*(params->line_content));
			(params->line_content)++;
			ft_putchar('\n');
		}
		return (1);
}

int	check_plane_params(t_params *params)
{
	static int	cpt_params = 4; /* position, normal, color, specular */
	return (1);
}

int	check_cylinder_params(t_params *params)
{
	static int	cpt_params = 4; /* radius, specular, cposition, color */
	return (1);
}

int	check_cone_params(t_params *params)
{
	static int	cpt_params = 4; /* position, angle, specular, color */
	return (1);
}

int	check_light_params(t_params *params)
{
	static int	cpt_params = 3; /* position, intensity, type */
	return (1);
}
