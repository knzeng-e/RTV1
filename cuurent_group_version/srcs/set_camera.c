/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:07:38 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/16 04:40:25 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	set_camera_look_at(t_ray *ray, t_params *params, t_vect *from,\
		t_vect *to)
{
	params->eye.forward_vect = vect_sub(*to, *from);
	ray_normalize(&(params->eye.forward_vect));
	params->eye.right_vect = cross_product(params->eye.orientation,\
			params->eye.forward_vect);
	params->eye.up_vect = cross_product(params->eye.forward_vect,\
			params->eye.right_vect);
	params->eye.cam_to_world.mat[0][0] = params->eye.right_vect.vect_x;
	params->eye.cam_to_world.mat[0][1] = params->eye.right_vect.vect_y;
	params->eye.cam_to_world.mat[0][2] = params->eye.right_vect.vect_z;
	params->eye.cam_to_world.mat[0][3] = 0;
	params->eye.cam_to_world.mat[1][0] = params->eye.up_vect.vect_x;
	params->eye.cam_to_world.mat[1][1] = params->eye.up_vect.vect_y;
	params->eye.cam_to_world.mat[1][2] = params->eye.up_vect.vect_z;
	params->eye.cam_to_world.mat[1][3] = 0;
	params->eye.cam_to_world.mat[2][0] = params->eye.forward_vect.vect_x;
	params->eye.cam_to_world.mat[2][1] = params->eye.forward_vect.vect_y;
	params->eye.cam_to_world.mat[2][2] = params->eye.forward_vect.vect_z;
	params->eye.cam_to_world.mat[2][3] = 0;
	params->eye.cam_to_world.mat[3][0] = from->vect_x;
	params->eye.cam_to_world.mat[3][1] = from->vect_y;
	params->eye.cam_to_world.mat[3][2] = from->vect_z;
	params->eye.cam_to_world.mat[3][3] = 1;
	ray->origin = *from;
}

void	set_camera(t_ray *ray, t_params *params, int i, int j)
{
	t_vect	p_camera_space;
	t_view	view;

	set_camera_look_at(ray, params, &params->eye.from, &params->eye.to);
	view.pix_norm_x = (i + 0.5) / WIDTH;
	view.pix_norm_y = (j + 0.5) / HEIGHT;
	view.image_aspect_ratio = WIDTH / HEIGHT;
	view.pix_remap_x = (1 - 2 * view.pix_norm_x) * view.image_aspect_ratio;
	view.pix_remap_y = 1 - 2 * view.pix_norm_y;
	view.pix_camera_x = view.pix_remap_x * tan(radians(params->fov) / 2);
	view.pix_camera_y = view.pix_remap_y * tan(radians(params->fov) / 2);
	p_camera_space = vect_add(vect_add(vect_multiply(params->eye.right_vect,\
		view.pix_camera_x), vect_multiply(params->eye.up_vect, \
			view.pix_camera_y)),\
		vect_add(params->eye.from, params->eye.forward_vect));
	ray->direction = vect_sub(p_camera_space, params->eye.from);
	ray_normalize(&ray->direction);
}
