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
	params->sphere.is_selected = 0;
	params->sphere.rayon = radius;
	set_vector(&params->sphere.center, x, y, 50);
	set_color(&params->sphere.color, 255, 0, 0);

	params->sphere2.is_selected = 0;
	//params->sphere2.rayon = radius + 2442;
	params->sphere2.rayon = radius - 42;
	set_vector(&params->sphere2.center, x, y + -42, 50);
	set_color(&params->sphere2.color, 255, 0, 0);

	params->sphere3.is_selected = 0;
	params->sphere3.rayon = radius + 21;
	set_vector(&params->sphere3.center, x, y + 47, 50);
	set_color(&params->sphere3.color, 255, 0, 0);
}

void	init_mlx(t_params *params)
{
	params->mlx = mlx_init();
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
	if ((params->v_plane = (t_plane *)malloc(sizeof(t_plane))) == NULL)
		exit(ft_free(params));
	/*Init position*/
	params->plane->position.vect_x = WIDTH;
	params->plane->position.vect_y = HEIGHT / 2;
	params->plane->position.vect_z = 1200;

	/*Init Normale*/
	params->plane->normale.vect_x = 0;
	params->plane->normale.vect_y = -10;
	params->plane->normale.vect_z = 1;

/* Vertical Plane */
	params->v_plane->position.vect_x = WIDTH;
	params->v_plane->position.vect_y = HEIGHT / 2;
	params->v_plane->position.vect_z = 1200;

	/*Init Normale*/
	params->v_plane->normale.vect_x = 1;
	params->v_plane->normale.vect_y = -1;
	params->v_plane->normale.vect_z = 1200;
}

void	put_light(t_params *params, int y_pos, int x_pos)
{
	t_light	*light;

	if ((light = (t_light *)malloc(sizeof(t_light))) == NULL)
		exit(0);
	light->position.vect_x = x_pos;
	light->position.vect_y = y_pos;
	light->position.vect_z = 50;
	params->light[0] = *light;
}

void	init_scene(t_params *params)
{
	params->t = MAX_DISTANCE;
	params->eye.view_left_up = get_first_pixel(params);
	params->rays_to_free = 0;
	params->x_indent = params->eye.view_width / params->x_resolution;
	params->y_indent = params->eye.view_height / params->y_resolution;
	set_camera(&params->eye);
	init_mlx(params);
	//set_view(params);
	create_sphere(params, 70, WIDTH / 2, HEIGHT / 2);
	create_plane(params);
	put_light(params, HEIGHT / 100, WIDTH / 2);
	init_transform_matrices(params->transforms);
}
