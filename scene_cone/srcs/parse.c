/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:29:26 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/05 12:07:09 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rt_v1.h"
# include <sys/types.h>
# include <fcntl.h>

int		check_sphere(char *line)
{
	if (ft_strcmp(line, "sphere") == 0)
		return (SPHERE);
	return (0);
}

int		check_plane(char *line)
{
	if (ft_strcmp(line, "plane") == 0)
		return (PLANE);
	return (0);
}

int		check_cone(char *line)
{
	if (ft_strcmp(line, "cone") == 0)
		return (CONE);
	return (0);
}

int		check_cylinder(char *line)
{
	if (ft_strcmp(line, "cylinder") == 0)
		return (CYLINDER);
	return (0);
}

int		check_object(char *line)
{
	int	object_id;

	if ((object_id = check_sphere(line)) || (object_id = (check_plane(line))) || (object_id = (check_cone(line))) \
			|| (object_id = (check_cylinder(line))))
		return (object_id);
	return (0);
}

void	show_object(int object_id)
{
	char	*object;

	object = (object_id == SPHERE) ? "Sphere" : (((object_id == PLANE) ? "Plane" : (object_id == CONE ? "Cone": ((object_id == CYLINDER) ? "Cylinder" : "Uknown Object"))));
	ft_putstr("\nObject ==> ");
	ft_putstr(object);
	ft_putchar('\n');
}

void	ft_parse_error(int num_line, char *infos)
{
	ft_putstr(PARSE_ERROR_MESSAGE);
	ft_putnbr(num_line);
	ft_putstr(" : ");
	ft_putstr(infos);
	ft_putchar('\n');
	exit (-2);
}

void	show_line_content(char **line_content)
{
		while (*line_content)
		{
			ft_putstr("\n- ");
			ft_putstr(*line_content);
			(line_content)++;
			ft_putchar('\n');
		}
}

int		check_object_params(int object_id, t_params *params)
{
	if (object_id == SPHERE)
	{
		printf("\nParsing Sphere:\n\tBegin with index => [%d]", params->current_sphere_index);
		fflush(stdout);
		params->current_sphere_index++;
		if (check_sphere_params(params)) /* 4 : check_sphere_params*/
			return (CORRECT_OBJECT_DESCRIPTION);
		return (ERROR_OBJECT_DESCRIPTION);
	}
	if (object_id == PLANE)
	{
		return (CORRECT_OBJECT_DESCRIPTION);
	}
	if (object_id == CYLINDER)
	{
		return (CORRECT_OBJECT_DESCRIPTION);
	}
	if (object_id == CONE)
	{
		return (CORRECT_OBJECT_DESCRIPTION);
	}
	if (object_id == LIGHT)
	{
		return (CORRECT_OBJECT_DESCRIPTION);
	}
	return (ERROR_OBJECT_DESCRIPTION);
}

int		parse_object(int object_id, char **line, t_params *params, int *num_line)
{
	while (get_next_line(params->fd, line) && ft_strcmp(*line, "}"))
	{
		++(*num_line);
		params->line_content = ft_strsplit(*line, ' ');
		if (check_object_params(object_id, params) == ERROR_OBJECT_DESCRIPTION) /* 3 : check_object_params*/
			ft_parse_error(*num_line, "INCORRECT CONTENT DESCRIPTION");
	}
	if (check_object(*line))
		ft_parse_error(--(*num_line), "SHOULD HAVE A '}' HERE");
	return (PARSE_OK);
}

int		read_block(t_params *params, char *line, int *num_line)
{
	(*num_line)++;
	if (!get_next_line(params->fd, &line) || ft_strcmp(line, "{"))
		ft_parse_error(*num_line, "SHOULD HAVE A '{' AFTER OBJECT TYPE");
	if (parse_object(params->object_id, &line, params, num_line) == 0) /* 2: parse_object --> check the object_id's parameters */
		ft_parse_error(*num_line, "ERROR IN OBJECT DESCRIPTION");
	if (ft_strcmp(line, "}") != 0)
	{	/* The block ended without '}' character */
		ft_parse_error(++(*num_line), "MISSING '}'"); 
	}
	++(*num_line);
	return (PARSE_OK);
}

void	parse_file(t_params *params)
{
	char	*line;
	int		num_line;
	int		has_content;

	params->fd = open(params->file, O_RDONLY);
	if (params->fd == ERROR_OPEN)
		exit (ERROR_OPEN);
	num_line = 0;
	while (get_next_line(params->fd, &line))
	{
		has_content = 0;
		num_line++;
		params->object_id = check_object(line);
		if (params->object_id == INVALID_OBJECT) /*Object not found*/
			ft_parse_error(num_line, "SHOULD HAVE A VALID OBJECT TYPE");
		if (read_block(params, line, &num_line) == INVALID_DESCRIPTION) /* 1 : read_block : lecture dun block entre accolades */
			ft_parse_error(num_line, "ERROR IN OBJECT DESCRIPTION");
		num_line++;
		if (get_next_line(params->fd, &line))
		{
			has_content = 1;
			if (ft_strlen(line))
				ft_parse_error(num_line, "SHOULD HAVE AN EMPTY LINE HERE");
		}
	}
	if (has_content)
		ft_parse_error(num_line, "NEW LINE AT THE END");
	close(params->fd);
}
