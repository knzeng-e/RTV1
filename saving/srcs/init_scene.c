/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 11:08:52 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/02/10 09:47:39 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	create_sphere(t_params *params)
{
	int	cpt;

	cpt = -1;
	while (++cpt < NB_SPHERES)
		params->sphere_list[cpt].is_selected = 0;
	params->sphere_list[0].rayon = 0.5;
	params->sphere_list[0].center.vect_x = 0.1;
	params->sphere_list[0].center.vect_y = 0.1;
	params->sphere_list[0].center.vect_z = -10.2;
	//params->sphere_list[0].color = YELLOW;
	params->sphere_list[0].color = RGB(255, 255, 0);

	params->sphere_list[1].rayon = 1;
	params->sphere_list[1].center.vect_x = -0.8;
	params->sphere_list[1].center.vect_y = 0;
	params->sphere_list[1].center.vect_z = -10;
	params->sphere_list[1].color = GREEN;
	params->sphere_list[1].color = BLUE;
	//params->sphere_list[1].color = RGB(0, 255, 0);

	params->sphere_list[2].rayon = 0.8;
	params->sphere_list[2].center.vect_x = -0.5;
	params->sphere_list[2].center.vect_y = 1.7;
	params->sphere_list[2].center.vect_z = -8;
	params->sphere_list[2].color = BLUE;
	//params->sphere_list[2].color = RGB(0, 0, 255);

	params->sphere_list[3].rayon = 0.9;
	params->sphere_list[3].center.vect_x = -1.7;
	params->sphere_list[3].center.vect_y = 1.3;
	params->sphere_list[3].center.vect_z = -8;
	params->sphere_list[3].color = RED;
	//params->sphere_list[3].color = get_color(255, 0, 0);
}

void	init_mlx(t_params *params)
{
	params->mlx = mlx_init();
	/*Penser à proteger le mlx_init*/
	params->win = mlx_new_window(params->mlx, WIDTH, HEIGHT, "RTV1");
	params->ptr_img = mlx_new_image(params->mlx, WIDTH, HEIGHT);
	params->img_data = mlx_get_data_addr(params->ptr_img, \
		&(params->bpp),  &(params->size_line), &(params->endian));
	params->fov = FOV;
}

void	create_plane(t_params *params)
{
	if ((params->plane = (t_plane *)malloc(sizeof(t_plane))) == NULL)
		exit(ft_free(params));
	/*Init position*/
	params->plane->position = set_vector(0, -4, 0);

	/*Init Normale*/
	params->plane->normale = set_vector(0, 1, 0);
	params->plane->color = 0x00FFFFFF;
	params->plane_list[0] = *params->plane;
}

void	put_light(t_params *params, double x_pos, double y_pos, double z_pos)
{
	t_light	*light;

	if ((light = (t_light *)malloc(sizeof(t_light))) == NULL)
		exit(0);
	light->position = set_vector(x_pos, y_pos, z_pos);
	light->intensity = 1;
	light->diffuse_light = DIFFUSE_LIGHT;
	light->specular_light = SPECULAR;
	light->shininess = SHININESS;
	params->light[0] = *light;
}

void	init_objects_list(t_params *params)
{
	t_list		head;
	t_plane		check_plane;
	t_sphere	check_sphere;
	int			cpt;

	cpt = -1;
	params->objects = (t_object *)malloc(sizeof(t_object) * params->nb_objects);
	if (params->objects == NULL)
	{
		ft_free(params);
		exit(MALLOC_ERROR);
	}
	params->obj_list.content_size = 0;
	params->obj_list.next = NULL;
	head = params->obj_list;
	while (++cpt < NB_SPHERES)
	{
		while (head.next != NULL)
			head = *head.next;
	//	head = *head.next;
		head.content = &params->sphere_list[cpt];
		params->objects[cpt].item = SPHERE;
		head.next = NULL;
		printf("\nCPT ==> %d", cpt);
		//	params->obj_list = head;
	}
	head = params->obj_list;

	while (head.next)
	{
		check_sphere = *(t_sphere *)head.content;
		printf("\nSPEHRE RADIUS ==> %f", check_sphere.rayon);
		head = *head.next;
	}
	head = params->obj_list;

	cpt = -1;
	while (++cpt < NB_PLANES)
	{
		head = params->obj_list;
		while (head.next != NULL)
			head = *head.next;
		head.content = &params->plane_list[cpt];
		params->objects[cpt].item = PLANE;
		head.next = &params->obj_list;
		check_plane = *(t_plane *)head.content;
		printf("\nPLANE COLOR ==> %d", check_plane.color);
	}
}

void	init_scene(t_params *params)
{
	init_mlx(params);
	params->nb_objects = get_nb_objects(params);
	create_sphere(params);
	create_plane(params);
	put_light(params, 1, 3, -8);
	init_objects_list(params);
}
