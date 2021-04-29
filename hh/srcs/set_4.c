#include "minirt.h"

void		set_square(char **line, t_scene *scene)
{
	t_square	*square;
	t_list		*object;

	if (!(square = malloc(sizeof(t_square))))
		map_error("malloc error");
	object = ft_lstnew(square);
	ft_lstadd_front(&scene->objs, object);
	while (ft_isalpha(**line))
		(*line)++;
	square->orig.x = ft_atod(ft_mini_check_double(line), 0, 0);
	square->orig.y = ft_atod(ft_mini_check_double(line), 0, 0);
	square->orig.z = ft_atod(ft_mini_check_double(line), 0, 0);
	square->vec_n.x = ft_atod(ft_mini_check_double(line), 0, 0);
	square->vec_n.y = ft_atod(ft_mini_check_double(line), 0, 0);
	square->vec_n.z = ft_atod(ft_mini_check_double(line), 0, 0);
	check_norm(square->vec_n.x, square->vec_n.y, square->vec_n.z);
	square->side_size = ft_atod(ft_mini_check_double(line), 0, 0);
	square->color = make_color(
			rt_atoi(check_int_mini(line)),
			rt_atoi(check_int_mini(line)),
			rt_atoi(check_int_mini(line)),
			1);
	if (**line != '\0')
		map_error("extra stuff after figure parameters");
	square->type = T_SQUARE;
}
