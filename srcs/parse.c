/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:29:26 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/01/24 20:15:12 by knzeng-e         ###   ########.fr       */
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

void	ft_parse_error(int num_line)
{
	ft_putstr(PARSE_ERROR_MESSAGE);
	ft_putnbr(num_line);
	exit (-2);
}

void	read_line(char *file)
{
	char	*line;
	int		cpt;
	int		num_line;
	int		fd;
	int		object_id;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit (-1);
	cpt = 1;
	num_line = 0;
	while (get_next_line(fd, &line))
	{
		num_line++;
		object_id = check_object(line);
		if (object_id == 0) /*Object not found*/
		{
			if (ft_strlen(line) != 0)
			{
				ft_putstr(PARSE_ERROR_MESSAGE);
				ft_putnbr(num_line);
				exit (-2);
			}
			/*We've got a space*/
			num_line++;
			if (!get_next_line(fd, &line) || !ft_strlen(line) || !check_object(line))
			{
				if (!get_next_line(fd, &line))
					num_line--;
				ft_parse_error(num_line);
			}
			object_id = check_object(line);
		}
		else
		{
			get_next_line(fd, &line);
			if (ft_strcmp(line, "{") != 0)
				ft_parse_error(++num_line);
		}

		show_object(object_id);
		while (ft_strcmp(line, "}"))
		{
			if (ft_strlen(line) == 0)
			{
				num_line++;
				get_next_line(fd, &line);
				if (ft_strlen(line) == 0)
					ft_parse_error(num_line);
			}
			if (line[0] == '}')
				ft_parse_error(num_line);
			num_line++;
			get_next_line(fd, &line);
			ft_putstr(line);
			ft_putchar('\n');
		}
		get_next_line(fd, &line);
		ft_putstr(line);
		if (ft_strlen(line))
			ft_parse_error(num_line);
		cpt++;
	}
}

