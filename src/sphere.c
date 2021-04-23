#include "sphere.h"

sphere      *sphere_constr(double R, vec3d *center)
{
    sphere *sph;

    sph = malloc(sizeof(sphere));
    if (sph == NULL)
        return (NULL);
    sph->R = R;
    sph->center = center;

    return (sph);
}

void        draw_sphere(sphere *sph, t_vars *vars)
{
    double l;
    double x1;
    double y1;

    for (double i = 0; i < sph->R; i += 0.1)
    {
        for (double j = 0; j < 360; j += 0.1)
        {
            l = j * PI / 180;
            x1 = i * cos(l);
            y1 = i * sin(l);
            my_mlx_pixel_put(vars->img, sph->center->x + x1, sph->center->y + y1, 0xFF00FF30);
        }
    }
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}