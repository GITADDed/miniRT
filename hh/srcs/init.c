#include "minirt.h"

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char		*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_vector		camera_to_world(t_vector ray, t_vector cam_dir)
{
	t_vector	new_x;
	t_vector	new_y;
	t_vector	new_z;

	new_z = cam_dir;
	new_x = cross((t_vector){0, -1, 0}, new_z);
	new_y = cross(new_z, new_x);
	return ((t_vector){ray.x * new_x.x + ray.y * new_x.y + ray.z * new_x.z,
					ray.x * new_y.x + ray.y * new_y.y + ray.z * new_y.z,
					ray.x * new_z.x + ray.y * new_z.y + ray.z * new_z.z});
}

t_vector		ray_set(int i, int j, t_scene *scene)
{
	double		point_x;
	double		point_y;
	t_vector	res;

	point_x = (i + 0.5) / scene->view.rw;
	point_y = (j + 0.5) / scene->view.rh;
	res.x = -(2 * point_x - 1) * tan(scene->cameras->fov / 2)
			* ((float)scene->view.rw / (float)scene->view.rh);
	res.y = (2 * point_y - 1) * tan(scene->cameras->fov / 2);
	res.z = 1;
	return (res);
}
