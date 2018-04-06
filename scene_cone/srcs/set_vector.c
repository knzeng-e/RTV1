#include "rt_v1.h"

t_vect	set_vector(double x, double y, double z)
{
	t_vect	result;

	result.vect_x = x;
	result.vect_y = y;
	result.vect_z = z;
	return (result);
}
