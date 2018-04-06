#include "rt_v1.h"

int	ft_isnumber(char *number)
{
	int	i;

	i = -1;
	while (number[++i])
	{
		if (!ft_isdigit(number[i]))
			return (FALSE);
	}
	return (TRUE);
}
