#include "minirt.h"

void		set_triangle(char **line, t_scene *scene)
{
	t_triangle	*tr;
	t_list		*object;

	tr = malloc(sizeof(t_triangle));
	object = ft_lstnew(tr);
	ft_lstadd_front(&scene->objs, object);
	while (ft_isalpha(**line))
		(*line)++;
	tr->vertex_1.x = ft_atod(ft_mini_check_double(line), 0, 0);
	tr->vertex_1.y = ft_atod(ft_mini_check_double(line), 0, 0);
	tr->vertex_1.z = ft_atod(ft_mini_check_double(line), 0, 0);
	tr->vertex_2.x = ft_atod(ft_mini_check_double(line), 0, 0);
	tr->vertex_2.y = ft_atod(ft_mini_check_double(line), 0, 0);
	tr->vertex_2.z = ft_atod(ft_mini_check_double(line), 0, 0);
	tr->vertex_3.x = ft_atod(ft_mini_check_double(line), 0, 0);
	tr->vertex_3.y = ft_atod(ft_mini_check_double(line), 0, 0);
	tr->vertex_3.z = ft_atod(ft_mini_check_double(line), 0, 0);
	tr->color = make_color(
			rt_atoi(check_int_mini(line)),
			rt_atoi(check_int_mini(line)),
			rt_atoi(check_int_mini(line)),
			1);
	tr->s = area_of_a_triangle(tr->vertex_1, tr->vertex_2, tr->vertex_3);
	init_tr_norm(tr);
	if (**line != '\0')
		map_error("extra stuff after figure parameters");
	tr->type = T_TRIANGLE;
}
