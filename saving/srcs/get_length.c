#include "rt_v1.h"

double	get_length(t_vect *vect)
{
	double	module;

	module = 0;
	module		 += vect->vect_x * vect->vect_x;
	module += vect->vect_y * vect->vect_y;
	module += vect->vect_z * vect->vect_z;
	return (sqrt(module));
}
