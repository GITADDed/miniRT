#include "minirt.h"

int			square_intersection(t_scene *scene, t_square *square, t_ray *ray)
{
	double		t;
	t_vector	point;
	t_vector	d_1;
	t_vector	border;

	point = vec_sub(ray->orig, square->orig);
	t = check_scalar(ray->dir, square->vec_n, point);
	if (t < 0)
		return (0);
	d_1 = vec_sum(ray->orig, vec_con_mult(t, ray->dir));
	border = vec_sub(d_1, square->orig);
	if (fabs(border.x) > square->side_size / 2
	|| fabs(border.y) > square->side_size / 2
	|| fabs(border.z) > square->side_size / 2)
		return (0);
	scene->closest.t = t;
	scene->closest.point = vec_sum(ray->orig, vec_con_mult(t, ray->dir));
	scene->closest.figure = square;
	scene->closest.type = T_SQUARE;
	if (scalar(ray->dir, square->vec_n) > 0)
		square->vec_n = vec_con_mult(-1, square->vec_n);
	return (1);
}
