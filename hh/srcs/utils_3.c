#include "minirt.h"

t_vector	vec_con_mult(double a, t_vector vec)
{
	t_vector	res;

	res.x = vec.x * a;
	res.y = vec.y * a;
	res.z = vec.z * a;
	return (res);
}

t_vector	vec_sum(t_vector vec_1, t_vector vec_2)
{
	t_vector	res;

	res.x = vec_1.x + vec_2.x;
	res.y = vec_1.y + vec_2.y;
	res.z = vec_1.z + vec_2.z;
	return (res);
}

t_vector	vec_sub(t_vector vec_1, t_vector vec_2)
{
	t_vector	res;

	res.x = vec_1.x - vec_2.x;
	res.y = vec_1.y - vec_2.y;
	res.z = vec_1.z - vec_2.z;
	return (res);
}

t_vector	vec_normalisation(t_vector v)
{
	double		len;

	len = 1 / length(v);
	v.x *= len;
	v.y *= len;
	v.z *= len;
	return (v);
}

t_vector	vec_mult(t_vector vec_1, t_vector vec_2)
{
	t_vector	res;

	res.x = vec_1.x * vec_2.x;
	res.y = vec_1.y * vec_2.y;
	res.z = vec_1.z * vec_2.z;
	return (res);
}
