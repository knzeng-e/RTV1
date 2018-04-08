#include "rt_v1.h"

void	save_intersection(t_ray *ray)
{
	double	x_intersect;
	double	y_intersect;
	double	z_intersect;

	/*ray = O + DIR * t*/;
	x_intersect = ray->origin.vect_x + ray->direction.vect_x * ray->t;
	y_intersect = ray->origin.vect_y + ray->direction.vect_y * ray->t;
	z_intersect = ray->origin.vect_z + ray->direction.vect_z * ray->t;
	ray->intersection = set_vector(x_intersect, y_intersect, z_intersect);
    if ((ray->t_min == ray->t_max) || (y_intersect > ray->t_min && y_intersect < ray->t_max))
        ray->is_inter = 1;
    else
        ray->is_inter = 0;
}
