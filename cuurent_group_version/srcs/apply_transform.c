/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 09:25:00 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/16 10:12:41 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void    translate_sphere(t_sphere *sphere, t_vect translation)
{
    sphere->center.vect_x += translation.vect_x;
    sphere->center.vect_y += translation.vect_y;
    sphere->center.vect_z += translation.vect_z;
}

void    translate_cone(t_cone *cone, t_vect translation)
{
    cone->center.vect_x += translation.vect_x;
    cone->center.vect_y += translation.vect_y;
    cone->center.vect_z += translation.vect_z;
}

void    translate_cylinder(t_cylinder *cylinder, t_vect translation)
{
    cylinder->center.vect_x += translation.vect_x;
    cylinder->center.vect_y += translation.vect_y;
    cylinder->center.vect_z += translation.vect_z;
}
