/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 23:42:39 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/02/15 02:58:28 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

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
	ft_putstr("\n LIST OF OBJECTS SAVED");
	ft_putstr("\n =====================\n");
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
		save_planes(current_obj, params, &cpt);
		save_lights(current_obj, params, &cpt);
	}
	current_obj = NULL;
	print_objects(params->objects);
}