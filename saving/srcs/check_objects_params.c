/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects_params.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 16:42:44 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/02/25 16:51:52 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

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
