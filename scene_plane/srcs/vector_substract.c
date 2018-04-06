#include "rt_v1.h"

t_vect	vect_sub(t_vect vect1, t_vect vect2)
{
	t_vect	result;

	result.vect_x = vect1.vect_x - vect2.vect_x;
	result.vect_y = vect1.vect_y - vect2.vect_y;
	result.vect_z = vect1.vect_z - vect2.vect_z;

	return (result);
}
