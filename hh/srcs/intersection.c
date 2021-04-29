#include "minirt.h"

int			test_intersection(t_scene *scene, t_ray *ray)
{
	t_list		*obj;
	t_hit		tmp;
	t_obj_type	*type;
	int			col_det;
	int			flag;

	ft_memset(&tmp, '\0', sizeof(t_hit));
	tmp.t = INFINITY;
	obj = scene->objs;
	col_det = 0;
	flag = 0;
	while (obj)
	{
		type = obj->content;
		if (*type == T_SPHERE)
			col_det = sphere_intersection(scene, obj->content, ray);
		else if (*type == T_PLANE)
			col_det = plane_intersection(scene, obj->content, ray);
		else if (*type == T_TRIANGLE)
			col_det = triangle_intersection(scene, obj->content, ray);
		else if (*type == T_CYLINDER)
			col_det = cylinder_intersection(scene, obj->content, ray);
		else if (*type == T_SQUARE)
			col_det = square_intersection(scene, obj->content, ray);
		if (col_det && scene->closest.t < tmp.t)
		{
			tmp = scene->closest;
			flag = 1;
		}
		obj = obj->next;
	}
	if (flag)
	{
		scene->closest = tmp;
		col_det = 1;
	}
	return (col_det);
}

void		init_normal(t_scene *scene)
{
	t_obj_type	*type;
	void		*obj;

	obj = scene->closest.figure;
	type = scene->closest.figure;
	if (*type == T_SPHERE)
		scene->closest.norm = ((t_sphere *)obj)->vec_n;
	else if (*type == T_TRIANGLE)
		scene->closest.norm = vec_normalisation(((t_triangle *)obj)->vec_n);
	else if (*type == T_SQUARE)
		scene->closest.norm = ((t_square *)obj)->vec_n;
	else if (*type == T_PLANE)
		scene->closest.norm = ((t_plane *)obj)->vec_n;
	else if (*type == T_CYLINDER)
		scene->closest.norm = ((t_cylinder *)obj)->surf_norm;
}

int			get_color(t_hit *hit)
{
	if (hit->type == T_SPHERE)
		return (((t_sphere *)hit->figure)->color);
	if (hit->type == T_PLANE)
		return (((t_plane *)hit->figure)->color);
	if (hit->type == T_TRIANGLE)
		return (((t_triangle *)hit->figure)->color);
	if (hit->type == T_CYLINDER)
		return (((t_cylinder *)hit->figure)->color);
	if (hit->type == T_SQUARE)
		return (((t_square *)hit->figure)->color);
	return (0);
}
