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

int	ft_is_number(char *nbr)
{
	int	index;

	index = 0;
	while (nbr[index])
	{
		if (ft_isdigit(nbr[index]) == 0)
			return (FALSE);
		index++;
	}
	return (TRUE);
}

int	get_sphere_position(t_params *params, char **list_params)
{
	int	sphere_position[3];
	int	index;

	index = 0;
	while (*list_params)
	{
		if (ft_is_number(*list_params) == FALSE)
			return (ERROR_OBJECT_DESCRIPTION);
		sphere_position[index] = ft_atoi(*list_params);
		index++;
		(*list_params)++;
	}
}


int	check_sphere_params(t_params *params)
{
	static int	cpt_params = 4; /* position, color, rayon, specular  */

		if (cpt_params <= 0)
			return (ERROR_NB_PARAMS);
		while (*(params->line_content))
		{
			if (ft_strcmp(*(params->line_content), "center:") || ft_strcmp(*(params->line_content), "position:"))
			{
				cpt_params--;
				(params->line_content)++;
				if (get_sphere_position(params, ft_strsplit(*(params->line_content), ',')) == 0)
					return (0);
			}
			ft_putstr("\n- ");
			ft_putstr(*(params->line_content));
			(params->line_content)++;
			ft_putchar('\n');
		}
}

int	check_plane_params(t_params *params)
{
	static int	cpt_params = 4; /* position, normal, color, specular */
}

int	check_cylinder_params(t_params *params)
{
	static int	cpt_params = 4; /* radius, specular, cposition, color */
}

int	check_cone_params(t_params *params)
{
	static int	cpt_params = 4; /* position, angle, specular, color */
}

int	check_light_params(t_params *params)
{
	static int	cpt_params = 3; /* position, intensity, type */
}
