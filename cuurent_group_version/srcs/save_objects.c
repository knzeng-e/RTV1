/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 02:52:46 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/16 00:50:22 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	save_spheres(t_object *obj, t_params *params, int *cpt_objects)
{
	int			cpt_spheres;
	t_object	*last;

	cpt_spheres = -1;
	while (++cpt_spheres < params->nb_spheres)
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
			free(params);
			exit(MALLOC_ERROR);
		}
		params->current_index = *cpt_objects;
		set_sphere(obj, params, cpt_spheres);
		(*cpt_objects)++;
	}
}

void	save_planes(t_object *obj, t_params *params, int *cpt_objects)
{
	int			cpt_planes;
	t_object	*last;

	cpt_planes = -1;
	while (++cpt_planes < params->nb_planes)
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
			free(params);
			exit(MALLOC_ERROR);
		}
		params->current_index = *cpt_objects;
		set_plane(obj, params, cpt_planes);
		(*cpt_objects)++;
	}
}

void	save_lights(t_object *obj, t_params *params, int *cpt_objects)
{
	int			cpt_lights;
	t_object	*last;

	cpt_lights = -1;
	while (++cpt_lights < params->nb_lights)
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
			free(params);
			exit(MALLOC_ERROR);
		}
		params->current_index = *cpt_objects;
		set_light(obj, params, cpt_lights);
		(*cpt_objects)++;
	}
}

void	save_cylinders(t_object *obj, t_params *params, int *cpt_objects)
{
	int			cpt_cylinders;
	t_object	*last;

	cpt_cylinders = -1;
	while (++cpt_cylinders < params->nb_cylinders)
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
			free(params);
			exit(MALLOC_ERROR);
		}
		params->current_index = *cpt_objects;
		set_cylinder(obj, params, cpt_cylinders);
		(*cpt_objects)++;
	}
}

void	save_cones(t_object *obj, t_params *params, int *cpt_objects)
{
	int			cpt_cones;
	t_object	*last;

	cpt_cones = -1;
	while (++cpt_cones < params->nb_cones)
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
			free(params);
			exit(MALLOC_ERROR);
		}
		params->current_index = *cpt_objects;
		set_cone(obj, params, cpt_cones);
		(*cpt_objects)++;
	}
}
