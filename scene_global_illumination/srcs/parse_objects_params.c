/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects_params.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 16:42:40 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/04 17:25:32 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int	get_sphere_position(t_params *params, char **infos)
{
	int	i;
	int nb_coord;
	int	has_dot;

	nb_coord = 0;
	has_dot = 0;
	while (*infos && nb_coord < 3)
	{
		printf("\nGetting Sphere position ==> in ");
		fflush(stdout);
		switch (nb_coord) {
			case 0 :
							printf(" x = %s\n", *infos);
							break;
			case  1:
							printf(" y = %s\n", *infos);
							break;

			case 2:
							printf(" z = %s\n", *infos);
							break;
		}
		has_dot = 0;
		if (*infos)
		{
			i = 0;
			while ((*infos)[i])
			{
				printf("\tprocessing => %c\n", (*infos)[i]);
				fflush(stdout);
				if ((*infos)[i] == '.' || (*infos)[i] == ',')
				{
					if (has_dot)	/* Error If there is double dot/comma */
						return (ERROR_OBJECT_DESCRIPTION);
					has_dot = 1;
				}
				printf("\tis %c a number ? ==> %d\n", (*infos)[i], ft_isnumber(&(*infos)[i]));
				fflush(stdout);
				if (!ft_isnumber(&(*infos)[i]) && (*infos)[i] != '.' && (*infos)[i] != ',')
					return (ERROR_OBJECT_DESCRIPTION);
				i++;
			}
			printf("\tEnregistrement de %s\n", *infos);
			fflush(stdout);
			save_sphere_coord(params, *infos, &nb_coord);
		}
		else
			return (ERROR_OBJECT_DESCRIPTION);
		infos++;
		nb_coord++;
		printf("OK\n");
	}
	if (*infos || nb_coord != 3)
		return (ERROR_OBJECT_DESCRIPTION);
	return (CORRECT_OBJECT_DESCRIPTION);
}
