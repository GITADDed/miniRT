#ifndef VECTOR_H
# define VECTOR_H

#include <stdlib.h>

// struct for 3d vector
typedef struct  s_vec
{
    int         x;
    int         y;
    int         z;
}               vec3d;

vec3d       *vec3d_constructor(int x, int y, int z);
int         dot(vec3d *vec1, vec3d *vec2);

#endif