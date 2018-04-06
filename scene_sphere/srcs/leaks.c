/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 18:05:31 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/01 23:35:05 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	free_lights(t_params *params)
{
	int	current_light;

	current_light = -1;
	while (++current_light < NB_LIGHTS)
		ft_putstr("\n Turning OFF Light");
	params->current_light_index = 0;
	ft_putstr("\nALL LIGHTS FREED!");
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
	ft_putstr("\nALL OBJECTS FREED!");
}
