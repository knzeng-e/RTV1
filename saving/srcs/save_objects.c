/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 02:52:46 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/02/15 02:55:35 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	save_spheres(t_object *obj, t_params *params, int *cpt_objects)
{
	int			cpt_spheres;
	t_object	*last;

	cpt_spheres = -1;
	while (++cpt_spheres < NB_SPHERES)
	{
		while (obj != NULL)
		{
			last = obj;
			obj = obj->next;
		}
		obj = (last->is_set) ? (t_object *)malloc(sizeof(t_object)) : last;
		if (last->is_set)
			last->next = obj;
		if (obj == NULL)
		{
			ft_free(params);
			exit(MALLOC_ERROR);
		}
		set_sphere(obj, params, cpt_spheres);
		(*cpt_objects)++;
	}
}

void	save_planes(t_object *obj, t_params *params, int *cpt_objects)
{
	int			cpt_planes;
	t_object	*last;

	cpt_planes = -1;
	while (++cpt_planes < NB_PLANES)
	{
		while (obj != NULL)
		{
			last = obj;
			obj = obj->next;
		}
		obj = (last->is_set) ? (t_object *)malloc(sizeof(t_object)) : last;
		if (last->is_set)
			last->next = obj;
		if (obj == NULL)
		{
			ft_free(params);
			exit(MALLOC_ERROR);
		}
		set_plane(obj, params, cpt_planes);
		(*cpt_objects)++;
	}
}

void	save_lights(t_object *obj, t_params *params, int *cpt_objects)
{
	int			cpt_lights;
	t_object	*last;

	cpt_lights = -1;
	while (++cpt_lights < NB_LIGHTS)
	{
		while (obj != NULL)
		{
			last = obj;
			obj = obj->next;
		}
		obj = (last->is_set) ? (t_object *)malloc(sizeof(t_object)) : last;
		if (last->is_set)
			last->next = obj;
		if (obj == NULL)
		{
			ft_free(params);
			exit(MALLOC_ERROR);
		}
		set_light(obj, params, cpt_lights);
		(*cpt_objects)++;
	}
}
