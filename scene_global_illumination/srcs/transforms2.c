/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 15:39:06 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/13 20:08:45 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

t_vect  translate(t_vect *elm, t_vect translation, t_params *params)
{
    t_vect4 result;
    t_vect4 homogen_vect;

    printf("\nBefore Translattion fo (%f, %f, %f)", elm->vect_x, elm->vect_y, elm->vect_z);
    fflush(stdout);
    homogen_vect = set_homogen(elm);
    set_translation(&params->transforms, translation.vect_x, translation.vect_y, translation.vect_z);
    result = vect_matrx_multiply(&homogen_vect, &params->transforms.translation);
    *elm  = set_reverse_homogen(&result);
    printf("\nAfter Translattion fo (%f, %f, %f)", elm->vect_x, elm->vect_y, elm->vect_z);
    fflush(stdout);
    return (*elm);
}

t_vect  reverse_translate(t_vect *elm, t_vect translation, t_params *params)
{
    t_vect4  result;
    t_vect4 homogen_vect;

    homogen_vect = set_homogen(elm);
    set_translation(&params->transforms, translation.vect_x, translation.vect_y, translation.vect_z);
    result = vect_matrx_multiply(&homogen_vect, &params->transforms.translation);
    *elm  = set_reverse_homogen(&result);
    return (*elm);
}
