/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 18:05:31 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/16 08:03:03 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int		ft_free(t_params *params)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			if (params->rays_to_free == 0)
			{
				free(params);
				return (0);
			}
			free(params->tab_rays[j][i]);
			params->rays_to_free--;
			j++;
		}
		i++;
	}
	free(params);
	return (1);
}

void	free_objects_list(t_params *params)
{
	t_object	**current_obj;

	current_obj = NULL;
	if (params->objects)
	{
		while (params->objects->next)
		{
			current_obj = &params->objects;
			params->objects = params->objects->next;
			free(*current_obj);
		}
	}
}
