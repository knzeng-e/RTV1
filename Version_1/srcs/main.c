/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_v1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 19:51:41 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/05 19:37:42 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void		mlx_draw(t_params *infos)
{
	int	key_press_mask;
	int	key_press;

	key_press_mask = 1L << 0;
	key_press = 2;
	init_scene(infos);
	mlx_mouse_hook(infos->win, mouse_hook, infos);
	mlx_expose_hook(infos->win, expose_hook, infos);
	mlx_hook(infos->win, key_press, key_press_mask, key_hook, infos);
	mlx_loop(infos->mlx);
}

t_params	*init_params(void)
{
	t_params	*params;

	if ((!(params = (t_params *)malloc(sizeof(t_params)))) || params == NULL)
		exit(MALLOC_PARAMS_ERROR);
	params->x_resolution = WIDTH;
	params->y_resolution = HEIGHT;
	if (!(params->mlx = mlx_init()))
		return (NULL);
	return (params);
}

void		quit(t_params *params)
{
	free_lights(params);
	free_objects_list(params);
}

int			main(int ac, char **av)
{
	t_params	*params;

	params = init_params();
	if (ac == 2)
		params->file = av[1];
	else
		params->file = "test";
	mlx_draw(params);
	return (OK);
}
