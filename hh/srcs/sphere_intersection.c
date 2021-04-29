#include "minirt.h"

t_roots		solve_quadratic(t_quadratic *q)
{
	double	decr;
	t_roots	roots;

	decr = q->b * q->b - 4 * q->a * q->c;
	if (decr < 0)
	{
		roots.t_1 = -1;
		roots.t_2 = -1;
		return (roots);
	}
	roots.t_1 = (-q->b - sqrt(decr)) / (2 * q->a);
	roots.t_2 = (-q->b + sqrt(decr)) / (2 * q->a);
	return (roots);
}

int			sphere_intersection(t_scene *scene, t_sphere *sphere, t_ray *ray)
{
	t_roots		roots;
	t_quadratic	q;
	t_vector	oc;
	double		t;

	oc = vec_sub(ray->orig, sphere->orig);
	q.a = scalar(ray->dir, ray->dir);
	q.b = 2 * scalar(oc, ray->dir);
	q.c = scalar(oc, oc) - pow(sphere->diameter / 2, 2);
	roots = solve_quadratic(&q);
	t = (roots.t_1 > roots.t_2 ? roots.t_2 : roots.t_1);
	if (t < EPSILON)
		return (0);
	scene->closest.t = t;
	scene->closest.point = vec_sum(ray->orig, vec_con_mult(t, ray->dir));
	sphere->vec_n = vec_normalisation(vec_sub(scene->closest.point,
										sphere->orig));
	if (scalar(sphere->vec_n, ray->dir) > 0)
		sphere->vec_n = vec_con_mult(-1, sphere->vec_n);
	scene->closest.figure = sphere;
	scene->closest.type = T_SPHERE;
	return (1);
}
