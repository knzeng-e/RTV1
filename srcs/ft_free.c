/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 03:55:12 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/11/08 08:46:08 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int	ft_free(t_params *params)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while(j < HEIGHT)
		{
			if (params->rays_to_free == 0)
			{
				free(params);
				return (0);
			}
			//free(&(params->tab_rays[j][i]));
			free(params->tab_rays[j][i]);
			params->rays_to_free--;
			j++;
		}
		i++;
	}
	free(params->transforms);
	free(params);
	return (1);
}
