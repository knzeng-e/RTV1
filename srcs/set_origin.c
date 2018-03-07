/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_origin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 09:57:49 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/11/25 04:07:44 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rt_v1.h"

void	set_origin(int i, int j, t_ray *ray, t_params *params)
{
	t_vect	view_pixel;

	params->eye.right_vect = multiply_vect(params->eye.right_vect, params->x_indent * i);
	params->eye.up_vect = multiply_vect(params->eye.up_vect, params->y_indent * j);
	view_pixel = addition(params->eye.view_left_up, substraction(params->eye.right_vect, params->eye.up_vect));
	params->eye.vect_dir = substraction(view_pixel, params->eye.cam_pos);
	ray_normalize(&params->eye.vect_dir);
	ray->origin.vect_x = i;
	ray->origin.vect_y = j;
	ray->origin.vect_z = 0;
	//ray->direction = params->eye.vect_dir;
	ray->direction.vect_x = 0;
	ray->direction.vect_y = 0;
	ray->direction.vect_z = 1;
	ray->t = 20000;
	ray->ray_normalize = ray_normalize;
	params->tab_rays[j][i] = ray;
	/*viewPlaneUpLeft + rightVec*xIndent*x - upVec*yIndent*y*/
}
