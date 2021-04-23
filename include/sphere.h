#ifndef SPHERE_H
# define SPHERE_H

#include "vector.h"
#include "miniRT.h"

typedef struct  s_sphere
{
    double      R;
    vec3d       *center;
}               sphere;

sphere      *sphere_constr(double R, vec3d *center);
void        draw_sphere(sphere *sph, t_vars *vars);

#endif