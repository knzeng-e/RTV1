#include "rt_v1.h"

void	map_color(t_color *col) {
	col->red = (col->red > 255) ? 255 : (col->red < 0) ? 0 : col->red;
	col->green = (col->green > 255) ? 255 : (col->green < 0) ? 0 : col->green;
	col->blue = (col->blue > 255) ? 255 : (col->blue < 0) ? 0 : col->blue;
}
