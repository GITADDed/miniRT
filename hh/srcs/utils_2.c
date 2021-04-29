#include "minirt.h"

double		length(t_vector v1)
{
	double	res;

	res = sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
	return (res);
}

void		scaling(t_all *all)
{
	int			size_x;
	int			size_y;

	mlx_get_screen_size(all->mlx, &size_x, &size_y);
	if (all->scene.view.rw > size_x)
		all->scene.view.rw = size_x;
	if (all->scene.view.rh > size_y)
		all->scene.view.rh = size_y;
}

int			rt_atoi(const char *str)
{
	int			num;
	int			m;

	num = 0;
	m = 0;
	if (*str == '-')
	{
		m = 1;
		str++;
	}
	else if (*str == '+' || *str == ',')
		str++;
	else if (!ft_isdigit(*str))
		map_error("wrong separator\n");
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	if (m)
		num = -num;
	return (num);
}
