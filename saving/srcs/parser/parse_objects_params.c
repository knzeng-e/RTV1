/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects_params.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 16:42:40 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/02/25 19:07:55 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int	get_sphere_position(t_params *params, char **infos)
{
	int	i;
	int	i;
	int	has_dot;

	nb_coord = 0;
	has_dot = 0;
	while (*infos && nb_coord < 3)
	{
		has_dot = 0;
		if (*infos)
		{
			i = 0;
			while ((*infos)[i])
			{
				if ((*infos)[i] == '.' || (*infos)[i] == ',')
				{
					if (has_dot)	/* Error If there is double dot/comma */
						return (ERROR_OBJECT_DESCRIPTION);
					has_dot = 1;
				}
				if (!ft_isnumber((*infos)[i]) && (*infos)[i] != '.' && (*infos)[i] != ',')
					return (ERROR_OBJECT_DESCRIPTION);
				i++;
			}
			save_sphere_coord(params, *infos, &nb_coord);
		}
		else
			return (ERROR_OBJECT_DESCRIPTION);
		infos++;
		nb_coord++;
	}
	if (nb_coord != 2)
		return (ERROR_OBJECT_DESCRIPTION);
	return (CORRECT_OBJECT_DESCRIPTION);
}
