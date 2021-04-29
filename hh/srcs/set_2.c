#include "minirt.h"

void		little_checker(char **line)
{
	int		flag;
	int		flag2;

	flag = 0;
	flag2 = 0;
	while (**line != ',' && **line != ' ' && **line != '\0')
	{
		if (!ft_isdigit(**line) && **line != '.' &&
		**line != '+' && **line != '-')
			map_error("invalid value!");
		else if ((**line == '+' || **line == '-') && flag)
			map_error("invalid value!");
		else if (**line == '.' && flag2)
			map_error("invalid value!");
		if ((**line == '+' || **line == '-'))
			flag = 1;
		if (**line == '.')
			flag2 = 1;
		(*line)++;
	}
}

char		*ft_mini_check_double(char **line)
{
	char	*str;

	while (**line == ' ')
		(*line)++;
	str = *line;
	if (**line == ',')
		map_error("invalid value!");
	little_checker(line);
	if (**line == ',' || **line == ' ')
		(*line)++;
	if (!*line)
		map_error("!not enough arguments!");
	return (str);
}

void		add_funct(t_scene *scene, t_light *light)
{
	t_light		*cur;

	cur = scene->lights;
	if (!cur)
		scene->lights = light;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = light;
	}
}

void		set_light_source(char **line, t_scene *scene)
{
	t_light		*light;

	light = malloc(sizeof(t_light));
	if (!light)
		map_error("malloc error!!");
	else
	{
		light->next = NULL;
		(*line)++;
		while (**line == ' ')
			(*line)++;
		if (**line != '-' && !ft_isdigit(**line))
			map_error("wrong light source name!");
		light->orig.x = ft_atod(ft_mini_check_double(line), 0, 0);
		light->orig.y = ft_atod(ft_mini_check_double(line), 0, 0);
		light->orig.z = ft_atod(ft_mini_check_double(line), 0, 0);
		light->intensity = ft_atod(ft_mini_check_double(line), 0, 0);
		light->color = make_color(
				rt_atoi(check_int_mini(line)),
				rt_atoi(check_int_mini(line)),
				rt_atoi(check_int_mini(line)),
				light->intensity);
		if (**line != '\0')
			map_error("extra stuff after figure parameters");
		add_funct(scene, light);
	}
}

void		set_sphere(char **line, t_scene *scene)
{
	t_sphere		*sphere;
	t_list			*object;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		map_error("malloc error!!!");
	object = ft_lstnew(sphere);
	ft_lstadd_front(&scene->objs, object);
	while (ft_isalpha(**line))
		(*line)++;
	sphere->orig.x = ft_atod(ft_mini_check_double(line), 0, 0);
	sphere->orig.y = ft_atod(ft_mini_check_double(line), 0, 0);
	sphere->orig.z = ft_atod(ft_mini_check_double(line), 0, 0);
	sphere->diameter = ft_atod(ft_mini_check_double(line), 0, 0);
	sphere->color = make_color(
			rt_atoi(check_int_mini(line)),
			rt_atoi(check_int_mini(line)),
			rt_atoi(check_int_mini(line)),
			1);
	if (**line != '\0')
		map_error("extra stuff after figure parameters");
	sphere->type = T_SPHERE;
}
