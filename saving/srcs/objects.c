/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 23:42:39 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/02/15 01:55:48 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	save_spheres(t_object *current_obj, t_params *params, int *cpt_objects)
{
	int			cpt_spheres;
	t_object	*last;

	cpt_spheres = -1;
	while (++cpt_spheres < NB_SPHERES)
	{
		while (current_obj != NULL)
		{
			last = current_obj;
			current_obj = current_obj->next;
		}
		if (last->is_set)
		{
			current_obj = (t_object *)malloc(sizeof(t_object));
			last->next = current_obj;
		}
		else
			current_obj = last;
		if (current_obj == NULL)
		{
			ft_free(params);
			exit(MALLOC_ERROR);
		}
		current_obj->type.sphere = &params->sphere_list[cpt_spheres];
		current_obj->item = SPHERE;
		current_obj->position = params->sphere_list[cpt_spheres].center;
		current_obj->color = get_rgb(params->sphere_list[cpt_spheres].color);
		current_obj->is_set = 1;
		current_obj->next = NULL;
		(*cpt_objects)++;
	}
}

void	save_planes(t_object *current_obj, t_params *params, int *cpt_objects)
{
	int			cpt_planes;
	t_object	*last;

	cpt_planes = -1;
	while (++cpt_planes < NB_PLANES)
	{
		while (current_obj != NULL)
		{
			last = current_obj;
			current_obj = current_obj->next;
		}
		if (last->is_set)
		{
			current_obj = (t_object *)malloc(sizeof(t_object));
			last->next = current_obj;
		}
		else
			current_obj = last;
		if (current_obj == NULL)
		{
			ft_free(params);
			exit(MALLOC_ERROR);
		}
		current_obj->type.plane = &params->plane_list[cpt_planes];
		current_obj->item = PLANE;
		current_obj->position = params->plane_list[cpt_planes].position;
		current_obj->color = get_rgb(params->plane_list[cpt_planes].color);
		current_obj->next = NULL;
		(*cpt_objects)++;
	}
}

void	show_object_type(t_object *current_obj)
{
	if (current_obj->item == SPHERE)
		ft_putstr("\nSPHERE\n");
	if (current_obj->item == PLANE)
		ft_putstr("\nPLANE\n");
	if (current_obj->item == CYLINDER)
		ft_putstr("\nCYLINDER\n");
	if (current_obj->item == CONE)
		ft_putstr("\nCONE\n");
	if (current_obj->item == LIGHT)
		ft_putstr("\nLIGHT\n");
}

void	print_objects(t_object *objects)
{
	t_object	*current_obj;
	int			cpt;

	cpt = 0;
	current_obj = objects;
	while (current_obj)
	{
		++cpt;
		show_object_type(current_obj);
		current_obj = current_obj->next;
	}
	ft_putstr("\n NB_OBJECTS SAVED ==> ");
	ft_putnbr(cpt);
	ft_putstr("\n\n");
}

void	init_objects(t_params *params)
{
	int			cpt;
	t_object	*current_obj;
	t_object	**head;

	cpt = -1;
	while (++cpt < NB_OBJECTS)
	{
		current_obj = params->objects;
		head = &params->objects;
		save_spheres(current_obj, params, &cpt);
		//print_objects(params->objects);
		save_planes(current_obj, params, &cpt);
	}
	current_obj = NULL;
	print_objects(params->objects);
}
