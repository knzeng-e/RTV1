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
	int	partie_entiere;
	int	fraction;
	int	cpt;
	int	index;
	int	has_dot;
	double	coord[3];

	nb_coord = 0;
	has_dot = 0;
	while (*infos && nb_coord < 3)
	{
		has_dot = 0;
		if (*infos)
		{
			cpt = 0;
			while ((*infos)[i])
			{
				if ((*infos)[i] == '.' || (*infos)[i] == ',')
				{
					if (has_dot)	/* Error If there is double dot/comma */
						return (0);
					has_dot = 1;
				}
				if (!ft_isdigit((*infos)[i]) && (*infos)[i] != '.' && (*infos)[i] != ',')
					return (0);
				i++;
			}
			vect_x = ft_atoi(*infos);
		}
		else
			return (0);
		infos++;
		nb_coord++;
	}
	if (nb_coord != 2)
		return (0);
	return (1);
}
