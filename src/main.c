#include "miniRT.h"
#include "sphere.h"
#include "vector.h"

int             close(int keycode, t_vars *vars)
{
    if (keycode == 65307)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(1);
    }
    return (0);
}

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int main()
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
    t_vars    vars;
    double r = 300;
    int x = 960;
    int y = 540;
    int z = 0;

    mlx = mlx_init();
    vars.mlx = mlx;
    mlx_win = mlx_new_window(mlx, 1920, 1080, "miniRT");
    vars.win = mlx_win;
    mlx_hook(vars.win, 2, 1L<<0, close, &vars);
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    vars.img = &img;
    
    draw_sphere(sphere_constr(r, vec3d_constructor(x, y, z)), &vars);
    mlx_loop(mlx);
}
