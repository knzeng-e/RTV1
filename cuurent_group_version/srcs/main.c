/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 19:51:41 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/16 07:32:13 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void		mlx_draw(t_params *infos)
{
	int		key_press_mask;
	int		key_press;

	key_press_mask = 1L << 0;
	key_press = 2;
	init_scene(infos, infos->forme);
	mlx_mouse_hook(infos->win, mouse_hook, infos);
	mlx_expose_hook(infos->win, expose_hook, infos);
	mlx_hook(infos->win, key_press, key_press_mask, key_hook, infos);
	mlx_loop(infos->mlx);
}

t_params	*init_params(void)
{
	t_params	*params;

	params = (t_params *)malloc(sizeof(t_params));
	if (params == NULL)
		exit(MALLOC_PARAMS_ERROR);
	params->x_resolution = WIDTH;
	params->y_resolution = HEIGHT;
	params->mlx = mlx_init();
	return (params);
}

void		quit(t_params *params)
{
	free_objects_list(params);
}

int			is_valid_forme(char *forme)
{
	int		output;

	output = (!ft_strcmp(forme, "cone") || !ft_strcmp(forme, "cylinder") ||
			!ft_strcmp(forme, "plane") || !ft_strcmp(forme, "sphere") ||
			!ft_strcmp(forme, "all"));
	if (output == 0)
	{
		ft_putstr("You provided an invalid argument\n");
		ft_putendl("Usage: ./rtv1 [sphere | cylinder | cone | plane | all]");
		return (INVALID_OBJECT);
	}
	return (output);
}

int			main(int ac, char **av)
{
	t_params	*params;

	params = init_params();
	if (ac == 2)
	{
		if (!is_valid_forme(av[1]))
		{
			free(params);
			return (-1);
		}
		params->forme = av[1];
	}
	else
	{
		if (ac == 1)
			params->forme = "all";
		else
		{
			ft_putendl("Usage: sphere | cylinder | cone | plane | all");
			free(params);
			return (-2);
		}
	}
	mlx_draw(params);
	return (OK);
}
