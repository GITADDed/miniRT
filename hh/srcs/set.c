#include "minirt.h"

void			set_screen(char **line, t_scene *scene)
{
	(*line)++;
	if (**line != ' ')
		map_error("wrong separator\n");
	while (**line == ' ')
		(*line)++;
	if (!scene->view.rw && !scene->view.rh)
	{
		scene->view.rw = rt_atoi(check_int_mini(line));
		scene->view.rh = rt_atoi(check_int_mini(line));
		if (**line != '\0')
			map_error("extra stuff after figure parameters");
	}
	else
		map_error("you mentioned R twice or more!");
	if (**line != '\0')
		map_error("extra stuff after screen resolution");
}

int				make_color(int r, int g, int b, double intensity)
{
	if (r > 255 || r < 0)
		map_error("invalid plane color value");
	if (g > 255 || g < 0)
		map_error("invalid plane color value");
	if (b > 255 || b < 0)
		map_error("invalid plane color value");
	return (create_rgb(r * intensity, g * intensity, b * intensity));
}

void			set_ambient_light(char **line, t_scene *scene)
{
	double			intensity;

	(*line)++;
	while (**line == ' ')
		(*line)++;
	if (!scene->ambient_color)
	{
		scene->if_ambient = 1;
		intensity = ft_atod(ft_mini_check_double(line), 0, 0);
		if (intensity > 1 || intensity <= 0)
			map_error("wrong light intensity value!");
		scene->ambient_color = make_color(
				rt_atoi(check_int_mini(line)),
				rt_atoi(check_int_mini(line)),
				rt_atoi(check_int_mini(line)),
				intensity);
		if (**line != '\0')
			map_error("extra stuff after figure parameters");

	}
	else
		map_error("you mentioned A twice or more!");
}

void			add_extra_camera(t_scene *scene, t_camera *camera)
{
	t_camera		*cur;

	cur = scene->cameras;
	if (!cur)
	{
		scene->cameras = camera;
		scene->cameras->next = scene->cameras;
	}
	else
	{
		while (cur->next != scene->cameras)
			cur = cur->next;
		cur->next = camera;
		cur->next->next = scene->cameras;
	}
}

void			set_camera(char **line, t_scene *scene)
{
	t_camera		*camera;

	camera = malloc(sizeof(t_camera));
	if (!camera)
		map_error("malloc error!");
	(*line)++;
	while (**line == ' ')
		(*line)++;
	camera->orig.x = ft_atod(ft_mini_check_double(line), 0, 0);
	camera->orig.y = ft_atod(ft_mini_check_double(line), 0, 0);
	camera->orig.z = ft_atod(ft_mini_check_double(line), 0, 0);
	camera->dir.x = ft_atod(ft_mini_check_double(line), 0, 0);
	camera->dir.y = ft_atod(ft_mini_check_double(line), 0, 0);
	camera->dir.z = ft_atod(ft_mini_check_double(line), 0, 0);
	check_norm(camera->dir.x, camera->dir.y, camera->dir.z);
	camera->fov = (rt_atoi((check_int_mini(line))) * M_PI / 180);
	if (camera->fov > M_PI || camera->fov < 0)
		map_error("wrong camera fov");
	if (**line != '\0')
		map_error("extra stuff after figure parameters");
	add_extra_camera(scene, camera);
}
