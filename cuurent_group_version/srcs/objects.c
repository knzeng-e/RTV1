/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 23:42:39 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/15 23:29:18 by neprocur         ###   ########.fr       */
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
		ft_putstr("\t id == ");
		ft_putnbr(current_obj->id);
		ft_putchar('\n');
		current_obj = current_obj->next;
	}
	ft_putstr("\n NB_OBJECTS SAVED ==> ");
	ft_putnbr(cpt);
	ft_putstr("\n\n");
}
