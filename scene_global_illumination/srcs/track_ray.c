/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:42:53 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/09 20:55:21 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	 apply_transform(t_vect *vect, t_params *params)
{
	t_vect4	homogen;

	homogen = set_homogen(vect);
	//vect_matrx_multiply(&homogen, &params->eye.cam_to_world);
	*vect = set_reverse_homogen(&homogen);
	rotate_x_axis(&(params->current_ray.direction), params->rotation_val, &params->transforms);
	rotate_y_axis(&(params->current_ray.direction), params->rotation_val, &params->transforms);
	rotate_z_axis(&(params->current_ray.direction), params->rotation_val, &params->transforms);


	rotate_x_axis(&(params->current_ray.origin), params->rotation_val, &params->transforms);
	rotate_y_axis(&(params->current_ray.origin), params->rotation_val, &params->transforms);
	rotate_z_axis(&(params->current_ray.origin), params->rotation_val, &params->transforms);
}


int		track_ray(t_params *params)
{
    int			i;
    int			j;
    int         touched_obj;
    
    touched_obj = -1;
    i = -1;
    while (++i < WIDTH)
    {
        j = -1;
        while (++j < HEIGHT)
            touched_obj = throw_ray(params, &i, &j);
    }
    return (0);
}
