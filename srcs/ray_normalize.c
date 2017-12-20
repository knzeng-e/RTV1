#include "rt_v1.h"

double			get_length(t_vect *vect)
{
	double	module;

	module = 0;
	module += vect->vect_x * vect->vect_x;
	module += vect->vect_y * vect->vect_y;
	module += vect->vect_z * vect->vect_z;
	return (sqrt(module));
}

void			ray_normalize(t_vect *vect)
{
	double		module;

	module = get_length(vect);
	/* module = sqrt(x2 + y2 + z2) */
	vect->vect_x /= module;
	vect->vect_y /= module;
	vect->vect_z /= module;
}
