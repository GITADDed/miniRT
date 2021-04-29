#include "minirt.h"

void		set_cylinder(char **line, t_scene *scene)
{
	t_cylinder	*cylinder;
	t_list		*object;

	if (!(cylinder = malloc(sizeof(t_cylinder))))
		map_error("malloc error");
	object = ft_lstnew(cylinder);
	ft_lstadd_front(&scene->objs, object);
	while (ft_isalpha(**line))
		(*line)++;
	cylinder->p_1.x = ft_atod(ft_mini_check_double(line), 0, 0);
	cylinder->p_1.y = ft_atod(ft_mini_check_double(line), 0, 0);
	cylinder->p_1.z = ft_atod(ft_mini_check_double(line), 0, 0);
	cylinder->vec_n.x = ft_atod(ft_mini_check_double(line), 0, 0);
	cylinder->vec_n.y = ft_atod(ft_mini_check_double(line), 0, 0);
	cylinder->vec_n.z = ft_atod(ft_mini_check_double(line), 0, 0);
	check_norm(cylinder->vec_n.x, cylinder->vec_n.y, cylinder->vec_n.z);
	cylinder->diameter = ft_atod(ft_mini_check_double(line), 0, 0);
	cylinder->height = ft_atod(ft_mini_check_double(line), 0, 0);
	cylinder->color = make_color(
			rt_atoi(check_int_mini(line)),
			rt_atoi(check_int_mini(line)),
			rt_atoi(check_int_mini(line)),
			1);
	if (**line != '\0')
		map_error("extra stuff after figure parameters");
	cylinder->type = T_CYLINDER;
	cylinder->vec_n = vec_normalisation(cylinder->vec_n);
}
