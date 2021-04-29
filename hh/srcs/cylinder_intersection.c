#include "minirt.h"

void		fill_cylinder(t_cylinder *cyl, t_ray *ray, t_scene *scene)
{
	scene->closest.t = cyl->cur;
	scene->closest.point = vec_sum(ray->orig, vec_con_mult(cyl->cur, ray->dir));
	cyl->surf_norm = vec_normalisation(vec_sub(scene->closest.point,
					vec_sub(cyl->p_1, vec_con_mult(cyl->m, cyl->vec_n))));
	if (scalar(ray->dir, cyl->surf_norm) > 0)
		cyl->surf_norm = vec_con_mult(-1, cyl->surf_norm);
	scene->closest.figure = cyl;
	scene->closest.type = T_CYLINDER;
}

int			get_cylinder_values(t_cylinder *cyl, t_ray *ray, t_scene *scene)
{
	cyl->cur = cyl->t_1 < cyl->t_2 ? cyl->t_1 : cyl->t_2;
	cyl->m = cyl->n_dir * cyl->cur + cyl->oc_norm;
	if (cyl->m > 0 && cyl->m < cyl->height && cyl->cur > 0)
	{
		fill_cylinder(cyl, ray, scene);
		return (1);
	}
	cyl->cur = cyl->t_1 > cyl->t_2 ? cyl->t_1 : cyl->t_2;
	cyl->m = cyl->n_dir * cyl->cur + cyl->oc_norm;
	if (cyl->m > 0 && cyl->m < cyl->height && cyl->cur > 0)
	{
		fill_cylinder(cyl, ray, scene);
		return (1);
	}
	return (0);
}

int			cylinder_intersection(t_scene *scene, t_cylinder *cyl, t_ray *ray)
{
	t_roots		roots;
	t_quadratic	q;

	cyl->oc = vec_sub(ray->orig, cyl->p_1);
	cyl->n_dir = scalar(ray->dir, cyl->vec_n);
	cyl->oc_norm = scalar(cyl->oc, cyl->vec_n);
	q.a = scalar(ray->dir, ray->dir) - cyl->n_dir * cyl->n_dir;
	q.b = 2 * (scalar(ray->dir, cyl->oc) - cyl->n_dir * cyl->oc_norm);
	q.c = scalar(cyl->oc, cyl->oc) - cyl->oc_norm * cyl->oc_norm -
			((cyl->diameter / 2) * (cyl->diameter / 2));
	roots = solve_quadratic(&q);
	cyl->t_1 = roots.t_1;
	cyl->t_2 = roots.t_2;
	if (cyl->t_1 < EPSILON && cyl->t_2 < EPSILON)
		return (0);
	return (get_cylinder_values(cyl, ray, scene));
}
