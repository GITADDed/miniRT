#include "minirt.h"

t_color		shade(t_scene *scene, t_color color)
{
	double		h;
	t_light		*light;
	t_ray		ray;
	t_hit		hit;

	light = scene->lights;
	hit = scene->closest;
	ray.orig = vec_sum(hit.point, vec_con_mult(0.001, hit.norm));
	while (light)
	{
		ray.dir = vec_normalisation(vec_sub(light->orig, hit.point));
		if (!test_intersection(scene, &ray))
		{
			h = fmax(0, scalar(hit.norm, ray.dir));
			color = vec_sum(color, vec_con_mult(h, int_to_color(light->color)));
		}
		scene->closest = hit;
		light = light->next;
	}
	return (vec_con_mult(1.0 / 255, color));
}

t_color		int_to_color(int c)
{
	t_color			color;
	unsigned char	*ptr;

	ptr = (unsigned char *)&c;
	color.x = ptr[2];
	color.y = ptr[1];
	color.z = ptr[0];
	return (color);
}

int			color_to_int(t_color c)
{
	double	k;

	k = fmax(c.x, fmax(c.y, c.z));
	if (k > 255)
		c = vec_con_mult(255 / k, c);
	return (create_rgb((int)c.x, (int)c.y, (int)c.z));
}
