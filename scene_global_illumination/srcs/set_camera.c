/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:07:38 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/09 22:54:01 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	set_camera_look_at(t_ray *ray, t_params *params, t_vect *from, t_vect *to)
{
	t_vect	arbitrary_vect;

	arbitrary_vect = set_vector(0, 1, 0);
	params->eye.forward_vect = vect_sub(*to, *from);
	ray_normalize(&(params->eye.forward_vect));
	params->eye.right_vect = cross_product(arbitrary_vect, params->eye.forward_vect);
	params->eye.up_vect = cross_product(params->eye.forward_vect, params->eye.right_vect);
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
	//ray->direction = vect_multiply(params->eye.forward_vect, -1);
}

void	set_camera(t_ray *ray, t_params *params, int i, int j)
{
	t_vect	p_camera_space;
    t_vect4 quaternion;
	double	pix_norm_x;
	double	pix_norm_y;
	double	image_aspect_ratio;
	double	pix_remap_x;
	double	pix_remap_y;
	double	pix_camera_x;
	double	pix_camera_y;

	pix_norm_x = (i + 0.5) / WIDTH; //Normalize Pix_dimension to [0;1]
	pix_norm_y = (j + 0.5) / HEIGHT;
	pix_norm_x -= params->eye.to.vect_x;
	pix_norm_y -= params->eye.to.vect_y;
	image_aspect_ratio = WIDTH/ HEIGHT;
	pix_remap_x = (2 * pix_norm_x - 1) * image_aspect_ratio;
	pix_remap_y = 1 - 2 * pix_norm_y;
	pix_camera_x = pix_remap_x * tan(radians(params->fov) / 2); // FOV 30 degrees
	pix_camera_y = pix_remap_y * tan(radians(params->fov) / 2);
	p_camera_space = set_vector(pix_camera_x, pix_camera_y, -1);
	//apply reverse__cam_to_world
	//rotate_y_axis(&(params->eye.from), 90, &params->transforms);
	//rotate_z_axis(&(params->eye.from), 90, &params->transforms);
    set_translation(&params->transforms, 0, 6, 8);
    quaternion = set_homogen(&params->eye.from);
    //vect_matrx_multiply(&quaternion, &params->transforms.translation);
    //params->eye.from = set_reverse_homogen(&quaternion);
	//rotate_x_axis(&(params->eye.from), 10, &params->transforms);
	ray->direction = vect_sub(p_camera_space, ray->origin);
	//rotate_y_axis(&(ray->direction), 90, &params->transforms);
	//rotate_z_axis(&(ray->direction), 90, &params->transforms);
	//rotate_x_axis(&(ray->direction), 10, &params->transforms);
	//rotate_y_axis(&(ray->direction), params->rotation_val, &params->transforms);
	/*rotate_y_axis(&(ray->direction), 30, &params->transforms);
	rotate_z_axis(&(ray->direction), 30, &params->transforms);*/
	set_camera_look_at(ray, params, &params->eye.from, &params->eye.to);
	ray_normalize(&ray->direction);
}
