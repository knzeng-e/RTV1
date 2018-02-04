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

void	create_sphere(t_params *params)
{
	int	cpt;

	cpt = -1;
	while (++cpt < NB_SPHERES)
		params->sphere_list[cpt].is_selected = 0;
	params->sphere_list[0].rayon = 1;
	params->sphere_list[0].center.vect_x = 0;
	params->sphere_list[0].center.vect_y = 0;
	params->sphere_list[0].center.vect_z = -10;
	params->sphere_list[0].color = YELLOW;

	params->sphere_list[1].rayon = 1;
	params->sphere_list[1].center.vect_x =-0.8;
	params->sphere_list[1].center.vect_y = 0;
	params->sphere_list[1].center.vect_z = -10;
	params->sphere_list[1].color = GREEN;

	params->sphere_list[2].rayon = 0.8;
	params->sphere_list[2].center.vect_x = -2;
	params->sphere_list[2].center.vect_y = 0;
	params->sphere_list[2].center.vect_z = -10;
	params->sphere_list[2].color = BLUE;

	params->sphere_list[3].rayon = 1;
	params->sphere_list[3].center.vect_x = 0.7;
	params->sphere_list[3].center.vect_y = 1.3;
	params->sphere_list[3].center.vect_z = -10;
	params->sphere_list[3].color = RED;
}

void	init_mlx(t_params *params)
{
	params->mlx = mlx_init();
	/*Penser à proteger le mlx_init*/
	params->win = mlx_new_window(params->mlx, WIDTH, HEIGHT, "RTV1");
	params->ptr_img = mlx_new_image(params->mlx, WIDTH, HEIGHT);
	params->img_data = (int *)mlx_get_data_addr(params->ptr_img, \
		&(params->bpp),  &(params->size_line), &(params->endian));
}

void	create_plane(t_params *params)
{
	if ((params->plane = (t_plane *)malloc(sizeof(t_plane))) == NULL)
		exit(ft_free(params));
	/*Init position*/
	params->plane->position = set_vector(0, -4, 0);
/*	params->plane->position.vect_x = 10;
	params->plane->position.vect_y = 4;
	params->plane->position.vect_z = 56;*/

	/*Init Normale*/
	params->plane->normale = set_vector(0, 1, 0);
	/*params->plane->normale.vect_x = 0;
	params->plane->normale.vect_y = 1;
	params->plane->normale.vect_z = 0;*/
}

void	put_light(t_params *params, int y_pos, int x_pos, int z_pos)
{
	t_light	*light;

	if ((light = (t_light *)malloc(sizeof(t_light))) == NULL)
		exit(0);
	light->position.vect_x = x_pos;
	light->position.vect_y = y_pos;
	light->position.vect_z = z_pos;
	params->light[0] = *light;
}
void	init_scene(t_params *params)
{
	init_mlx(params);
	create_sphere(params);
	create_plane(params);
	put_light(params, 0, 2, -10);
}
