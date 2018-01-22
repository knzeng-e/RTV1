/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 11:08:52 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/11/25 03:17:28 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	create_sphere(t_params *params, double radius, double x, double y)
{
	int	cpt;

	x = x + 0;
	y = y + 0;
	cpt = -1;
	while (++cpt < NB_SPHERES)
		params->sphere_list[cpt].is_selected = 0;
	params->sphere_list[0].rayon = radius;
	params->sphere_list[0].center.vect_x = 0;
	params->sphere_list[0].center.vect_y = 0;
	params->sphere_list[0].center.vect_z = -20;
	params->sphere_list[0].color = YELLOW;

	params->sphere_list[1].rayon = 12;
	params->sphere_list[1].center.vect_x = 0;
	params->sphere_list[1].center.vect_y = 0;
	params->sphere_list[1].center.vect_z = -4;
	params->sphere_list[1].color = GREEN;

	params->sphere_list[2].rayon = radius + 40;
	params->sphere_list[2].center.vect_x = 5;
	params->sphere_list[2].center.vect_y = 0;
	params->sphere_list[2].center.vect_z = -25;
	params->sphere_list[2].color = BLUE;

	params->sphere_list[3].rayon = radius;
	params->sphere_list[3].center.vect_x = x - 210;
	params->sphere_list[3].center.vect_y = y;
	params->sphere_list[3].center.vect_z = -120;
	params->sphere_list[3].color = RED;
}

void	init_mlx(t_params *params)
{
	params->mlx = mlx_init();
	/*Penser à proteger le mlx_init*/
	params->win = mlx_new_window(params->mlx, WIDTH, HEIGHT, "RTV1");
	params->ptr_img = mlx_new_image(params->mlx, WIDTH, HEIGHT);
	params->img_data = (int *)mlx_get_data_addr(params->ptr_img, &(params->bpp),  &(params->size_line), &(params->endian));
}

t_vect	get_first_pixel(t_params *params)
{
	t_vect		screen_center;
	t_camera	camera;

	/* Screen_center = cam_pos + (vect_dir * veiw_dist)*/
	camera = params->eye;
	screen_center.vect_x = camera.cam_pos.vect_x + (camera.vect_dir.vect_x * camera.view_dist);
	screen_center.vect_y = camera.cam_pos.vect_y + (camera.vect_dir.vect_y * camera.view_dist);
	screen_center.vect_z = camera.cam_pos.vect_z + (camera.vect_dir.vect_z * camera.view_dist);

	/* camPos + ((vecDir*viewplaneDist)+(upVec*(viewplaneHeight/2.0f))) */

	screen_center.vect_x += params->eye.up_vect.vect_x * (params->eye.view_height / 2.0);
	screen_center.vect_y += params->eye.up_vect.vect_y * (params->eye.view_height / 2.0);
	screen_center.vect_z += params->eye.up_vect.vect_z * (params->eye.view_height / 2.0);

	/* camPos + ((vecDir*viewplaneDist)+(upVec*(viewplaneHeight/2.0f))) - (rightVec*(viewplaneWidth/2.0f))*/

	screen_center.vect_x -= params->eye.right_vect.vect_x * params->eye.view_width / 2.0;
	screen_center.vect_x -= params->eye.right_vect.vect_y * params->eye.view_width / 2.0;
	screen_center.vect_x -= params->eye.right_vect.vect_z * params->eye.view_width / 2.0;

	// viewPlaneUpLeft = camPos + ((vecDir*viewplaneDist)+(upVec*(viewplaneHeight/2.0f))) - (rightVec*(viewplaneWidth/2.0f))
	return (screen_center);
}

void	create_plane(t_params *params)
{
	if ((params->plane = (t_plane *)malloc(sizeof(t_plane))) == NULL)
		exit(ft_free(params));
	/*Init position*/
	params->plane->position.vect_x = 10;
	params->plane->position.vect_y = 4;
	params->plane->position.vect_z = 56;

	/*Init Normale*/
	params->plane->normale.vect_x = 0;
	params->plane->normale.vect_y = 1;
	params->plane->normale.vect_z = 0;
}

void	init_scene(t_params *params)
{
	params->eye.cam_pos.vect_x = 0;
	params->eye.cam_pos.vect_y = 0;
	params->eye.cam_pos.vect_z = 0;
	params->eye.view_width = 0.5;
	params->eye.view_height = 0.35;
	params->eye.view_dist = 1.0;
	params->eye.vect_dir.vect_x = 0;
	params->eye.vect_dir.vect_y = 0;
	params->eye.vect_dir.vect_z = 1;
	params->eye.view_left_up = get_first_pixel(params);
	params->rays_to_free = 0;
	params->x_indent = params->eye.view_width / params->x_resolution;
	params->y_indent = params->eye.view_height / params->y_resolution;
	params->eye.up_vect.vect_x = 0;
	params->eye.up_vect.vect_y = -1;
	params->eye.up_vect.vect_z = 0;

	params->eye.right_vect.vect_x = 1;
	params->eye.right_vect.vect_y = 0;
	params->eye.right_vect.vect_z = 0;
	init_mlx(params);
	//set_view(params);
	//create_sphere(params, 70, WIDTH / 2, HEIGHT / 2);
	create_sphere(params, 32, WIDTH / 2, HEIGHT / 4);
	create_plane(params);
	//create_sphere(params, 40, WIDTH / 4, HEIGHT / 2);
}
