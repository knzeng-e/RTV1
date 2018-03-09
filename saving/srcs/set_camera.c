/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:07:38 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/03/09 22:07:56 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	set_camera(t_ray *ray, t_params *params, int i, int j)
{
	t_vect	p_camera_space;
	double	pix_norm_x;
	double	pix_norm_y;
	double	image_aspect_ratio;
	double	pix_remap_x;
	double	pix_remap_y;
	double	pix_camera_x;
	double	pix_camera_y;

	pix_norm_x = (i + 0.5) / WIDTH; //Normalize Pix_dimension to [0;1]
	pix_norm_y = (j + 0.5) / HEIGHT;
	image_aspect_ratio = WIDTH/ HEIGHT;
	pix_remap_x = (2 * pix_norm_x - 1) * image_aspect_ratio;
	pix_remap_y = 1 - 2 * pix_norm_y;
	pix_camera_x = pix_remap_x * tan(radians(params->fov) / 2); // FOV 30 degrees
	pix_camera_y = pix_remap_y * tan(radians(params->fov) / 2);
	p_camera_space = set_vector(pix_camera_x, pix_camera_y, -1);
	ray->direction = vect_sub(p_camera_space, ray->origin);
	ray_normalize(&ray->direction);
}

void	set_camera_look_at(t_ray *ray, t_params *params, t_vect *from, t_vect *to)
{
	t_vect	arbitrary_vect;

	arbitrary_vect = set_vector(0, 1, 0);
	//ray_normalize(&arbitrary_vect);
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
	ray->direction = vect_multiply(params->eye.forward_vect, -1);
	
	/*t_vect	p_camera_space;
	  double	pix_norm_x;
	  double	pix_norm_y;
	  double	image_aspect_ratio;
	  double	pix_remap_x;
	  double	pix_remap_y;
	  double	pix_camera_x;
	  double	pix_camera_y;

	  pix_norm_x = (i + 0.5) / WIDTH; //Normalize Pix_dimension to [0;1]
	  pix_norm_y = (j + 0.5) / HEIGHT;
	  image_aspect_ratio = WIDTH/ HEIGHT;
	  pix_remap_x = (2 * pix_norm_x - 1) * image_aspect_ratio;
	  pix_remap_y = 1 - 2 * pix_norm_y;
	  pix_camera_x = pix_remap_x * tan(radians(params->fov) / 2); // FOV 30 degrees
	  pix_camera_y = pix_remap_y * tan(radians(params->fov) / 2);
	  p_camera_space = set_vector(pix_camera_x, pix_camera_y, -1);
	  ray->direction = vect_sub(p_camera_space, ray->origin);
	  ray_normalize(&ray->direction);*/
}
