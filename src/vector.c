#include "vector.h"

vec3d       *vec3d_constructor(int x, int y, int z)
{
    vec3d *vec;

    vec = malloc(sizeof(vec));
    if (vec == NULL)
        return (NULL);
    vec->x = x;
    vec->y = y;
    vec->z = z;

    return (vec);
}

int         dot(vec3d *vec1, vec3d *vec2)
{
    int result;

    result = vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z;
    return (result);
}