#include "minirt.h"

void			init_tr_norm(t_triangle *triangle)
{
	t_vector	side_a;
	t_vector	side_b;

	side_a = vec_sub(triangle->vertex_1, triangle->vertex_2);
	side_b = vec_sub(triangle->vertex_1, triangle->vertex_3);
	triangle->vec_n = cross(side_a, side_b);
}

double			area_of_a_triangle(t_vector ver1, t_vector ver2, t_vector ver3)
{
	t_vector	side_a;
	t_vector	side_b;

	side_a = vec_sub(ver1, ver2);
	side_b = vec_sub(ver2, ver3);
	return (length(cross(side_a, side_b)) / 2.0);
}

double			check_scalar(t_vector v_1, t_vector v_norm, t_vector v_3)
{
	double		u;
	double		v;
	double		t;

	u = scalar(v_1, v_norm);
	v = scalar(v_3, v_norm);
	if (u == 0 || ((u < 0 && v < 0) || (u > 0 && v > 0)))
		return (-1);
	t = -(v / u);
	if (t < EPSILON)
		return (-1);
	return (t);
}

int				triangle_intersection(t_scene *scene, t_triangle *tr, t_ray *ray)
{
	double		s_1;
	double		s_2;
	double		s_3;
	double		t;
	t_vector	d_1;

	tr->point = vec_sub(ray->orig, tr->vertex_3);
	t = check_scalar(ray->dir, tr->vec_n, tr->point);
	if (t < 0)
		return (0);
	d_1 = vec_sum(ray->orig, vec_con_mult(t, ray->dir));
	s_1 = area_of_a_triangle(d_1, tr->vertex_2, tr->vertex_3);
	s_2 = area_of_a_triangle(d_1, tr->vertex_3, tr->vertex_1);
	s_3 = area_of_a_triangle(d_1, tr->vertex_1, tr->vertex_2);
	if (tr->s - s_1 - s_2 - s_3 < EPSILON && tr->s - s_1 - s_2 - s_3 > -EPSILON)
	{
		scene->closest.t = t;
		scene->closest.point = vec_sum(ray->orig, vec_con_mult(t, ray->dir));
		scene->closest.figure = tr;
		if (scalar(ray->dir, tr->vec_n) > 0)
			tr->vec_n = vec_con_mult(-1, tr->vec_n);
		scene->closest.type = T_TRIANGLE;
		return (1);
	}
	return (0);
}
