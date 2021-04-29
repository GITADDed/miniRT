#include "minirt.h"

void		check_norm(double n_x, double n_y, double n_z)
{
	if (n_x > 1 || n_x < -1)
		map_error("invalid 3d normalized orientation vector");
	if (n_y > 1 || n_y < -1)
		map_error("invalid 3d normalized orientation vector");
	if (n_z > 1 || n_z < -1)
		map_error("invalid 3d normalized orientation vector");
}

void		set_plane(char **line, t_scene *scene)
{
	t_plane		*plane;
	t_list		*object;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		map_error("malloc error");
	object = ft_lstnew(plane);
	ft_lstadd_front(&scene->objs, object);
	while (ft_isalpha(**line))
		(*line)++;
	plane->orig.x = ft_atod(ft_mini_check_double(line), 0, 0);
	plane->orig.y = ft_atod(ft_mini_check_double(line), 0, 0);
	plane->orig.z = ft_atod(ft_mini_check_double(line), 0, 0);
	plane->vec_n.x = ft_atod(ft_mini_check_double(line), 0, 0);
	plane->vec_n.y = ft_atod(ft_mini_check_double(line), 0, 0);
	plane->vec_n.z = ft_atod(ft_mini_check_double(line), 0, 0);
	check_norm(plane->vec_n.x, plane->vec_n.y, plane->vec_n.z);
	plane->color = make_color(
			rt_atoi(check_int_mini(line)),
			rt_atoi(check_int_mini(line)),
			rt_atoi(check_int_mini(line)),
			1);
	if (**line != '\0')
		map_error("extra stuff after figure parameters");
	plane->type = T_PLANE;
}
